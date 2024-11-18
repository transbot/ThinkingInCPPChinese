//: C07:BasicSequenceOperations.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示所有基本序列容器都支持的操作
#include <deque>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

template<typename Container>
void print(Container& c, char* title = "") {
    cout << title << ':' << endl;
    if(c.empty()) {
        cout << "(empty)" << endl;
        return;
    }
    typename Container::iterator it;
    for(it = c.begin(); it != c.end(); it++)
        cout << *it << " ";
    cout << endl;
    cout << "size() " << c.size() << " max_size() " 
         << c.max_size() << " front() " << c.front()
         << " back() " << c.back() << endl;
}

template<typename ContainerOfInt>
void basicOps(char* s) {
    cout << "------- " << s << " -------" << endl;
    typedef ContainerOfInt Ci;
    Ci c;
    print(c, "执行默认构造函数后的c");
    Ci c2(10, 1); // 10个元素，值全为1
    print(c2, "执行构造函数(10,1)后的c2");
    
    int ia[] = { 1, 3, 5, 7, 9 };
    const int IASZ = sizeof(ia)/sizeof(*ia);
    // 使用begin和end迭代器来初始化
    Ci c3(ia, ia + IASZ);
    print(c3, "执行构造函数(iter,iter)后的c3");
    Ci c4(c2); // 拷贝构造函数
    print(c4, "执行拷贝构造函数(c2)后的c4");
    c = c2;    // 赋值操作符
    print(c, "执行operator=c2后的c");
    c.assign(10, 2); // 10个元素，值全为2
    print(c, "执行assign(10, 2)后的c");
    // 使用开始和结束迭代器赋值
    c.assign(ia, ia + IASZ);
    print(c, "执行assign(iter, iter)后的c");
    cout << "使用逆序迭代器的c：" << endl;
    typename Ci::reverse_iterator rit = c.rbegin();
    while(rit != c.rend())
        cout << *rit++ << " ";
    cout << endl;
    c.resize(4);
    print(c, "执行resize(4)后的c");
    c.push_back(47);
    print(c, "执行push_back(47)后的c");
    c.pop_back();
    print(c, "执行pop_back()后的c");
    typename Ci::iterator it = c.begin();
    ++it; ++it;
    c.insert(it, 74);
    print(c, "执行insert(it, 74)后的c");
    it = c.begin();
    ++it;
    c.insert(it, 3, 96);
    print(c, "执行insert(it, 3, 96)后的c");
    it = c.begin();
    ++it;
    c.insert(it, c3.begin(), c3.end());
    print(c, "执行insert(it, c3.begin(), c3.end())后的c");
    it = c.begin();
    ++it;
    c.erase(it);
    print(c, "执行erase(it)后的c");
    typename Ci::iterator it2 = it = c.begin();
    ++it;
    ++it2; ++it2; ++it2; ++it2; ++it2;
    c.erase(it, it2);
    print(c, "执行erase(it, it2)后的c");
    c.swap(c2);
    print(c, "执行swap(c2)后的c");
    c.clear();
    print(c, "执行clear()后的c");
}

int main() {
    basicOps<vector<int>>("vector");
    basicOps<deque<int>>("deque");
    basicOps<list<int>>("list");
} ///:~
