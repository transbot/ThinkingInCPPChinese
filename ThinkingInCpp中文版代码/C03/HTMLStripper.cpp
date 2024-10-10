//: C03:HTMLStripper.cpp {RunByHand}
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
//{L} ReplaceAll

// �ù����������Ƴ�HTML��ǩ�ͱ��
#include <cassert>
#include <cmath>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>
#include "ReplaceAll.h"
#include "../require.h"

using namespace std;

string& stripHTMLTags(string& s) {
    static bool inTag = false;
    bool done = false;
    while(!done) {
        if(inTag) {
            // ��һ�п�ʼ��һ��HTML��ǵ�û�н����������������'>'.
            size_t rightPos = s.find('>');
            if(rightPos != string::npos) {
                inTag = false;
                s.erase(0, rightPos + 1);
            } else {
                done = true;
                s.erase();
            }
        } else {
            // ���ұ�ǵ���ʼ���ţ�
            size_t leftPos = s.find('<');
            if(leftPos != string::npos) {
                // �жϱ���Ƿ���ͬһ�н�����
                size_t rightPos = s.find('>');
                if(rightPos == string::npos) {
                    inTag = done = true;
                    s.erase(leftPos);
                } else
                    s.erase(leftPos, rightPos - leftPos + 1);
            } else
                done = true;
        }
    }

    // �Ƴ���������HTML�ַ�
    replaceAll(s, "&lt;", "<");
    replaceAll(s, "&gt;", ">");
    replaceAll(s, "&amp;", "&");
    replaceAll(s, "&nbsp;", " ");
    // �ȵ�...
    return s;
}

int main(int argc, char* argv[]) {
    requireArgs(argc, 1,
               "�÷�: HTMLStripper ��Ĳ���.html�ļ�");
    ifstream in(argv[1]);
    assure(in, argv[1]);
    string s;
    while(getline(in, s))
        if(!stripHTMLTags(s).empty())
            cout << s << endl;
} ///:~
