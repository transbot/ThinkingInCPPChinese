//: C06:ReplaceStrings.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ԭ���滻�ַ���
#include <algorithm> 
#include <cstddef> 
#include <iostream> 
#include <string> 
using namespace std;

// ν�ʣ��ж��ַ������Ƿ�������ߡ���
// ��ͬ�������޸�Ϊlambda���ʽ��
bool contains_qi(const string& s) { 
    return s.find("��") != string::npos; 
}

int main() { 
    string a[] = {"��һȥ", "��", "ʮѽô", "ʮ����"};
    const size_t SIZE = sizeof a / sizeof a[0]; 
    replace_if(a, a + SIZE, contains_qi, string("ʮ����")); 
    string* p = a; 
    while(p != a + SIZE)
        cout << *p++ << endl; 
} ///:~
