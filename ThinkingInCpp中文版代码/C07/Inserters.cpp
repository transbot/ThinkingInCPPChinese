//: C07:Inserters.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾ��ͬ���͵ĵ�����������
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <iterator>
using namespace std;

int a[] = { 1, 3, 5, 7, 11, 13, 17, 19, 23 }; // ����a

template<class Cont>
void frontInsertion(Cont& ci) { // ��ģ�庯��������ǰ�˲���Ԫ��
    // ʹ��front_inserter������a��Ԫ�ز��뵽����ci��ǰ��
    copy(a, a + sizeof(a)/sizeof(Cont::value_type), front_inserter(ci));
    copy(ci.begin(), ci.end(),  // ������ci������Ԫ�����������̨
        ostream_iterator<typename Cont::value_type>(cout, " "));
    cout << endl;
}

template<class Cont>
void backInsertion(Cont& ci) { // ��ģ�庯����������ˣ�ĩ�ˣ�����Ԫ��
    // ʹ��back_inserter������a��Ԫ�ز��뵽����ci�ĺ�ˣ�ĩ�ˣ�
    copy(a, a + sizeof(a)/sizeof(Cont::value_type), back_inserter(ci));
    copy(ci.begin(), ci.end(),  // ������ci������Ԫ�����������̨
        ostream_iterator<typename Cont::value_type>(cout, " "));
    cout << endl;
}

template<class Cont>
void midInsertion(Cont& ci) { // ��ģ�庯���������м����Ԫ��
    typename Cont::iterator it = ci.begin(); // ��ȡ����ci����ʼ������
    ++it; ++it; ++it; // ������it��ǰ�ƶ�����λ��    
    // ʹ��inserter������a�Ĳ���Ԫ�ز��뵽����ci���м�λ��
    copy(a, a + sizeof(a)/(sizeof(Cont::value_type) * 2), inserter(ci, it));    
    copy(ci.begin(), ci.end(), // ������ci������Ԫ�����������̨
         ostream_iterator<typename Cont::value_type>(cout, " "));
    cout << endl;
}

int main() {
    deque<int> di;
    list<int> li;
    vector<int> vi;

    // ���ܶ�vectorʹ��front_inserter()��
    // ��Ϊvector��֧����ǰ�˸�Ч����Ԫ�أ���Ҫ�ƶ��������ݣ�
    frontInsertion(di);  // ��deque��ǰ�˲���Ԫ��
    frontInsertion(li);  // ��list��ǰ�˲���Ԫ��

    // ���deque��list���Ա����²���Ԫ��
    di.clear();
    li.clear();
    
    backInsertion(vi);  // ��vector�ĺ�˲���Ԫ��
    backInsertion(di);  // ��deque�ĺ�˲���Ԫ��
    backInsertion(li);  // ��list�ĺ�˲���Ԫ��
    
    midInsertion(vi);   // ��vector���м�λ�ò���Ԫ��
    midInsertion(di);   // ��deque���м�λ�ò���Ԫ��
    midInsertion(li);   // ��list���м�λ�ò���Ԫ��
} ///:~
