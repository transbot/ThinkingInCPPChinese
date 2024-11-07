//: C06:CopyInts4_bind_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
#include <iterator>
using namespace std;

// std::bind是C++11引入的一个更强大的函数绑定工具，
// 可以绑定任何可调用对象的参数，并且支持更复杂的绑定需求。
// 不过，在这么简单的一个例子中，它显得有点“大材小用”。
// 因此，建议换成使用lambda表达式（参见另一个例子）。
int main() {
    int a[] = { 10, 20, 30 };
    const size_t SIZE = sizeof a / sizeof a[0];

    // 使用std::bind将15绑定为greater<int>的第二个实参
    remove_copy_if(a, a + SIZE,
                  ostream_iterator<int>(cout, "\n"),
                  bind(greater<int>(), placeholders::_1, 15));

    // 注释：
    // - bind(greater<int>(), placeholders::_1, 15)创建了一个新的可调用对象。
    // - placeholders::_1表示将传入remove_copy_if的第一个实参绑定到greater<int>的第一个参数。
    // - 15直接绑定到greater<int>的第二个实参。
    // - 因此，最终的效果是将数组a中不大于15的元素复制到输出流。
}