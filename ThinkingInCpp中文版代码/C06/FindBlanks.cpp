//: C06:FindBlanks.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾͨ��mem_fun_ref()��ʹ��string::empty()
#include <algorithm>
#include <cassert>
#include <cstddef>
#include <fstream>
#include <functional>
#include <string>
#include <vector>
#include "../require.h"
using namespace std;

// ����һ�����ͱ��������ڱ�ʾ�ַ��������ĵ�����
typedef vector<string>::iterator LSI;

int main(int argc, char* argv[]) {
    char* fname = "FindBlanks.cpp"; // Ĭ���ļ���Ϊ"FindBlanks.cpp"
    if(argc > 1) fname = argv[1];   // ��Ҳ����ͨ��������ʵ����ָ�������ļ�

    ifstream in(fname);             // ���ļ�
    assure(in, fname);              // ȷ���ļ���ȷ��
    
    vector<string> vs;              // ���ַ����������ڴ洢�ļ��е�ÿһ��
    string s;                       // ����ʱ�ַ������ڶ�ȡÿһ��
    while(getline(in, s))           // ���ж�ȡ�ļ�
        vs.push_back(s);            // ��ÿһ����ӵ�������
    vector<string> cpy = vs;        // ����������һ�����������ں�������
    
    // ���ҵ�һ������
    LSI lsi = find_if(vs.begin(), vs.end(), 
                      mem_fun_ref(&string::empty));
    
    while(lsi != vs.end()) { // ����ҵ��˿���
        *lsi = "����";       // �ͽ������滻Ϊ"����"
        // ����������һ������
        lsi = find_if(vs.begin(), vs.end(),
                      mem_fun_ref(&string::empty));
    }
    for(size_t i = 0; i < cpy.size(); i++)
        if(cpy[i].size() == 0)        // ���ԭ�����е�ĳһ���ǿ���
            assert(vs[i] == "����");  // ȷ�ϸ����ѱ��滻Ϊ"����"
        else
            assert(vs[i] != "����");  // ȷ�Ϸǿ���δ���滻
} ///:~

