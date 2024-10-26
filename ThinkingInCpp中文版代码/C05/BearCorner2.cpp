//: C05:BearCorner2.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
// ��ʾ������
#include <iostream>
#include "BearCorner.h"
using namespace std;

// �����ࣨҪ��һ����̬doAction()��������
class Feed {
public:
    static const char* doAction() { return "ι"; }
};

class Stuff {
public:
    static const char* doAction() { return "���"; }
};

// Guestģ�壨ʹ����һ�����Ժ�һ��traits�ࣩ
template<class Guest, class Action, class traits = GuestTraits<Guest> >
class BearCorner {
    Guest theGuest;
    typedef typename traits::beverage_type beverage_type;
    typedef typename traits::snack_type snack_type;
    beverage_type bev; // �ȵ�
    snack_type snack;  // �Ե� 
public:
    BearCorner(const Guest& g) : theGuest(g) {}
    void entertain() {
        cout << "��" << bev << "��" << snack
             << Action::doAction() << theGuest << endl;
    }
};

int main() {
    Boy cr;
    BearCorner<Boy, Feed> pc1(cr);
    pc1.entertain();
    Bear pb;
    BearCorner<Bear, Stuff> pc2(pb);
    pc2.entertain();
} ///:~
