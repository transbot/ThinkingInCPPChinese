//: C06:CopyInts4_lambda_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>

using namespace std;

int main() {
    int a[] = { 10, 20, 30 };
    const size_t SIZE = sizeof a / sizeof a[0];

    // 使用lambda表达式
    // 这是目前乃至未来很长一段时间的主流
    remove_copy_if(a, a + SIZE,
                  ostream_iterator<int>(cout, "\n"),
                  [](int x) { return x > 15; });

    // 注释：
    // - [](int x) { return x > 15; }是一个lambda表达式，它创建了一个匿名函数对象。
    // - x表示当前遍历到的元素。
    // - 返回x > 15的结果，即判断当前元素是否大于15。
    // - 因此，最终的效果是将数组a中不大于15的元素复制到输出流。
    // - 这种写法更加简洁直观。
}
