//: C06:SortedSearchTest.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
// ������������Χ�ڽ���������
// NString

// ������������Χ��ִ�С����ҡ�
#include <algorithm>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>
#include "NString.h"
#include "PrintSequence.h"
#include "../require.h"
using namespace std;

int main(int argc, char* argv[]) {
    typedef vector<NString>::iterator sit;  // �������������
    const char* fname = "Test.txt";         // Ĭ���ļ���
    if(argc > 1) fname = argv[1];           // ����ṩ��������ʵ�Σ���ʹ���ṩ���ļ���
    ifstream in(fname);  // ���ļ�
    assure(in, fname);   // ȷ���ļ��ɹ���
    srand(time(0));      // ��ʼ�������������
    cout.setf(ios::boolalpha);  // ���������ʽΪ����ֵ
    vector<NString> original;   // ����������ڴ洢ԭʼ����
    copy(istream_iterator<string>(in),  // ���ļ��ж�ȡ����
         istream_iterator<string>(), back_inserter(original)); // �����ݿ�����ԭʼ������
    require(original.size() >= 4, "������Ҫ4��Ԫ��"); // ȷ��ԭʼ�������ٰ���4��Ԫ��

    // ����ԭʼ�����Ŀ���v����������СΪԭʼ������һ�������v
    vector<NString> v(original.begin(), original.end()), w(original.size() / 2);

    sort(v.begin(), v.end());           // ������v��������
    print(v.begin(), v.end(), "sort");  // ��ӡ����������v

    v = original;  // �ָ�����vΪԭʼ����
    stable_sort(v.begin(), v.end());  // ������v�����ȶ����򣨱���ԭ�������˳��
    print(v.begin(), v.end(), "stable_sort");  // ��ӡ�ȶ�����������v

    v = original;  // �ָ�����vΪԭʼ����
    sit it = v.begin(), it2;  // ���������it��it2
    // ��������it�ƶ����м�λ��
    for(size_t i = 0; i < v.size() / 2; i++)
        ++it;
    partial_sort(v.begin(), it, v.end());  // ������v��ǰ�벿�ֽ��в�������
    cout << "middle = " << *it << endl;    // ����м�λ�õ�Ԫ��
    print(v.begin(), v.end(), "partial_sort");  // ��ӡ��������������v

    v = original;  // �ָ�����vΪԭʼ����
    // ��������it�ƶ����ķ�֮һλ��
    it = v.begin();
    for(size_t i = 0; i < v.size() / 4; i++)
        ++it;

    // Դ��Χ�е�Ԫ������Ŀ�귶Χ
    // ������v��ǰ�ķ�֮һ���ֽ��в������򲢿���������w
    partial_sort_copy(v.begin(), it, w.begin(), w.end());
    print(w.begin(), w.end(), "partial_sort_copy");   // ��ӡ�������򲢿����������w

    // Ŀ�귶Χ�ռ䲻��
    // ������v��ȫ�����ݽ��в������򲢿���������w
    partial_sort_copy(v.begin(), v.end(), w.begin(), w.end());
    print(w.begin(), w.end(), "w partial_sort_copy");  // ��ӡ�������򲢿����������w

    // ��֤�����������У�����v���ֲ���
    assert(v == original);

    // ������v���в�������ʹ��*it��Ϊ��n����С��Ԫ��
    nth_element(v.begin(), it, v.end());
    cout << "The nth_element = " << *it << endl;  // �����n����С��Ԫ��
    print(v.begin(), v.end(), "nth_element");     // ��ӡ��������������v

    string f = original[rand() % original.size()];  // ���ѡ��һ��Ԫ��f
    // ������v�н��ж�����Ҳ�������
    cout << "�������: "
         << binary_search(v.begin(), v.end(), f) << endl;

    sort(v.begin(), v.end());  // ������v��������
    it = lower_bound(v.begin(), v.end(), f);   // ���ҵ�һ����С��f��Ԫ�ص�λ��
    it2 = upper_bound(v.begin(), v.end(), f);  // ���ҵ�һ������f��Ԫ�ص�λ��
    print(it, it2, "�ҵ��ķ�Χ");  // ��ӡ�ҵ��ķ�Χ

    pair<sit, sit> ip = equal_range(v.begin(), v.end(), f);  // ����f�ĵ�ֵ��Χ
    print(ip.first, ip.second, "equal_range");               // ��ӡ��ֵ��Χ
} ///:~