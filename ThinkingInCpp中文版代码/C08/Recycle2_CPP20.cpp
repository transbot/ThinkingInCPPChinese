//: C08:Recycle2_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
//{L} Trash

// ʹ��map������������
// �޸���ԭ�����ʹ������ָ���������������������ڡ�
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <memory>
#include <typeinfo>
#include <vector>
#include "Trash.h"
using namespace std;

// type_infoָ��ıȽ���
struct TInfoLess {
    bool operator()(const type_info* t1, const type_info* t2) const {
        return t1->before(*t2);
    }
};

typedef map<const type_info*, vector<unique_ptr<Trash>>, TInfoLess> TrashMap;

// �������������������ܼ�ֵ
void sumValue(const TrashMap::value_type& p, ostream& os) {
    float val = 0;
    for (const auto& trash : p.second) {
        val += trash->weight() * trash->value();
        os << p.first->name() // type_info::name()
           << " ������ = " << trash->weight() << endl;
    }
    os << "�ܼ�ֵ = " << val << endl;
}

int main() {
    srand(static_cast<unsigned>(time(0))); // ��ʼ�������������

    // ������������
    TrashMap bin;
    for (int i = 0; i < 30; i++) {
        unique_ptr<Trash> tp;
        switch (rand() % 3) {
            case 0: tp = make_unique<Aluminum>(static_cast<float>((rand() % 1000) / 10.0)); break;
            case 1: tp = make_unique<Paper>(static_cast<float>((rand() % 1000) / 10.0)); break;
            case 2: tp = make_unique<Glass>(static_cast<float>((rand() % 1000) / 10.0)); break;
        }
        // ��unique_ptrת�Ƶ�vector�У�ȷ������Ȩת�ơ�
        bin[&typeid(*tp)].push_back(move(tp));
    }

    // ��ӡ������ÿ����������Ϣ
    for (const auto& p : bin) {
        sumValue(p, cout);
    }

    return 0;
} ///:~