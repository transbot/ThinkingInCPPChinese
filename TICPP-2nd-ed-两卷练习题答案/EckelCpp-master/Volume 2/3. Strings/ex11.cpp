/*
编写一个程序，该程序接收两个命令行实参（一个文件名和一个字符串），并计算字符串在文件中出现的次数，
无论它是不是子串（但是忽略重叠）。例如，输入字符串“ba”在单词“basketball”计为匹配两次，
但输入字符串“ana”在单词“banana”中只计为匹配一次（因为发生了重叠）。在控制台中显示字符串在文件中匹配的次数，
以及包含该字符串的单词的平均长度。（如果一个单词中字符串出现了多次，那么在计算平均长度时只计算一次。）
*/

#include <iostream>
#include <fstream>
#include <string>
#include <set>

int main() {

	std::ifstream source("ex11.txt", std::ios::in);
	std::string str;

	std::cout << "请输入要查找的字符串: ";
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

	std::cout << "字符串 " << str << " 在给定的文件中出现了 " << s_count << " 次。\n";

	int lengths = 0;
	for (const auto& s : words) {
		lengths += s.size();
	}

	if (words.size() != 0)
		std::cout << "平均单词长度: " << lengths / words.size() << '\n';

return 0;
}
