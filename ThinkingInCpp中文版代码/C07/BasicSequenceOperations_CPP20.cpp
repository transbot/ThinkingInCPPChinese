//: C07:BasicSequenceOperations_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示所有基本序列容器都支持的操作
// 本程序对原书程序进行了修改，使之符合现代C++标准
// 主要改动包括：
/* 
1. 使用const和auto：
   在print函数中，使用const修饰容器参数，以防止不必要的修改。
   使用auto关键字来简化迭代器的声明。
2. 基于范围的for：
   使用for(const auto& item : c)来遍历容器，这在现代 C++ 中更加简洁和安全。
3. 类型别名：
   使用using关键字定义类型别名，使代码更清晰。
*/

#include <deque>
#include <iostream>
#include <list>
#include <vector>
using namespace std;

// 打印容器内容的模板函数
template<typename Container>
void print(const Container& c, const char* title = "") {
    cout << title << ':' << endl;
    if(c.empty()) {
        cout << "(empty)" << endl;
        return;
    }
    for(const auto& item : c) {
        cout << item << " ";
    }
    cout << endl;
    cout << "size() " << c.size() << " max_size() " << c.max_size() 
         << " front() " << c.front() << " back() " << c.back() << endl;
}

// 演示基本操作的模板函数
template<typename ContainerOfInt>
void basicOps(const char* s) {
    cout << "------- " << s << " -------" << endl;
    using Ci = ContainerOfInt;
    Ci c;
    print(c, "执行默认构造函数后的c");
    Ci c2(10, 1); // 10个元素，值全为1
    print(c2, "执行构造函数(10,1)后的c2");

    int ia[] = { 1, 3, 5, 7, 9 };
    const size_t IASZ = sizeof(ia) / sizeof(*ia);
    // 使用begin和end迭代器来初始化
    Ci c3(ia, ia + IASZ);
    print(c3, "执行构造函数(iter,iter)后的c3");
    Ci c4(c2); // 拷贝构造函数
    print(c4, "执行拷贝构造函数(c2)后的c4");
    c = c2;    // 赋值操作符
    print(c, "执行operator=c2后的c");
    c.assign(10, 2); // 10个元素，值全为2
    print(c, "执行assign(10, 2)后的c");
    // 使用begin和end迭代器来赋值
    c.assign(ia, ia + IASZ);
    print(c, "执行assign(iter, iter)后的c");
    cout << "使用逆序迭代器的c：" << endl;
    for(auto rit = c.rbegin(); rit != c.rend(); ++rit) {
        cout << *rit << " ";
    }
    cout << endl;
    c.resize(4);
    print(c, "执行resize(4)后的c");
    c.push_back(47);
    print(c, "执行push_back(47)后的c");
    c.pop_back();
    print(c, "执行pop_back()后的c");
    auto it = c.begin();
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
    auto it2 = it = c.begin();
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