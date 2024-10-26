//: C05:FriendScope.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include <iostream>
using namespace std;

class Friendly {
    int i;
public:
    Friendly(int theInt) { i = theInt; }
    friend void f(const Friendly&); // ��Ҫȫ�ֶ���
    void g() { f(*this); }
};

void h() { f(Friendly(1)); } // ADL���ƽ���

void f(const Friendly& fo) { // ��Ԫ����
    cout << fo.i << endl;
}

int main() {
    h(); // ���1
    Friendly(2).g(); // ���2
} ///:~
