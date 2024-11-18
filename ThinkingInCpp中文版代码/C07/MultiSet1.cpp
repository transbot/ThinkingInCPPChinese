//: C07:MultiSet1.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示multiset的行为
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <set>
using namespace std;

class X {
    char c; // 用于比较的字符
    int i;  // 不用于比较的整数
    // 不需要默认构造函数和赋值操作符（operator=）
    X();
    X& operator=(const X&);

    // 一般需要拷贝构造函数（但本例可以使用自动生成的版本）
public:
    X(char cc, int ii) : c(cc), i(ii) {}
    // 注意，不需要operator==
    friend bool operator<(const X& x, const X& y) {
        return x.c < y.c; // 比较字符c
    }
    friend ostream& operator<<(ostream& os, X x) {
        return os << x.c << ":" << x.i; // 输出字符c和整数i
    }
};

class Xgen {
    static int i; 
    enum { SPAN = 6 }; // 从多少个字符中选择（从'A'到'F'）
public:
    X operator()() {
        char c = 'A' + rand() % SPAN; // 随机生成字符
        return X(c, i++); // 返回一个新的X对象 
    }
};

int Xgen::i = 0; // 初始化静态成员变量

typedef multiset<X> Xmset;
typedef Xmset::const_iterator Xmit;

int main() {
    Xmset mset;
    // 用X的对象填充名为mset的multiset
    srand(time(0)); // 随机化
    // 生成25个随机X对象
    generate_n(inserter(mset, mset.begin()), 25, Xgen());

    // 从mset初始化一个普通的set
    set<X> unique(mset.begin(), mset.end());
    copy(unique.begin(), unique.end(),
         ostream_iterator<X>(cout, " "));
    cout << "\n----" << endl;

    // 遍历唯一值
    for(set<X>::iterator i = unique.begin();
        i != unique.end(); i++) {
        pair<Xmit, Xmit> p = mset.equal_range(*i);
        copy(p.first, p.second,
             ostream_iterator<X>(cout, " ")); // 输出 unique 中的所有元素
        cout << endl;
    }
} ///:~
