/*
Modify CalcInventory.cpp so that it will find all
the objects that have a quantity that鈥檚 less than
a certain amount. Provide this amount as a command-line
argument, and use copy_if( ) and bind2nd( ) to create
the collection of values less than the target value.
*/

//: C06:CalcInventory.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
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
