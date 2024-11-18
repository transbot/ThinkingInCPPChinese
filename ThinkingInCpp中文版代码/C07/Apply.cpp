//: C07:Apply.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 使用简单的迭代
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

template<class Cont, class PtrMemFun>
void apply(Cont& c, PtrMemFun f) {
    typename Cont::iterator 
        it = c.begin();       // 获取容器的起始迭代器
    while(it != c.end()) {    // 遍历容器中的所有元素
        ((*it).*f)();         // 这是为当前元素调用成员函数的两种形式之一
        ++it;                 // 移动到下一个元素
    }
}


// 该类包含一个整数成员和一个成员函数g
class Z {
    int i;
public:
    Z(int ii) : i(ii) {}
    void g() { ++i; }
    
    // 重载<<操作符，用于输出Z对象
    friend ostream& operator<<(ostream& os, const Z& z) {
        return os << z.i;
    }
};

int main() {
    ostream_iterator<Z> out(cout, " ");
    vector<Z> vz;
    for(int i = 0; i < 10; i++)
        // 向vector添加10个Z对象，每个对象的i值从0到9
        vz.push_back(Z(i)); 
    
    // 使用copy函数将vector中的所有Z对象输出到控制台
    copy(vz.begin(), vz.end(), out);
    cout << endl;

    // 调用apply函数，为vector中的每个Z对象调用成员函数g
    // g的作用是递增i
    apply(vz, &Z::g);

    // 再次输出到控制台
    copy(vz.begin(), vz.end(), out);
} ///:~
