//: C07:MultiSet1.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾmultiset����Ϊ
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <set>
using namespace std;

class X {
    char c; // ���ڱȽϵ��ַ�
    int i;  // �����ڱȽϵ�����
    // ����ҪĬ�Ϲ��캯���͸�ֵ��������operator=��
    X();
    X& operator=(const X&);

    // һ����Ҫ�������캯��������������ʹ���Զ����ɵİ汾��
public:
    X(char cc, int ii) : c(cc), i(ii) {}
    // ע�⣬����Ҫoperator==
    friend bool operator<(const X& x, const X& y) {
        return x.c < y.c; // �Ƚ��ַ�c
    }
    friend ostream& operator<<(ostream& os, X x) {
        return os << x.c << ":" << x.i; // ����ַ�c������i
    }
};

class Xgen {
    static int i; 
    enum { SPAN = 6 }; // �Ӷ��ٸ��ַ���ѡ�񣨴�'A'��'F'��
public:
    X operator()() {
        char c = 'A' + rand() % SPAN; // ��������ַ�
        return X(c, i++); // ����һ���µ�X���� 
    }
};

int Xgen::i = 0; // ��ʼ����̬��Ա����

typedef multiset<X> Xmset;
typedef Xmset::const_iterator Xmit;

int main() {
    Xmset mset;
    // ��X�Ķ��������Ϊmset��multiset
    srand(time(0)); // �����
    // ����25�����X����
    generate_n(inserter(mset, mset.begin()), 25, Xgen());

    // ��mset��ʼ��һ����ͨ��set
    set<X> unique(mset.begin(), mset.end());
    copy(unique.begin(), unique.end(),
         ostream_iterator<X>(cout, " "));
    cout << "\n----" << endl;

    // ����Ψһֵ
    for(set<X>::iterator i = unique.begin();
        i != unique.end(); i++) {
        pair<Xmit, Xmit> p = mset.equal_range(*i);
        copy(p.first, p.second,
             ostream_iterator<X>(cout, " ")); // ��� unique �е�����Ԫ��
        cout << endl;
    }
} ///:~
