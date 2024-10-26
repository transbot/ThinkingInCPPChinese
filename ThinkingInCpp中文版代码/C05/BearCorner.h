//: C05:BearCorner.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#ifndef BEARCORNER_H
#define BEARCORNER_H
#include <iostream>
using std::ostream;

// ��ʾ������Ʒ���ࣨҲ���ǿ��˵�traits���������ɿ��˵ġ�ƫ�á�������������
class Milk {
public:
    friend ostream& operator<<(ostream& os, const Milk&) { return os << "ţ��"; }
};

class CondensedMilk {
public:
    friend ostream& operator<<(ostream& os, const CondensedMilk &) {
        return os << "����";
    }
};

class Honey {
public:
    friend ostream& operator<<(ostream& os, const Honey&) { return os << "����"; }
};

class Cookies {
public:
    friend ostream& operator<<(ostream& os, const Cookies&) { return os << "����"; }
};

// ��ʾ���ֿ��˵��ࣺ
class Bear {
public:
    friend ostream& operator<<(ostream& os, const Bear&) { return os << "̩��"; }
};

class Boy {
public:
    friend ostream& operator<<(ostream& os, const Boy&) { return os << "�������"; }
};

// ��traitsģ�壨�����ǿյģ���������ͨ�����ͣ�
template<class Guest> class GuestTraits;

// ��Կ������͵�traits�ػ�
// ��ϲ������ͷ���
template<> class GuestTraits<Bear> {
public:
    typedef CondensedMilk beverage_type;
    typedef Honey snack_type;
};

// �к�ϲ��ţ�̺ͱ���
template<> class GuestTraits<Boy> {
public:
    typedef Milk beverage_type;
    typedef Cookies snack_type;
};
#endif // BEARCORNER_H ///:~
