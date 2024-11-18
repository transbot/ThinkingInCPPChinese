/*
����һ��set<char>����һ���ļ����ļ���ͨ���������ṩ���������ַ���ȡ���ļ���
��ÿ��char����set�С���ӡ�������ע��۲졣�Ƿ���һЩ��ĸû���ڸ��ļ����õ���
ע����������ԭ�𰸽������޸ģ����Զ������ļ���δʹ�õ���ĸ��
*/

#include <iostream>
#include <fstream>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "�÷�: " << argv[0] << " filename" << endl;
        return 1;
    }

    set<char> chars;
    ifstream infile(argv[1]);

    if (!infile.is_open()) {
        cerr << "���ļ�ʧ��: " << argv[1] << endl;
        return 1;
    }

    char ch;
    while (infile.get(ch)) {
        // ��������ĸת��ΪСд��ͳһ����
        chars.insert(tolower(ch));
    }

    infile.close();

    cout << "�ļ����õ����ַ���Ӣ����ĸ�����ִ�Сд��:" << endl;
    for (char c : chars) {
        cout << c << " ";
    }
    cout << endl;

    // ����ȱʧ��ĸ�����Ǵ�Сд��
    cout << "û���õ���ĸ���е�������ĸ:(�����ִ�Сд):" << endl;
    for (char c = 'a'; c <= 'z'; ++c) {
        if (chars.count(c) == 0) {
            cout << c << " ";
        }
    }
    cout << endl;

    return 0;
}