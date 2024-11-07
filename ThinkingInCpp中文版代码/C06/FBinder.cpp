//: C06:FBinder.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 绑定器（binder）不限于生成谓词
//{L} Generators
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
#include "Generators.h"
using namespace std;

int main() {
    ostream_iterator<int> out(cout," ");
    vector<int> v(15);
    srand(time(0));  // 随机化
    generate(v.begin(), v.end(), URandGen(20));

    // 输出原始vector
    copy(v.begin(), v.end(), out);
    cout << endl;
    
    // 每个元素乘以10
    transform(v.begin(), v.end(), v.begin(), bind2nd(multiplies<int>(), 10));
    // 上面这个语句不符合现代C++标准，应替换为使用lambda表达式：
    // transform(v.begin(), v.end(), v.begin(), [](int x) { return x * 10; });
  
    // 输出结果vector
    copy(v.begin(), v.end(), out);
} ///:~
