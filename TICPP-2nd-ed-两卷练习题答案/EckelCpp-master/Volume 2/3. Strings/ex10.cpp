/*
��дһ�����򣬸ó����������������ʵ�Σ��ļ����������ַ�������
���ڿ���̨��ʾ�ļ���ͬʱ���������ַ������У�Both����
�����κ�һ���ַ������У�Either�����߲������κ��ַ������У�Neither����
���������ʾҪȡ�����û��ڳ���ʼʱ�����루ִ�г���󣬻�ѯ���û�Ҫʹ��ʲôƥ��ģʽ����
����Neitherѡ��֮�⣬����ƥ����ַ���������ʾʱʹ���Ǻţ�*�����ַ����Ŀ�ͷ�ͽ�β����ͻ����ʾ��
*/

// ִ�����ex10 
// �������ı��ļ��̶�Ϊex10.txt
// ���磬�����һ���ַ���Ϊ���С����ڶ���Ϊ���ַ�������ģʽѡ��1

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

	std::cout << "�����һ���ַ���: ";
	std::cin >> str1;
	std::cout << "����ڶ����ַ���: ";
	std::cin >> str2;
	std::cout << "ָ������ģʽ\n (1: Both, 2: Either, ����: Neither): ";

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

	std::cout << "��һ���ַ���: " << str1 << ", �ڶ����ַ���: " << str2 << ", ģʽ: " << current_mode << '\n';

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
