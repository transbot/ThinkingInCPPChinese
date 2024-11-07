/*
�޸�CalcInventory.cpp���ҳ�����ĳ���ض����������ж��󡣽���������Ϊ������ʵ���ṩ��
��ʹ��copy_if()��bind2nd()����С��Ŀ��ֵ��ֵ���ϡ�
*/

//: C06:CalcInventory.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
// More use of for_each().
#include <algorithm>
#include <ctime>
#include <vector>
#include <iterator>
#include <numeric>
#include "Inventory.h"
#include "PrintSequence.h"
using namespace std;

// To calculate inventory totals:
class InvAccum {
  int quantity;
  int value;
public:
  InvAccum() : quantity(0), value(0) {}
  void operator()(const Inventory& inv) {
    quantity += inv.getQuantity();
    value += inv.getQuantity() * inv.getValue();
  }
  friend ostream&
  operator<<(ostream& os, const InvAccum& ia) {
    return os << "total quantity: " << ia.quantity
              << ", total value: " << ia.value;
  }
};

int main() {
  vector<Inventory> vi;
  srand(time(0));  // Randomize
  generate_n(back_inserter(vi), 15, InvenGen());
  print(vi.begin(), vi.end(), "vi");
  //InvAccum ia = for_each(vi.begin(),vi.end(), InvAccum());
  //cout << ia << endl;

  std::cout << "Enter quaintity limit: ";
  int quaintity = 0;
  std::cin >> quaintity;

  vector<Inventory> vi_limited;
  std::copy_if(vi.begin(), vi.end(), std::back_inserter(vi_limited),
		  [quaintity](const Inventory& i) { return i.quantity < quaintity; }
  );

  print(vi_limited.begin(), vi_limited.end(), "vi_limited");

}
