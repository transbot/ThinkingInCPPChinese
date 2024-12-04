//: C10:PaperScissorsRock.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// �á�ʯͷ-����-������Ϸ����ʾ���ص���
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "../purge.h"
using namespace std;

class Paper;
class Scissors;
class Rock;

// ������Ϸ���ö������
enum Outcome { WIN, LOSE, DRAW };

// ��������������������������Ϸ���
ostream& operator<<(ostream& os, const Outcome out) {
    switch(out) {
        default:
        case WIN: return os << "Ӯ��";
        case LOSE: return os << "����";
        case DRAW: return os << "ƽ��";
    }
}

// ����Item��ʾ��Ϸ�е�һ����Ʒ����ʵ��һ�����ƣ�
class Item {
public:
    // ���麯�������ڱȽ�������Ʒ
    virtual Outcome compete(const Item*) = 0;
    // ���麯����������ֵ��������Ʒ�Ĺ�ϵ
    virtual Outcome eval(const Paper*) const = 0;
    virtual Outcome eval(const Scissors*) const = 0;
    virtual Outcome eval(const Rock*) const = 0;
    // ���麯�������������Ʒ����
    virtual ostream& print(ostream& os) const = 0;
    // ����������
    virtual ~Item() {}
    // ��Ԫ���������������Ʒ
    friend ostream& operator<<(ostream& os, const Item* it) {
        return it->print(os);
    }
};

// ������Paper����ʾ������
class Paper : public Item {
public:
    // �Ƚ�������Ʒ
    Outcome compete(const Item* it) { return it->eval(this);}
    // ��ֵ��������Ʒ�Ĺ�ϵ
    Outcome eval(const Paper*) const { return DRAW; }
    Outcome eval(const Scissors*) const { return WIN; }
    Outcome eval(const Rock*) const { return LOSE; }
    // �����Ʒ����
    ostream& print(ostream& os) const {
        return os << "��";
    }
};

// ������Scissors����ʾ�����ӡ�
class Scissors : public Item {
public:
    // �Ƚ�������Ʒ
    Outcome compete(const Item* it) { return it->eval(this);}
    // ��ֵ��������Ʒ�Ĺ�ϵ
    Outcome eval(const Paper*) const { return LOSE; }
    Outcome eval(const Scissors*) const { return DRAW; }
    Outcome eval(const Rock*) const { return WIN; }
    // �����Ʒ����
    ostream& print(ostream& os) const {
        return os << "����";
    }
};

// ������Rock����ʾ��ʯͷ��
class Rock : public Item {
public:
    // �Ƚ�������Ʒ
    Outcome compete(const Item* it) { return it->eval(this);}
    // ��ֵ��������Ʒ�Ĺ�ϵ
    Outcome eval(const Paper*) const { return WIN; }
    Outcome eval(const Scissors*) const { return LOSE; }
    Outcome eval(const Rock*) const { return DRAW; }
    // �����Ʒ����
    ostream& print(ostream& os) const {
        return os << "ʯͷ";
    }
};

// �ṹ��ItemGen�������������Ʒ
struct ItemGen {
    Item* operator()() {
        switch(rand() % 3) {
            default:
            case 0: return new Scissors;
            case 1: return new Paper;
            case 2: return new Rock;
        }
    }
};

// �ṹ��Compete���ڱȽ�������Ʒ
struct Compete {
    Outcome operator()(Item* a, Item* b) {
        cout << a << "\t" << b << "\t";
        return a->compete(b); // ��ʼ˫�ص���
    }
};

int main() {
    srand(time(0)); // ��ʼ�������������
    const int sz = 20;
    vector<Item*> v(sz*2);
    generate(v.begin(), v.end(), ItemGen()); // ���������Ʒ�����ƣ�
    transform(v.begin(), v.begin() + sz,
              v.begin() + sz,
              ostream_iterator<Outcome>(cout, "\n"),
              Compete()); // �Ƚ���Ʒ�����ƣ���������
    purge(v); // �����ڴ�
} ///:~
