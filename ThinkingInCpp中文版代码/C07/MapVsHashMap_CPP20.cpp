//: C07:MapVsHashMap_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 对比map和unordered_map的各种操作的速度
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
    cout << "map插入: " << clock() - ticks << " ticks" << endl;

    ticks = clock();
    for(int i = 0; i < 100; i++)
        for(int j = 0; j < 1000; j++) 
            hm.insert(make_pair(j, j));
    cout << "unordered_map插入: " << clock() - ticks << " ticks" << endl;

    ticks = clock(); 
    for(int i = 0; i < 100; i++) 
        for(int j = 0; j < 1000; j++) 
            m[j]; 
    cout << "map::operator[] 查找: " << clock() - ticks << " ticks" << endl;

    ticks = clock(); 
    for(int i = 0; i < 100; i++) 
        for(int j = 0; j < 1000; j++) 
            hm[j]; 
    cout << "unordered_map::operator[] 查找: " << clock() - ticks << " ticks" << endl;

    ticks = clock(); 
    for(int i = 0; i < 100; i++) 
        for(int j = 0; j < 1000; j++) {
            auto it = m.find(j); // 捕获返回值
            (void)it; // 使用返回值以消除警告
        }
    cout << "map::find() 查找: " << clock() - ticks << " ticks" << endl;

    ticks = clock(); 
    for(int i = 0; i < 100; i++) 
        for(int j = 0; j < 1000; j++) {
            auto it = hm.find(j); // 捕获返回值
            (void)it; // 使用返回值以消除警告
        }
    cout << "unordered_map::find() 查找: " << clock() - ticks << " ticks" << endl; 
}