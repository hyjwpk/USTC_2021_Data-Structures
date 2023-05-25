#pragma once
#include<map>
#include<unordered_map>
#include<string>

struct HTNode
{
	unsigned int weight;
	unsigned int parent, child[16] = { 0 };
	unsigned int ch;
	HTNode()
	{
		weight = 0;
		parent = 0;
		ch = 0;
	}
};

class HuffmanTree
{
public:
	HuffmanTree(unsigned int halfbyte, unsigned int branch);
	~HuffmanTree();
	void createTree(std::map<unsigned int, unsigned int> charfrequency);
	void createCode();
	unsigned int getUnitSize();
	std::unordered_map<unsigned int, std::string> code;

	// 叶子节点数
	unsigned int leavesnum;

	// 总字符数为n，最多需要2*n-1个节点，0号单元未用
	HTNode* HT;
	unsigned int branch;
private:
	unsigned int halfbyte;
	void selectMinNum(const unsigned int i, std::pair<unsigned int, unsigned int> minNum[]);
};

