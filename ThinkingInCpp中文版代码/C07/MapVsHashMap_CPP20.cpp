//: C07:MapVsHashMap_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// �Ա�map��unordered_map�ĸ��ֲ������ٶ�
#include <unordered_map>
#include <iostream>
#include <map>
#include <ctime>
using namespace std;

int main() {
    unordered_map<int, int> hm;
    map<int, int> m;
    clock_t ticks = clock();
    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 1000; j++)
            m.insert(make_pair(j, j));
    cout << "map����: " << clock() - ticks << " ticks" << endl;

    ticks = clock();
    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 1000; j++) 
            hm.insert(make_pair(j, j));
    cout << "unordered_map����: " << clock() - ticks << " ticks" << endl;

    ticks = clock(); 
    for(int i = 0; i < 100; i++) 
        for(int j = 0; j < 1000; j++) 
            m[j]; 
    cout << "map::operator[] ����: " << clock() - ticks << " ticks" << endl;

    ticks = clock(); 
    for(int i = 0; i < 100; i++) 
        for(int j = 0; j < 1000; j++) 
            hm[j]; 
    cout << "unordered_map::operator[] ����: " << clock() - ticks << " ticks" << endl;

    ticks = clock(); 
    for(int i = 0; i < 100; i++) 
        for(int j = 0; j < 1000; j++) {
            auto it = m.find(j); // ���񷵻�ֵ
            (void)it; // ʹ�÷���ֵ����������
        }
    cout << "map::find() ����: " << clock() - ticks << " ticks" << endl;

    ticks = clock(); 
    for(int i = 0; i < 100; i++) 
        for(int j = 0; j < 1000; j++) {
            auto it = hm.find(j); // ���񷵻�ֵ
            (void)it; // ʹ�÷���ֵ����������
        }
    cout << "unordered_map::find() ����: " << clock() - ticks << " ticks" << endl; 
}