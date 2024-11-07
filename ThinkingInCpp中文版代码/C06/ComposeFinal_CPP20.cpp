//: C06:ComposeFinal_CPP20.cpp {-edg}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ���ⴴ��composer��ֱ��ʹ��lambda���ʽ
#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include "NumStringGen.h"
using namespace std;



int main() {
    const int SZ = 9;      // ׼��������ת��9���ַ���
    vector<string> vs(SZ); // ����������ַ������
    generate(vs.begin(), vs.end(), NumStringGen());
    copy(vs.begin(), vs.end(),
         ostream_iterator<string>(cout, "\t"));
    cout << endl;
    vector<double> vd;

    // ԭ�����ʹ��ptr_fun()��mem_fun_ref������
    // transform(vs.begin(), vs.end(), back_inserter(vd),
    //           compose(ptr_fun(atof), mem_fun_ref(&string::c_str)));

    // ��Ϊʹ��lambda���ʽ������stod�滻atof
    transform(vs.begin(), vs.end(), std::back_inserter(vd),
                   [](const std::string& str) { return std::stod(str); });        
    
    copy(vd.begin(), vd.end(),
         ostream_iterator<double>(cout, "\t"));
    cout << endl;
} ///:~
