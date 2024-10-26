//: C05:Conditionals.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ʹ�ñ���ʱ������ѡ��ִ�еĴ���
#include <iostream>
using namespace std;

template<bool cond> struct Select {};

// true�ػ�
template<> class Select<true> {
    static void statement1() {
        cout << "����ִ�����1 �C statement1\n";
    }
public:
    static void f() {
        statement1();
    }
};

// false�ػ�
template<> class Select<false> {
    static void statement2() {
        cout << "����ִ�����2 - statement2\n";
    }
public:
    static void f() {
        statement2();
    }
};

template<bool cond> void execute() {
    Select<cond>::f();
}

int main() {
    // int���͵Ĵ�СȷʵΪ4���ֽ� 
    execute<sizeof(int) == 4>();
} ///:~
