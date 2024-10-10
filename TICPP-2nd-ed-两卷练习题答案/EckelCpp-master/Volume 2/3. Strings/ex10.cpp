/*
编写一个程序，该程序接收三个命令行实参（文件名和两个字符串），
并在控制台显示文件中同时包含两个字符串的行（Both）、
包含任何一个字符串的行（Either）或者不包含任何字符串的行（Neither）。
具体如何显示要取决于用户在程序开始时的输入（执行程序后，会询问用户要使用什么匹配模式）。
除了Neither选项之外，对于匹配的字符串，在显示时使用星号（*）在字符串的开头和结尾进行突出显示。
*/

// 执行命令：ex10 
// 操作的文本文件固定为ex10.txt
// 例如，输入第一个字符串为“行”，第二个为“字符串”，模式选择1

#include <iostream>
#include <fstream>
#include <string>

enum Modes {Both = 1, Either = 2, Neither = 3};

bool should_print(bool flag1, bool flag2, Modes mode) {

	if ( (mode == Both) && (flag1 == true) && (flag2 == true) )
		return true;

	if ( (mode == Either) && (flag1 == !flag2) )
		return true;

	if ( (mode == Neither) && (flag1 == false) && (flag2 == false) )
		return true;

return false;
}

void highlight_words(std::string& line, std::string word) {
	size_t offset;
	size_t p = line.find(word);
	while (p != std::string::npos) {
		offset = p + word.size() + 1;
		line.insert(p, "*");
		line.insert(offset, "*");
		p = line.find(word, offset);
	}
}

int main() {

	std::ifstream source("ex10.txt", std::ios::in);
	std::string str1, str2;

	std::cout << "输入第一个字符串: ";
	std::cin >> str1;
	std::cout << "输入第二个字符串: ";
	std::cin >> str2;
	std::cout << "指定搜索模式\n (1: Both, 2: Either, 其他: Neither): ";

	Modes current_mode;
	int mode;

	std::cin >> mode;

	switch(mode) {
		case 1:
			current_mode = Both;
			break;
		case 2:
			current_mode = Either;
			break;
		default:
			current_mode = Neither;
			break;
	}

	std::cout << "第一个字符串: " << str1 << ", 第二个字符串: " << str2 << ", 模式: " << current_mode << '\n';

	std::string buf;
	size_t pos;
	bool word1, word2;

	while (getline(source, buf)) {

		word1 = word2 = false;

		pos = buf.find(str1);
			if (pos != std::string::npos)
				word1 = true;

		pos = buf.find(str2);
			if (pos != std::string::npos)
				word2 = true;

		if ( should_print(word1, word2, current_mode) ) {
			if (current_mode != Neither) {
				highlight_words(buf, str1);
				highlight_words(buf, str2);
			}
			std::cout << buf << '\n';
		}
	}

return 0;
}
