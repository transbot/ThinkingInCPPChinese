//: C06:CalcInventory.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// for_each()�ĸ�������
#include <algorithm>
#include <ctime>
#include <vector>
#include "Inventory.h"
#include "PrintSequence.h"
using namespace std;

// ���������������ܼ۸�
class InvAccum {
    int quantity;
    int value;
public:
    InvAccum() : quantity(0), value(0) {}
    void operator()(const Inventory& inv) {
        quantity += inv.getQuantity();
        value += inv.getQuantity() * inv.getValue();
    }
    friend ostream& operator<<(ostream& os, const InvAccum& ia) {
        return os << "������: " << ia.quantity << ", �ܼ۸�: " << ia.value;
    }
};

int main() {
    vector<Inventory> vi;
    srand(time(0)); // �����
    generate_n(back_inserter(vi), 15, InvenGen());
    print(vi.begin(), vi.end(), "vi");
    InvAccum ia = for_each(vi.begin(), vi.end(), InvAccum());
    cout << ia << endl;
} ///:~
