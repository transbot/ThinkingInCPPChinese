//: C07:Inserters.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示不同类型的迭代器插入器
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <iterator>
using namespace std;

int a[] = { 1, 3, 5, 7, 11, 13, 17, 19, 23 }; // 数组a

template<class Cont>
void frontInsertion(Cont& ci) { // 该模板函数在容器前端插入元素
    // 使用front_inserter将数组a的元素插入到容器ci的前端
    copy(a, a + sizeof(a)/sizeof(Cont::value_type), front_inserter(ci));
    copy(ci.begin(), ci.end(),  // 将容器ci的所有元素输出到控制台
        ostream_iterator<typename Cont::value_type>(cout, " "));
    cout << endl;
}

template<class Cont>
void backInsertion(Cont& ci) { // 该模板函数在容器后端（末端）插入元素
    // 使用back_inserter将数组a的元素插入到容器ci的后端（末端）
    copy(a, a + sizeof(a)/sizeof(Cont::value_type), back_inserter(ci));
    copy(ci.begin(), ci.end(),  // 将容器ci的所有元素输出到控制台
        ostream_iterator<typename Cont::value_type>(cout, " "));
    cout << endl;
}

template<class Cont>
void midInsertion(Cont& ci) { // 该模板函数在容器中间插入元素
    typename Cont::iterator it = ci.begin(); // 获取容器ci的起始迭代器
    ++it; ++it; ++it; // 迭代器it向前移动三个位置    
    // 使用inserter将数组a的部分元素插入到容器ci的中间位置
    copy(a, a + sizeof(a)/(sizeof(Cont::value_type) * 2), inserter(ci, it));    
    copy(ci.begin(), ci.end(), // 将容器ci的所有元素输出到控制台
         ostream_iterator<typename Cont::value_type>(cout, " "));
    cout << endl;
}

int main() {
    deque<int> di;
    list<int> li;
    vector<int> vi;

    // 不能对vector使用front_inserter()，
    // 因为vector不支持在前端高效插入元素（需要移动所有内容）
    frontInsertion(di);  // 在deque的前端插入元素
    frontInsertion(li);  // 在list的前端插入元素

    // 清空deque和list，以便重新插入元素
    di.clear();
    li.clear();
    
    backInsertion(vi);  // 在vector的后端插入元素
    backInsertion(di);  // 在deque的后端插入元素
    backInsertion(li);  // 在list的后端插入元素
    
    midInsertion(vi);   // 在vector的中间位置插入元素
    midInsertion(di);   // 在deque的中间位置插入元素
    midInsertion(li);   // 在list的中间位置插入元素
} ///:~
