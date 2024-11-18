//: C08:Recycle2.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
//{L} Trash

// ʹ��map������������
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <typeinfo>
#include <utility>
#include <vector>
#include "Trash.h"
#include "../purge.h"
using namespace std;

// type_infoָ��ıȽ���
struct TInfoLess {
    bool operator()(const type_info* t1, const type_info* t2) const {
        return t1->before(*t2);
    }
};

typedef map<const type_info*, vector<Trash*>, TInfoLess> TrashMap;

// �������������������ܼ�ֵ
void sumValue(const TrashMap::value_type& p, ostream& os) {
    vector<Trash*>::const_iterator tally = p.second.begin();
    float val = 0;
    while (tally != p.second.end()) {
        val += (*tally)->weight() * (*tally)->value();
        os << p.first->name() // type_info::name()
           << " ������ = " << (*tally)->weight() << endl;
        ++tally;
    }
    os << "�ܼ�ֵ = " << val << endl;
}

int main() {
    srand(time(0)); // ��ʼ�������������

    // ������������
    TrashMap bin;
    for (int i = 0; i < 30; i++) {
        Trash* tp;
        switch (rand() % 3) {
            case 0: tp = new Aluminum((rand() % 1000) / 10.0); break;
            case 1: tp = new Paper((rand() % 1000) / 10.0); break;
            case 2: tp = new Glass((rand() % 1000) / 10.0); break;
        }
        bin[&typeid(*tp)].push_back(tp);
    }

    // ��ӡ������ÿ����������Ϣ
    for (TrashMap::iterator p = bin.begin(); p != bin.end(); ++p) {
        sumValue(*p, cout);
        purge(p->second);
    }
} ///:~
