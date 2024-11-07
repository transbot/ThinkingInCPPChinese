//: C06:BinderValue.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// “绑定”实参是可变的
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <cstdlib>
using namespace std;

// 该函数生成0-99的随机数。
// 随机性很差，参见本书中文版修改后的BinderValue_CPP20.cpp程序。
int boundedRand() { return rand() % 100; }

int main() {
    const int SZ = 20;

    // 应使用vector容器替换C风格数组，以提高代码的安全性、灵活性，
    // 并更符合现代 C++ 的编程风格。参见本书中文版修改后的BinderValue_CPP20.cpp程序。
    int a[SZ], b[SZ] = {0};

    // 生成20个随机数
    generate(a, a + SZ, boundedRand);

    // 在0-99中随便选择一个，作为结果值的上限
    int val = boundedRand();

    // 移除大于val的元素，剩余元素拷贝到b数组。
    // bind2nd已弃用，参见本书中文版修改后的BinderValue_CPP20.cpp程序。
    int* end = remove_copy_if(a, a + SZ, b, bind2nd(greater<int>(), val));
    
    // 对输出进行排序
    sort(a, a + SZ);
    sort(b, end);

    // 输出结果
    ostream_iterator<int> out(cout, " ");
    cout << "原始序列：" << endl;
    copy(a, a + SZ, out);
    cout << endl;

    cout << "小于等于" << val << "的值：" << endl;
    copy(b, end, out);
    cout << endl;
}
