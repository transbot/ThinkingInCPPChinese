//: C07:Swapping.cpp {-bor}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

//: C07:Swapping.cpp {-bor}
// ���л�������������֧�ֽ���
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
    cout << "\n ���� " << cname << ":" << endl;
    c1.swap(c2);
    print(c1, "c1");
    print(c2, "c2");
}

int main() {
    testSwap<vector<Noisy>>("vector");
    testSwap<deque<Noisy>>("deque");
    testSwap<list<Noisy>>("list");
} ///:~
