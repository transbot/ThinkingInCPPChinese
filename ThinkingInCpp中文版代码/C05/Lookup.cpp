//: C05:Lookup.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ֻ��ʹ��ĳЩ�ض������������磬EDG��Metrowerks�����Һ���Ҫʹ��һ������ѡ���
// ����Ż���ֳ���Ԥ�ڡ�����Ϊ��
#include <iostream>
using std::cout;
using std::endl;

// ����doubleֵʱ��ӡ"f(double)"
void f(double) { cout << "f(double)" << endl; }

// ��ģ�������һ����Ա����g��g����������f������������ֵ1
// ֵ1��double����int������һ�����⣡
template<class T> class X {
public:
    void g() { f(1); }
};

// ����intֵʱ��ӡ"f(int)"
void f(int) { cout << "f(int)" << endl; }

// main����һ��X<int>���͵Ķ��󣬲������������ĳ�Ա����g
// �����������Ϊ1��int����ôӦ�õ���f(int)�����������"f(int)"
// �����������Ϊ1��double����ôӦ�õ���f(double)�����������"f(double)"
int main() {
    X<int>().g();
} ///:~
