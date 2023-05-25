#include "User.h"
#include <iostream>

User::User(unsigned int halfbyte, unsigned int branch)
{
	this->halfbyte = halfbyte;
	readSupplement = 0;
	writeSupplement = 0;
	fpOrigin = NULL;
	fpCompress = NULL;
	progress = 0;
	huffmantree = new HuffmanTree(halfbyte, branch);
}

User::~User()
{
	delete(huffmantree);
	if (fpOrigin) fclose(fpOrigin);
	if (fpCompress) fclose(fpCompress);
}

void User::compress()
{
	std::cout << "开始压缩" << std::endl;
	readFile(fpOrigin);
	calculateFrequency();
	std::cout << "编码中……" << std::endl;
	huffmantree->createTree(charfrequency);
	huffmantree->createCode();
	transcodeAndWriteFile();
	std::cout << "压缩完成" << std::endl;
}

void User::decompress()
{
	std::cout << "开始解压" << std::endl;
	readFile(fpCompress);
	getFrequencyAndLength();
	std::cout << "解码中……" << std::endl;
	huffmantree->createTree(charfrequency);
	decodeAndWriteFile();
	std::cout << "解压完成" << std::endl;
}

void User::readFile(FILE*& fp)
{
	fp = fopen(path.c_str(), "rb");
	if (fp == NULL)
	{
		std::cout << "读取文件失败" << std::endl;
		exit(1);
	}
}

unsigned int User::readsymbol(unsigned int& bits)
{
	unsigned int symbol = 0, i = 0;
	static int unuse = 0;
	static unsigned char ch, high, low;
	for (i = 0; i < halfbyte; i++)
	{
		if (!unuse)
		{
			ch = fgetc(fpOrigin);
			if (feof(fpOrigin)) break;
			high = ch >> 4;
			low = ch & 15;
			unuse = 2;
		}
		if (unuse == 2) symbol = (symbol << 4) + high;
		else symbol = (symbol << 4) + low;
		unuse--;
	}
	bits = i;
	return symbol;
}

void User::calculateFrequency()
{
	while (true)
	{
		unsigned int bits = 0;
		unsigned int symbol = readsymbol(bits);
		if (feof(fpOrigin))
		{
			if (bits != 0)
			{
				for (unsigned int i = bits; i < halfbyte; i++)
				{
					symbol = symbol << 4;
				}
				readSupplement = halfbyte - bits;
				if (charfrequency.find(symbol) == charfrequency.end())
				{
					charfrequency[symbol] = 0;
				}
				charfrequency[symbol]++;
			}
			break;
		}
		if (charfrequency.find(symbol) == charfrequency.end())
		{
			charfrequency[symbol] = 0;
		}
		charfrequency[symbol]++;
	}
}

void User::transcodeAndWriteFile()
{
	std::string compresspath = path + ".cop";
	fpCompress = fopen(compresspath.c_str(), "wb");
	unsigned int charfrequencysize = charfrequency.size();

	// 预留写最后补零个数的位置
	fwrite(&writeSupplement, sizeof(unsigned int), 1, fpCompress);
	fwrite(&readSupplement, sizeof(unsigned int), 1, fpCompress);
	fwrite(&charfrequencysize, sizeof(unsigned int), 1, fpCompress);
	for (auto i : charfrequency)
	{
		fwrite(&i.first, sizeof(unsigned int), 1, fpCompress);
		fwrite(&i.second, sizeof(unsigned int), 1, fpCompress);
	}
	std::string temp = "";
	fseek(fpOrigin, 0l, SEEK_SET);
	do
	{
		unsigned int bits = 0;
		unsigned int symbol = readsymbol(bits);
		if (feof(fpOrigin))
		{
			if (bits != 0)
			{
				for (unsigned int i = bits; i < halfbyte; i++)
				{
					symbol = symbol << 4;
				}
				temp += huffmantree->code[symbol];
			}
		}
		else temp += huffmantree->code[symbol];
		if (feof(fpOrigin))
		{
			for (unsigned int i = 0; i < huffmantree->getUnitSize() - 1; i++)
				temp += "0";
		}
		while (temp.length() >= huffmantree->getUnitSize())
		{
			char byte[9] = { 0 };
			strncpy(byte, temp.c_str(), huffmantree->getUnitSize());
			unsigned char bytetoch = (unsigned char)strtol(byte, NULL, huffmantree->branch);
			fputc(bytetoch, fpCompress);
			temp.erase(0, huffmantree->getUnitSize());
		}
		if (feof(fpOrigin))
		{
			fseek(fpCompress, 0l, SEEK_SET);
			writeSupplement = huffmantree->getUnitSize() - 1 - temp.length();
			fputc(writeSupplement, fpCompress);
		}
	} while (!feof(fpOrigin));
}

