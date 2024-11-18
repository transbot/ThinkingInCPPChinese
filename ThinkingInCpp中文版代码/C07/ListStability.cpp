//: C07:ListStability.cpp {-bor}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// list�е�Ԫ�ز����Ĵ��ƶ�
//{L} Noisy
#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include "Noisy.h"
using namespace std;

int main() {
    list<Noisy> l;
    ostream_iterator<Noisy> out(cout, " ");
    generate_n(back_inserter(l), 25, NoisyGen());
    cout << "\n ��ӡlist��" << endl;
    copy(l.begin(), l.end(), out);
    cout << "\n ��תlist��" << endl;
    l.reverse();
    copy(l.begin(), l.end(), out);
    cout << "\n ����list��" << endl;
    l.sort();
    copy(l.begin(), l.end(), out);
    cout << "\n ��������Ԫ�أ�" << endl;
    list<Noisy>::iterator it1, it2;
    it1 = it2 = l.begin();
    ++it2;
    swap(*it1, *it2);
    cout << endl;
    copy(l.begin(), l.end(), out);
    cout << "\n ʹ�÷���reverse()������" << endl;
    reverse(l.begin(), l.end());
    cout << endl;
    copy(l.begin(), l.end(), out);
    cout << "\n ����" << endl;
} ///:~
