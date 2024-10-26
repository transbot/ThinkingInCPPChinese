//: C05:StaticAssert2.cpp {-g++}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include <iostream>
using namespace std;

// һ��ģ���һ���ػ�
template<bool> struct StaticCheck {
    StaticCheck(...);
};
template<> struct StaticCheck<false> {};

// �꣨��������һ���ֲ��ࣩ
#define STATIC_CHECK(expr, msg) { \
    class Error_##msg {}; \
    sizeof((StaticCheck<expr>(Error_##msg()))); \
}

// �����Сת��
template<class To, class From> To safe_cast(From from) {
    STATIC_CHECK(sizeof(From) <= sizeof(To), NarrowingConversion);
    return reinterpret_cast<To>(from);
}

int main() {
    void* p = 0;
    int i = safe_cast<int>(p);
    cout << "���԰�ȫת��Ϊint\n";
    //! char c = safe_cast<char>(p);
} ///:~
