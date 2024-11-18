//: C07:Swapping.cpp {-bor}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

//: C07:Swapping.cpp {-bor}
// 所有基本序列容器都支持交换
//{L} Noisy
#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>
#include "Noisy.h"
#include "PrintContainer.h"
using namespace std;
ostream_iterator<Noisy> out(cout, " ");

template<class Cont>
void testSwap(char* cname) {
    Cont c1, c2;
    generate_n(back_inserter(c1), 10, NoisyGen());
    generate_n(back_inserter(c2), 5, NoisyGen());
    cout << endl << cname << ":" << endl;
    print(c1, "c1");
    print(c2, "c2");
    cout << "\n 交换 " << cname << ":" << endl;
    c1.swap(c2);
    print(c1, "c1");
    print(c2, "c2");
}

int main() {
    testSwap<vector<Noisy>>("vector");
    testSwap<deque<Noisy>>("deque");
    testSwap<list<Noisy>>("list");
} ///:~
