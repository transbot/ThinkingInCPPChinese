//: C06:MemFun2.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 通过对象引用调用成员函数
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
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
    for(int i = 0; i < 50; i += 10)
        va.push_back(Angle(i));   // 得到0, 10, 20, 30, 40
    int x[] = { 1, 2, 3, 4, 5 };  // 准备用这些值乘以刚才的vector中的对应元素

    // 使用mem_fun_ref将Angle::mul成员函数适配为可调用对象，
    // 并传递给transform，对vector中每个Angle对象调用mul方法，
    // 将结果乘以对应的x值，并将结果输出。
    transform(va.begin(), va.end(), x,
              ostream_iterator<int>(cout, " "),
              mem_fun_ref(&Angle::mul));
    cout << endl;
    // 输出: 0 20 60 120 200
} ///:~
