#include "HuffmanTree.h"
#include <iostream>
#include <algorithm>

HuffmanTree::HuffmanTree(unsigned int halfbyte, unsigned int branch)
{
	leavesnum = 0;
	HT = NULL;
	this->halfbyte = halfbyte;
	this->branch = branch;
}

HuffmanTree::~HuffmanTree()
{
	delete[](HT);
}

void HuffmanTree::createTree(std::map<unsigned int, unsigned int> charfrequency)
{
	leavesnum = charfrequency.size();
	leavesnum += branch - 1 - (leavesnum - 1) % (branch - 1);
	HT = new HTNode[leavesnum + (leavesnum - 1) / (branch - 1) + 1]();
	leavesnum = 0;
	for (auto i : charfrequency)
	{
		HT[++leavesnum].ch = i.first;
		HT[leavesnum].weight = i.second;
	}
	if (leavesnum == 0 || leavesnum == 1)
	{
		std::cout << "无法构造Huffman树" << std::endl;
		exit(1);
	}
	leavesnum += branch - 1 - (leavesnum - 1) % (branch - 1);
	for (unsigned int i = leavesnum + 1; i <= leavesnum + (leavesnum - 1) / (branch - 1); i++)
	{
		std::pair<unsigned int, unsigned int>  minNum[16];
		selectMinNum(i - 1, minNum);
		for (unsigned int j = 0; j < branch; j++)
		{
			HT[minNum[j].first].parent = i;
			HT[i].child[j] = minNum[j].first;
			HT[i].weight += minNum[j].second;
		}
	}
}

void HuffmanTree::createCode()
{
	for (unsigned int i = 1; i <= leavesnum; i++)
	{
		if (HT[i].weight == 0) continue;
		code[HT[i].ch] = "";
		for (unsigned int j = i; HT[j].parent; j = HT[j].parent)
		{
			unsigned int parent = HT[j].parent;
			for (unsigned int k = 0; k < branch; k++)
			{
				if (HT[parent].child[k] == j)
				{
					if (k < 10)
						code[HT[i].ch] += '0' + k;
					else code[HT[i].ch] += 'a' + k - 10;
					break;
				}
			}
		}
		std::reverse(code[HT[i].ch].begin(), code[HT[i].ch].end());
	}
}

unsigned int HuffmanTree::getUnitSize()
{
	switch (branch)
	{
	case 2:
		return 8;
	case 3:
		return 5;
	case 4:
		return 4;
	case 5:case 6:
		return 3;
	default:
		return 2;
	}
}

bool compare(std::pair<unsigned int, unsigned int> a, std::pair<unsigned int, unsigned int> b)
{
	return a.second < b.second;
}

void HuffmanTree::selectMinNum(const unsigned int i, std::pair<unsigned int, unsigned int> minNum[])
{
	unsigned int j = 0;
	for (unsigned int i = 0; i < branch; i++)
	{
		while (true)
		{
			j++;
			if (HT[j].parent == 0)
			{
				minNum[i].first = j;
				minNum[i].second = HT[j].weight;
				break;
			}
		}
	}
	std::sort(minNum, minNum + branch, compare);
	for (j = j + 1; j <= i; j++)
	{
		if (HT[j].parent == 0)
		{
			if (HT[j].weight < minNum[branch - 1].second)
			{
				minNum[branch - 1].first = j;
				minNum[branch - 1].second = HT[j].weight;
				std::sort(minNum, minNum + branch, compare);
			}
		}
	}
}