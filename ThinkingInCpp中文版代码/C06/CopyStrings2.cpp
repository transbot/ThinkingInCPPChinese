//: C06:CopyStrings2.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// �滻����ν�ʵ��ַ���
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
    string b[SIZE];

    // ʹ��replace_copy_if�滻����"��"���ַ���
    string* endb = replace_copy_if(a, a + SIZE, b, contains_qi, "ʮ����");

    // ������
    string* beginb = b;
    while(beginb != endb)
        cout << *beginb++ << endl;
} ///:~