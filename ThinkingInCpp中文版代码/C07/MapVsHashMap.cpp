//: C07:MapVsHashMap.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// hash_mapͷ�ļ����Ǳ�׼C++ STL��һ���֣�
// ����һ����չ��ֻ��SGI STL���ṩ��������dmc���а��У���
// �����ֶ������Щͷ�ļ���
// hash_map�����ִ�C++���Ƴ���Ӧ�滻Ϊunordered_map��
//{-bor}{-msc}{-g++}{-mwcc} 
#include <hash_map>
#include <iostream>
#include <map>
#include <ctime>
using namespace std;

int main() {
    hash_map<int, int> hm;
    map<int, int> m;
    clock_t ticks = clock();
    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 1000; j++)
            m.insert(make_pair(j,j));
    cout << "map����: " << clock() - ticks << endl;

    ticks = clock();
    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 1000; j++) 
            hm.insert(make_pair(j,j));
    cout << "hash_map����: " << clock() - ticks << endl;

    ticks = clock(); 
    for(int i = 0; i < 100; i++) 
        for(int j = 0; j < 1000; j++) 
            m[j]; 
    cout << "map::operator[] ����: " << clock() - ticks << endl;

    ticks = clock(); 
    for(int i = 0; i < 100; i++) 
        for(int j = 0; j < 1000; j++) 
            hm[j]; 
    cout << "hash_map::operator[] ����: " << clock() - ticks << endl;

    ticks = clock(); 
    for(int i = 0; i < 100; i++) 
        for(int j = 0; j < 1000; j++) 
            m.find(j); 
    cout << "map::find() ����: " << clock() - ticks << endl;

    ticks = clock(); 
    for(int i = 0; i < 100; i++) 
        for(int j = 0; j < 1000; j++) 
            hm.find(j); 
    cout << "hash_map::find() ����: " << clock() - ticks << endl; 
} 
///:~
