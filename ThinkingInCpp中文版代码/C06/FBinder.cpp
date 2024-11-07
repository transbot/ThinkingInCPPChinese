//: C06:FBinder.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ������binder������������ν��
//{L} Generators
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
#include "Generators.h"
using namespace std;

int main() {
    ostream_iterator<int> out(cout," ");
    vector<int> v(15);
    srand(time(0));  // �����
    generate(v.begin(), v.end(), URandGen(20));

    // ���ԭʼvector
    copy(v.begin(), v.end(), out);
    cout << endl;
    
    // ÿ��Ԫ�س���10
    transform(v.begin(), v.end(), v.begin(), bind2nd(multiplies<int>(), 10));
    // ���������䲻�����ִ�C++��׼��Ӧ�滻Ϊʹ��lambda���ʽ��
    // transform(v.begin(), v.end(), v.begin(), [](int x) { return x * 10; });
  
    // ������vector
    copy(v.begin(), v.end(), out);
} ///:~
