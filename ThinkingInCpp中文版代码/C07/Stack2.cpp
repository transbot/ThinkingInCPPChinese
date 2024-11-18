//: C07:Stack2.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��listת��Ϊstack
#include <iostream>
#include <fstream>
#include <stack>
#include <list>
#include <string>
#include <cstddef>
using namespace std;

// Ԥ�ڵ���һ��stack 
template<class Stk>
void stackOut(Stk& s, ostream& os = cout) {
    while(!s.empty()) {
        os << s.top() << "\n";
        s.pop();
    }
}

class Line {
    string line;    // ����ǰ���ո����
    size_t lspaces; // ǰ���ո������
public:
    Line(string s) : line(s) {
        lspaces = line.find_first_not_of(' ');
        if(lspaces == string::npos)
            lspaces = 0;
        line = line.substr(lspaces);
    }
    friend ostream& operator<<(ostream& os, const Line& l) {
        for(size_t i = 0; i < l.lspaces; i++)
            os << ' ';
        return os << l.line;
    }
    // ��������...
};

int main() {
    ifstream in("Stack2.cpp");
    list<Line> lines;
    // ��ȡ�ļ������д洢���б���
    string s;
    while(getline(in, s))
        lines.push_front(s);
    // ��listת��Ϊstack�Խ��д�ӡ
    stack<Line, list<Line>> stk(lines);
    stackOut(stk);
} ///:~
