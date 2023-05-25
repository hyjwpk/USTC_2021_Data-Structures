#include <iostream>
#include <string>
#include <string.h>
#include "User.h"
int main(int argc, char* argv[])
{
	User* user;
	if (argc == 5)
	{
		user = new User(atoi(argv[3]), atoi(argv[4]));
		std::cout << "�������ŵ�Ԫ:" << argv[3] << " " << "Huffman������:" << argv[4] << std::endl;
	}
	else if (argc == 3)
	{
		std::cout << "�������ŵ�Ԫ:" << 2 << " " << "Huffman������:" << 2 << std::endl;
		user = new User();
	}
	else
	{
		std::cout << "��������" << std::endl;
		exit(2);
	}
	user->path = argv[1];
	if (atoi(argv[2]) == 0)
	{
		user->compress();
	}
	else if (atoi(argv[2]) == 1)
	{
		user->decompress();
	}

	//user = new User();
	//user->path = "C:\\Users\\wangc\\source\\repos\\HuffmanCode\\Debug\\1.gif";
	//user->compress();
	//delete(user);
	//user = new User();
	//user->path = "c:\\users\\wangc\\source\\repos\\huffmancode\\debug\\1.gif.cop";
	//user->decompress();
	//delete (user);
}