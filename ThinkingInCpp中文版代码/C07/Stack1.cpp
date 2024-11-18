//: C07:Stack1.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾSTL stack
#include <fstream>
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// ��������ɾע�ͷ�����ʹ�ò�ͬ�汾
typedef stack<string> Stack1; // Ĭ�ϣ�deque<string>
// typedef stack<string, vector<string>> Stack2;
// typedef stack<string, list<string>> Stack3;

int main() {
    ifstream in("Stack1.cpp");
    Stack1 textlines; // ���Բ�ͬ�汾

    // ��ȡ�ļ������д洢��ջ��
    string line;
    while(getline(in, line))
        textlines.push(line + "\n");

    // ��ӡջ�д洢���У���ӡ�󵯳�
    while(!textlines.empty()) {
        cout << textlines.top();
        textlines.pop();
    }
} ///:~
