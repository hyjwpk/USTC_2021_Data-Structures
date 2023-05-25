#pragma once
#include <map>
#include <string>
#include "HuffmanTree.h"

class User
{
public:
	User(unsigned int halfbyte = 2, unsigned int branch = 2);
	~User();
	void compress();
	void decompress();
	std::string path;
private:
	unsigned int halfbyte;
	unsigned int readSupplement, writeSupplement;
	FILE* fpOrigin, * fpCompress;
	unsigned long long progress;
	std::map<unsigned int, unsigned int> charfrequency;
	HuffmanTree* huffmantree;
	void readFile(FILE*& fp);
	unsigned int readsymbol(unsigned int& bits);
	void calculateFrequency();
	void transcodeAndWriteFile();
	void getFrequencyAndLength();
	char* baseConversion(unsigned int ch, char destination[]);
	std::string baseDecode(unsigned char ch);
	void checkAndSave(char temp[], const unsigned int num);
	void decodeAndWriteFile();
};

