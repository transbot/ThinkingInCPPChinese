//: C06:FillGenerateTest.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示“填充”和“生成”算法
//{L} Generators
#include <vector>
#include <algorithm>
#include <string>
#include <ctime> // 为了每次运行都获得不同的随机数种子
#include "Generators.h"
#include "PrintSequence.h"
using namespace std;

int main() {
    // 设置随机数种子，以便每次都在向量v4中填充不同的随机数序列
    std::srand(std::time(nullptr));  

    // 创建一个包含5个元素的vector，并用"山歌"填充所有元素
    vector<string> v1(5);
    fill(v1.begin(), v1.end(), "山歌");
    print(v1.begin(), v1.end(), "v1", " ");
    // 输出：v1:  山歌 山歌 山歌 山歌 山歌

    // 创建一个空的vector，并向其中插入7个"寥哉"元素
    vector<string> v2;
    fill_n(back_inserter(v2), 7, "寥哉");
    print(v2.begin(), v2.end(), "v2", " ");
    // 输出：v2:  寥哉 寥哉 寥哉 寥哉 寥哉 寥哉 寥哉

    // 创建一个包含10个元素的vector，并使用SkipGen生成器生成元素
    // SkipGen生成器会从4开始，每次递增5，生成一个序列
    vector<int> v3(10);
    generate(v3.begin(), v3.end(), SkipGen(4, 5));
    print(v3.begin(), v3.end(), "v3", " ");
    // 输出：v3:  4 9 14 19 24 29 34 39 44 49

    // 创建一个空的vector，并使用URandGen生成器生成15个随机数（范围为0-29）
    vector<int> v4;
    generate_n(back_inserter(v4), 15, URandGen(30));
    print(v4.begin(), v4.end(), "v4", " ");
    // 输出：v4:  随机数序列（每次运行结果不同）
} ///:~
