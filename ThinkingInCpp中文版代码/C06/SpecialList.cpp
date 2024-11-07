//: C06:SpecialList.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ʹ��transform()�ĵڶ����汾
#include <algorithm>
#include <ctime>
#include <vector>
#include "Inventory.h"
#include "PrintSequence.h"
using namespace std;

struct Discounter {
    Inventory operator()(const Inventory& inv, float discount) {
        return Inventory(inv.getItem(), inv.getQuantity(),
                         int(inv.getValue() * (1 - discount)));
    }
};

struct DiscGen {
    float operator()() {
        float r = float(rand() % 10);
        return r / 100.0;
    }
};

int main() {
    vector<Inventory> vi;
    srand(time(0)); // �����
    generate_n(back_inserter(vi), 15, InvenGen());
    print(vi.begin(), vi.end(), "vi");

    vector<float> disc;
    generate_n(back_inserter(disc), 15, DiscGen());
    print(disc.begin(), disc.end(), "�ۿۣ�");

    vector<Inventory> discounted;
    transform(vi.begin(), vi.end(), disc.begin(),
              back_inserter(discounted), Discounter());
    print(discounted.begin(), discounted.end(), "���ۺ�");
} ///:~
