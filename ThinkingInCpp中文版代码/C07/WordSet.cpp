//: C07:WordSet.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

#include <fstream>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include "../require.h"
using namespace std;

// �ú�����ȡָ�����ļ��������е�Ӣ�ĵ��ʴ洢��������
void wordSet(const char* fileName) {
    ifstream source(fileName); // ���ļ�
    assure(source, fileName);  // ȷ���ļ��ɹ���
    string word;
    set<string> words;         // ����һ���������洢���ظ��ĵ���

    // ���ļ��������ȡ���ʣ���������뵽������
    while(source >> word)
        words.insert(word);

    // ʹ��������������������еĵ��ʴ�ӡ������̨��ÿ������һ��
    copy(words.begin(), words.end(),
         ostream_iterator<string>(cout, "\n"));
    cout << "���ظ��ĵ��ʵ�����:"
         << words.size() << endl;
}

int main(int argc, char* argv[]) {
    if(argc > 1) // ������������ṩ���ļ���ʵ�Σ���ʹ�ø��ļ���
        wordSet(argv[1]);
    else         // ����ʹ��Ĭ���ļ�
        wordSet("WordSet.cpp");
} ///:~