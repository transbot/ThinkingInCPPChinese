//: C10:BuildBicycles.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
//{L} Bicycle

// ���������ģʽ
#include <cstddef>
#include <iostream>
#include <map>
#include <vector>
#include "Bicycle.h"
#include "../purge.h"
using namespace std;

// ͨ�����彨�������������г�
Bicycle* buildMeABike(
    BicycleTechnician& t,
    BicycleBuilder* builder
) {
    t.setBuilder(builder);
    t.construct();
    Bicycle* b = builder->getProduct();
    cout << "������һ��" << builder->getBikeName() << endl;
    return b;
}

int main() {
    // ����һЩ���г�����
    map<string, size_t> order;
    order["ɽ�س�"] = 2;
    order["���г�"] = 1;
    order["����"] = 3;

    // �������г�
    vector<Bicycle*> bikes;
    BicycleBuilder* m = new MountainBikeBuilder;
    BicycleBuilder* t = new TouringBikeBuilder;
    BicycleBuilder* r = new RacingBikeBuilder;
    BicycleTechnician tech;
    map<string, size_t>::iterator it = order.begin();
    while(it != order.end()) {
        BicycleBuilder* builder;
        if(it->first == "ɽ�س�") builder = m;
        else if(it->first == "���г�") builder = t;
        else if(it->first == "����") builder = r;
        for(size_t i = 0; i < it->second; ++i)
            bikes.push_back(buildMeABike(tech, builder));
        ++it;
    }
    delete m;
    delete t;
    delete r;

    // ��ʾ���
    for(size_t i = 0; i < bikes.size(); ++i)
        cout << "���г�: " << *bikes[i] << endl;
    purge(bikes);
}
/* �������:
������һ�����г�
������һ������
������һ������
������һ������
������һ��ɽ�س�
������һ��ɽ�س�
���г�: { ���� ���� ���� ������ ���� ���� ���� }
���г�: { ���� ���� ���� ���� ���� }
���г�: { ���� ���� ���� ���� ���� }
���г�: { ���� ���� ���� ���� ���� }
���г�: { ���� ���� ���� ������ ���� ���� ������ }
���г�: { ���� ���� ���� ������ ���� ���� ������ }
*/ ///:~
