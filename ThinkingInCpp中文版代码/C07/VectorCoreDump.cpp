//: C07:VectorCoreDump.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 使迭代器失效
#include <iterator>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vi(10, 0);
    ostream_iterator<int> out(cout, " ");
    vector<int>::iterator i = vi.begin();
    *i = 47;
    copy(vi.begin(), vi.end(), out);
    cout << endl;
    // 强制其移动内存（也可以简单地添加足够多的对象）
    vi.resize(vi.capacity() + 1);
    // 此时i指向错误的内存：
    *i = 48; // 访问违例
    copy(vi.begin(), vi.end(), out); // vi[0]没有变化
} ///:~
