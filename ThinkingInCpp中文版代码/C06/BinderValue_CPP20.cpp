//: C06:BinderValue_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 对原版程序的改动：
// - 在boundedRand()中，使用了随机性、可定制性和可移植性更佳的随机数生成器
// - 使用lambda表达式替换过时的bind2nd
// - 使用vector替换了C风格的数组
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

using namespace std;

// 该函数生成0-99的随机数，使用更现代的随机数生成器
int boundedRand() {
    // 使用Mersenne Twister作为随机数引擎
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 99);
    return dis(gen);
}

int main() {
    const int SZ = 20;
    vector<int> a(SZ), b(SZ);

    // 生成20个随机数
    generate(a.begin(), a.end(), boundedRand);

    // 在0-99中随便选择一个，作为结果值的上限
    int val = boundedRand();

    // 移除大于val的元素，剩余元素拷贝到b数组
    auto end = remove_copy_if(a.begin(), a.end(), b.begin(), [val](int x) { return x > val; });

    // 对输出进行排序
    sort(a.begin(), a.end());
    sort(b.begin(), end);

    // 输出结果    
    ostream_iterator<int> out(cout, " ");
    cout << "原始序列：" << endl;
    copy(a.begin(), a.end(), out);
    cout << endl;

    cout << "小于等于" << val << "的值：" << endl;
    copy(b.begin(), end, out);
    cout << endl;

}