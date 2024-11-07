//: C06:Inventory.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <cstdlib>
using std::rand;

class Inventory {
    char item;     // ����
    int quantity;  // ����
    int value;     // ����
public:
    Inventory(char it, int quant, int val)
    : item(it), quantity(quant), value(val) {}
    // ���Խ��ܸ��ϸ�ֵ�������Ϳ������캯��
    char getItem() const { return item; }
    int getQuantity() const { return quantity; }
    void setQuantity(int q) { quantity = q; }
    int getValue() const { return value; }
    void setValue(int val) { value = val; }
    friend std::ostream& operator<<(std::ostream& os, const Inventory& inv) {
        return os << inv.item << ": " << "���� " << inv.quantity 
                  << ", ���� " << inv.value;
    }
};

// ������
struct InvenGen {
    Inventory operator()() {
        static char c = 'a';
        int q = rand() % 100;
        int v = rand() % 500;
        return Inventory(c++, q, v);
    }
};
#endif // INVENTORY_H  ///:~