void User::getFrequencyAndLength()
{
	fread(&writeSupplement, sizeof(unsigned int), 1, fpCompress);
	fread(&readSupplement, sizeof(unsigned int), 1, fpCompress);
	fread(&huffmantree->leavesnum, sizeof(unsigned int), 1, fpCompress);
	for (unsigned int i = 0; i < huffmantree->leavesnum; i++)
	{
		unsigned int pos;
		fread(&pos, sizeof(unsigned int), 1, fpCompress);
		charfrequency[pos] = 0;
		fread(&charfrequency[pos], sizeof(unsigned int), 1, fpCompress);
	}
	fseek(fpCompress, 0l, SEEK_END);
	progress = ftell(fpCompress) - 12 - 8 * huffmantree->leavesnum;
	fseek(fpCompress, 12 + 8 * huffmantree->leavesnum, SEEK_SET);
}

void User::checkAndSave(char temp[], const unsigned int num)
{
	while (strlen(temp) > num)
	{
		char byte[3] = { 0 };
		strncpy(byte, temp, 2);
		unsigned char bytetoch = (unsigned char)strtol(byte, NULL, 16);
		fputc(bytetoch, fpOrigin);
		memmove(temp, temp + 2, strlen(temp) + 1 - 2);
	}
}

char* User::baseConversion(unsigned int ch, char destination[])
{
	for (unsigned int i = 0; i < halfbyte; i++)
	{
		char temp[10];
		int part = ch & 15;
		_itoa(part, temp, 16);
		destination[halfbyte - i - 1] = temp[0];
		ch = ch >> 4;
	}
	destination[halfbyte] = 0;
	return destination;
}

std::string User::baseDecode(unsigned char ch)
{
	std::string result = "";
	for (unsigned int i = 0; i < huffmantree->getUnitSize(); i++)
	{
		result += ch % huffmantree->branch + '0';
		ch = ch / huffmantree->branch;
	}
	return result;
}

void User::decodeAndWriteFile()
{
	std::string originpath = path.substr(0, path.length() - 4);
	fpOrigin = fopen(originpath.c_str(), "wb");
	unsigned char ch;
	int num = 0;
	unsigned int root = huffmantree->leavesnum + (huffmantree->leavesnum - 1) / (huffmantree->branch - 1);
	unsigned int p = root;
	char temp[20] = { 0 };
	std::string result = "";
	while (true)
	{
		if (num == 0)
		{
			ch = fgetc(fpCompress);
			num = huffmantree->getUnitSize();
			result = baseDecode(ch);
			if (--progress == 0) break;
		}
		if (huffmantree->HT[p].child[0] != 0)
		{
			p = huffmantree->HT[p].child[result.c_str()[--num] - '0'];
		}
		else
		{
			char ch[10];
			strcat(temp, baseConversion(huffmantree->HT[p].ch, ch));
			checkAndSave(temp, 8u);
			p = root;
		}
	}
	while (num >= (int)writeSupplement)
	{
		if (huffmantree->HT[p].child[0] != 0)
		{
			p = huffmantree->HT[p].child[result.c_str()[--num] - '0'];
		}
		else
		{
			char ch[10];
			strcat(temp, baseConversion(huffmantree->HT[p].ch, ch));
			checkAndSave(temp, 8u);
			p = root;
		}
	}
	checkAndSave(temp, readSupplement);
}