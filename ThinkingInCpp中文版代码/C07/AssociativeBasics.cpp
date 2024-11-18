//: C07:AssociativeBasics.cpp {-bor}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// set��map�Ļ�������
#include <cstddef>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include "Noisy.h"
using namespace std;

int main() {
    Noisy na[7];
    // ͨ�����캯��������na�е�Ԫ����ӵ�set
    set<Noisy> ns(na, na + sizeof na / sizeof(Noisy));
    Noisy n;
    ns.insert(n); // ������Noisy���͵�Ԫ��n����set
    cout << endl;

    // ʹ��set�ĳ�Ա����
    cout << "ns.count(n)= " << ns.count(n) << endl; // ���n��set�г��ֵĴ���
    if(ns.find(n) != ns.end()) // ����n�Ƿ������set��
        cout << "��ns�з�����n(" << n << ")" << endl;

    // ��ӡset�е�����Ԫ��
    copy(ns.begin(), ns.end(),
         ostream_iterator<Noisy>(cout, " "));
    cout << endl;
    cout << "\n-----------" << endl;

    // ʹ��map
    map<int, Noisy> nm;
    for(int i = 0; i < 10; i++)
        nm[i]; // �Զ�������ֵ�ԣ���Ϊi��ֵΪĬ�Ϲ����Noisy����
    cout << "\n-----------" << endl;

    // ��ӡmap�е����м�ֵ��
    for(size_t j = 0; j < nm.size(); j++)
        cout << "nm[" << j << "] = " << nm[j] << endl;
    cout << "\n-----------" << endl;

    // �����ֵ�ԣ���Ϊ10��ֵΪn
    nm[10] = n;
    cout << "\n-----------" << endl;

    // �����ֵ�ԣ���Ϊ47��ֵΪn
    nm.insert(make_pair(47, n));
    cout << "\n-----------" << endl;

    // ����10��11��map���Ƿ����
    cout << "\n nm.count(10)= " << nm.count(10) << endl;
    cout << "nm.count(11)= " << nm.count(11) << endl;

    // ���Ҽ�6��Ӧ��ֵ
    map<int, Noisy>::iterator it = nm.find(6);
    if(it != nm.end())
        cout << " nm��λ��6�е�ֵ��:" << (*it).second << endl;

    // ��ӡmap�е����м�ֵ��
    for(it = nm.begin(); it != nm.end(); it++)
        cout << (*it).first << ":" << (*it).second << ", ";
    cout << "\n-----------" << endl;
    return 0;
} ///:~