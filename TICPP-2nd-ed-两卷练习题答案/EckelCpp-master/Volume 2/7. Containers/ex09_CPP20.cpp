// ��һ��ͨ��������ָ����Ӣ���ı��ļ����𵥴ʶ�ȡ�ļ���ʹ��multiset<string>����ÿ�����ʵĴ�Ƶͳ�ơ�
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <set>
#include <cstdlib> // for exit

using namespace std;

int main(int argc, char* argv[]) {
    string filename = "ex09.txt"; // Ĭ���ļ���

    // ��������в���
    if (argc > 1) {
        filename = argv[1];
    }

    ifstream source(filename, ios::in);
    if (!source) {
        cerr << "�޷����ļ�: " << filename << endl;
        return 1;
    }

    multiset<string> words;
    string buf;

    // ��ʶ�ȡ�ļ����ݲ����뵽multiset��
    while (source >> buf) {
        words.insert(buf);
    }

    // ͳ��ÿ�����ʵĳ��ִ��������
    auto it = words.begin();
    while (it != words.end()) {
        auto p = words.equal_range(*it);
        int count = distance(p.first, p.second);
        cout << *it << ": " << count << '\n';
        it = p.second;
    }

    return 0;
}