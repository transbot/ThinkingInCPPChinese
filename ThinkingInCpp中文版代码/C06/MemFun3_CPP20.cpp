//: C06:MemFun3_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ʹ���ִ�C++���Խ����ַ�������������ת��
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
    const int SZ = 9;  // ׼�����ɲ�ת��9��������
    vector<string> vs(SZ);
    
    // ����������ַ��������vs����
    srand(time(0));                                 // ��ʼ�����������
    generate(vs.begin(), vs.end(), NumStringGen()); // ������������ַ���

    // ������ɵ�������ַ���
    copy(vs.begin(), vs.end(), ostream_iterator<string>(cout, "\t"));
    cout << endl;

    // ʹ��lambda���ʽ���ַ���ת��ΪC����ַ���
    vector<const char*> vcp(SZ);
    transform(vs.begin(), vs.end(), vcp.begin(), [](const string& s) { return s.c_str(); });

    // ʹ��lambda���ʽ��C����ַ���ת��Ϊ˫���ȸ�����
    // ԭ��ʹ�õ���atof()����Ȼ����һ�����õ�C�⺯���������ִ�C++�У�
    // ���Ƽ�ʹ��std::stod�������ַ�������������ת����
    // std::stod��C++11����ı�׼�⺯�������ṩ�˸���ȫ�͸������ת����ʽ��
    vector<double> vd;
    transform(vcp.begin(), vcp.end(), back_inserter(vd), [](const char* s) { return std::stod(s); });

    // ���������ʽ
    cout.precision(4);
    cout.setf(ios::showpoint);

    // ���ת����ĸ�����
    copy(vd.begin(), vd.end(), ostream_iterator<double>(cout, "\t"));
    cout << endl;

    return 0;
}