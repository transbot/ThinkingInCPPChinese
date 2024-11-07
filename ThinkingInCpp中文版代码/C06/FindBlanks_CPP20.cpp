//: C06:FindBlanks_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾͨ��lambda���ʽ��ʹ��string::empty()
// ͬʱ��ʾ�����ڷ�Χ��for��
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <fstream>
#include <functional>
#include <string>
#include <vector>
#include <iostream>
#include "../require.h"
using namespace std;

int main(int argc, char* argv[]) {
    char* fname = "FindBlanks_CPP20.cpp"; // Ĭ���ļ���Ϊ "FindBlanks_CPP20.cpp"
    if (argc > 1) fname = argv[1];  // ��Ҳ����ͨ��������ʵ����ָ�������ļ�

    ifstream in(fname);             // ���ļ�
    assure(in, fname);              // ȷ���ļ���ȷ��

    vector<string> vs;              // ���ַ����������ڴ洢�ļ��е�ÿһ��
    string s;                       // ����ʱ�ַ������ڶ�ȡÿһ��
    while (getline(in, s))          // ���ж�ȡ�ļ�
        vs.push_back(s);            // ��ÿһ����ӵ�������
    vector<string> cpy = vs;        // ����������һ�����������ں�������

    // ʹ��lambda���ʽ���Ҳ��滻����
    auto is_empty = [](const string& str) { return str.empty(); };
    auto it = find_if(vs.begin(), vs.end(), is_empty);
    while (it != vs.end()) {
        *it = "����";               // �������滻Ϊ"����"
        it = find_if(it + 1, vs.end(), is_empty); // ����������һ������
    }

    // ��֤���
    for (size_t i = 0; i < cpy.size(); ++i) {
        if (cpy[i].empty())          // ���ԭ�����е�ĳһ���ǿ���
            assert(vs[i] == "����"); // ȷ�ϸ����ѱ��滻Ϊ"����"
        else
            assert(vs[i] != "����"); // ȷ�Ϸǿ���δ���滻
    }

    // ���ԭ��������ָ���ļ��������ݣ�ע��ʹ�����ִ�C++���õġ����ڷ�Χ��for������
    cout << "�������ļ����ݣ�" << endl;
    for (const auto& line : vs) {
        cout << line << endl;
    }

    return 0;
}