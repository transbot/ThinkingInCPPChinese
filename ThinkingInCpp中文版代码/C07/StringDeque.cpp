//: C07:StringDeque.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// �޸���StringVector.cpp 
#include <cstddef>
#include <ctime>
#include <deque>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>
#include "../require.h"
using namespace std;

int main(int argc, char* argv[]) {
    const char* fname = "StringDeque.cpp";
    if(argc > 1) fname = argv[1];
    ifstream in(fname);
    assure(in, fname);

    vector<string> vstrings;
    deque<string> dstrings;
    string line;

    // ���Զ�ȡ��vector��ʱ��
    clock_t ticks = clock();
    while(getline(in, line))
        vstrings.push_back(line);
    ticks = clock() - ticks;
    cout << "��ȡ��vector: " << ticks << endl;

    // ��deque������ͬ�Ĳ��ԣ�
    ifstream in2(fname);
    assure(in2, fname);
    ticks = clock();
    while(getline(in2, line))
        dstrings.push_back(line);
    ticks = clock() - ticks;
    cout << "��ȡ��deque: " << ticks << endl;

    // ���ڱȽ���������
    ticks = clock();
    for(size_t i = 0; i < vstrings.size(); i++) {
        ostringstream ss;
        ss << i;
        vstrings[i] = ss.str() + ": " + vstrings[i];
    }
    ticks = clock() - ticks;
    cout << "vector����: " << ticks << endl;

    ticks = clock();
    for(size_t j = 0; j < dstrings.size(); j++) {
        ostringstream ss;
        ss << j;
        dstrings[j] = ss.str() + ": " + dstrings[j];
    }
    ticks = clock() - ticks;
    cout << "deque����: " << ticks << endl;

    // �Ƚϱ�������
    ofstream tmp1("tmp1.tmp"), tmp2("tmp2.tmp");
    ticks = clock();
    copy(vstrings.begin(), vstrings.end(),
         ostream_iterator<string>(tmp1, "\n"));
    ticks = clock() - ticks;
    cout << "vector����: " << ticks << endl;

    ticks = clock();
    copy(dstrings.begin(), dstrings.end(),
         ostream_iterator<string>(tmp2, "\n"));
    ticks = clock() - ticks;
    cout << "deque����: " << ticks << endl;
} ///:~
