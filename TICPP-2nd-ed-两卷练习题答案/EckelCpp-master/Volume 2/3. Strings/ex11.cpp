/*
��дһ�����򣬸ó����������������ʵ�Σ�һ���ļ�����һ���ַ��������������ַ������ļ��г��ֵĴ�����
�������ǲ����Ӵ������Ǻ����ص��������磬�����ַ�����ba���ڵ��ʡ�basketball����Ϊƥ�����Σ�
�������ַ�����ana���ڵ��ʡ�banana����ֻ��Ϊƥ��һ�Σ���Ϊ�������ص������ڿ���̨����ʾ�ַ������ļ���ƥ��Ĵ�����
�Լ��������ַ����ĵ��ʵ�ƽ�����ȡ������һ���������ַ��������˶�Σ���ô�ڼ���ƽ������ʱֻ����һ�Ρ���
*/

#include <iostream>
#include <fstream>
#include <string>
#include <set>

int main() {

	std::ifstream source("ex11.txt", std::ios::in);
	std::string str;

	std::cout << "������Ҫ���ҵ��ַ���: ";
	std::cin >> str;

	std::string buf;
	size_t pos;
	int s_count = 0;
	std::set<std::string> words;

	while (source >> buf) {
		pos = buf.find(str);

		while (pos != std::string::npos) {
			++s_count;
			words.insert(buf);
			pos = buf.find(str, pos + str.size());
		}
	}

	std::cout << "�ַ��� " << str << " �ڸ������ļ��г����� " << s_count << " �Ρ�\n";

	int lengths = 0;
	for (const auto& s : words) {
		lengths += s.size();
	}

	if (words.size() != 0)
		std::cout << "ƽ�����ʳ���: " << lengths / words.size() << '\n';

return 0;
}
