//: C07:ListVsSet.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// �Ƚ�list��set������
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include "PrintContainer.h"
using namespace std;

class Obj {
    int a[20]; // Ϊ��ռ�ö���ռ�
    int val;

public:
    Obj() : val(rand() % 500) {}
    friend bool operator<(const Obj& a, const Obj& b) {
        return a.val < b.val;
    }
    friend bool operator==(const Obj& a, const Obj& b) {
        return a.val == b.val;
    }
    friend ostream& operator<<(ostream& os, const Obj& a) {
        return os << a.val;
    }
};

struct ObjGen {
    Obj operator()() { return Obj(); }
};

int main() {
    const int SZ = 5000;
    srand(time(0));
    list<Obj> lo;

    clock_t ticks = clock();
    generate_n(back_inserter(lo), SZ, ObjGen());
    lo.sort();
    lo.unique();
    cout << "list: " << clock() - ticks << endl;

    set<Obj> so;
    ticks = clock();
    generate_n(inserter(so, so.begin()), SZ, ObjGen());
    cout << "set: " << clock() - ticks << endl;

    print(lo);
    print(so);
} ///:~
