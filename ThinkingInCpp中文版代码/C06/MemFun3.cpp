//: C06:MemFun3.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ʹ��mem_fun_ref()
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include "NumStringGen.h"
using namespace std;

int main() {
    const int SZ = 9; // ׼�����ɲ�ת��9��������
    vector<string> vs(SZ);
    // ����������ַ��������vs����
    srand(time(0));                                 // ��ʼ�����������
    generate(vs.begin(), vs.end(), NumStringGen()); // ������������ַ���    
    copy(vs.begin(), vs.end(),
         ostream_iterator<string>(cout, "\t"));
    cout << endl;
    const char* vcp[SZ];
    transform(vs.begin(), vs.end(), vcp,
              mem_fun_ref(&string::c_str));
    vector<double> vd;
    transform(vcp, vcp + SZ, back_inserter(vd),
              std::atof);
    cout.precision(4);
    cout.setf(ios::showpoint);
    copy(vd.begin(), vd.end(),
         ostream_iterator<double>(cout, "\t"));
    cout << endl;
} ///:~