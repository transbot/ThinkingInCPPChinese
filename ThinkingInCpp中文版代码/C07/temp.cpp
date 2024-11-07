#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <locale>
#include "../require.h"
using namespace std;

#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include "../require.h"
#include <boost/algorithm/string.hpp> // ʹ�� Boost ����зִ�

using namespace std;

// �����ı��ļ����� UTF-8 ���룬��ʹ�� Boost ����зִ�
void wordSet(const char* fileName) {
    ifstream source(fileName);
    assure(source, fileName);
    string line, word;
    set<string> chineseWords; // �洢���ظ��ĺ���
    set<string> englishWords; // �洢���ظ���Ӣ�ĵ���

    while (getline(source, line)) {
        // ʹ�� Boost �ִʣ��������ִʽ��Ϊ��������
        boost::split(chineseWords, line, boost::is_any_of(" "));

        // ��ȡӢ�ĵ��ʵĲ��֣����Ը���ʵ���������������ʽ��
        boost::regex englishRegex("[a-zA-Z]+");
        boost::sregex_iterator iter(line.begin(), line.end(), englishRegex);
        boost::sregex_iterator end;
        while (iter != end) {
            englishWords.insert(iter->str());
            ++iter;
        }
    }

    // ������
    cout << "���ظ��ĺ���������" << chineseWords.size() << endl;
    cout << "���ظ���Ӣ�ĵ���������" << englishWords.size() << endl;
}

int main(int argc, char* argv[]) {
    if(argc > 1) // ������������ṩ���ļ���ʵ�Σ���ʹ�ø��ļ���
        wordSet(argv[1]);
    else         // ����ʹ��Ĭ���ļ�
        wordSet("WordSet.cpp");
} ///:~