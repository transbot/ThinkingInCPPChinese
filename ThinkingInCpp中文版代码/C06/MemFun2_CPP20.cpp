//: C06:MemFun2_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示使用两种技术来替代过时的mem_fun_ref：
// std::mem_fn和lambda表达式。
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Angle {
    int degrees;
public:
    Angle(int deg) : degrees(deg) {}
    int mul(int times) { return degrees *= times; }    
};

int main() {
    vector<Angle> va;
    for (int i = 0; i < 50; i += 10)
        va.push_back(Angle(i));   // 得到0, 10, 20, 30, 40
    int x[] = { 1, 2, 3, 4, 5 };  // 准备用这些值乘以刚才的vector中的对应元素

    // 使用lambda表达式
    cout << "lambda表达式结果: ";
    transform(va.begin(), va.end(), x, ostream_iterator<int>(cout, " "),
              [](Angle& angle, int times) { return angle.mul(times); });
    cout << endl;
    // 输出: 0 20 60 120 200

    // 使用std::mem_fn    
    vector<Angle> vb;
    for (int i = 0; i < 50; i += 10)
        vb.push_back(Angle(i));   // 得到0, 10, 20, 30, 40
    cout << "std::mem_fn结果: ";
    transform(vb.begin(), vb.end(), x,
              ostream_iterator<int>(cout, " "),
              mem_fn(&Angle::mul));
    cout << endl;
    // 输出: 0 20 60 120 200

    return 0;
}