//: C07:VectorInsertAndErase.cpp {-bor}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��vector�ġ��м䡱��������β����ɾ��Ԫ��
//{L} Noisy
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include "Noisy.h"
using namespace std;

int main() {
    vector<Noisy> v;
    v.reserve(11);
    cout << "��Ԥ��11��Ԫ�صĿռ�" << endl;

    // ���ɶ������vector
    generate_n(back_inserter(v), 10, NoisyGen());
    ostream_iterator<Noisy> out(cout, " ");
    cout << endl;
    copy(v.begin(), v.end(), out);

    // ��vector�м�λ�ò���Ԫ��
    cout << "����һ��Ԫ�أ�" << endl;
    vector<Noisy>::iterator it = v.begin() + v.size() / 2; // �ҵ��м�λ��
    v.insert(it, Noisy());
    cout << endl;
    copy(v.begin(), v.end(), out);

    // ɾ��Ԫ��
    cout << "\nɾ��һ��Ԫ�أ�" << endl;
    // ���ﲻ��ʹ��it��ǰ��ֵ���������¼���
    it = v.begin() + v.size() / 2;
    v.erase(it);
    cout << endl;
    copy(v.begin(), v.end(), out);
    cout << endl;
} ///:~
