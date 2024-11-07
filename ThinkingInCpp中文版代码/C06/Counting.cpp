//: C06:Counting.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 计数算法
//{L} Generators
#include <algorithm>
#include <functional>
#include <iterator>
#include <set>
#include <vector>
#include <ctime> // 为了每次运行都获得不同的随机数种子
#include "Generators.h"
#include "PrintSequence.h"
using namespace std;

int main() {
    // 设置随机数种子
    std::srand(std::time(nullptr));  

    // 随机生成50个字符并填充向量v
    vector<char> v;
    generate_n(back_inserter(v), 50, CharGen());
    print(v.begin(), v.end(), "v", "");

    // 创建包含v中字符的一个集合，集合中的所有字符都不重复
    set<char> cs(v.begin(), v.end());
    typedef set<char>::iterator sci;

    // 参照集合cs，统计向量v中每个字符的出现次数
    for(sci it = cs.begin(); it != cs.end(); it++) {
        int n = count(v.begin(), v.end(), *it);
        cout << *it << ": " << n << ", ";
    }

    // 统计小写字母有多少个
    int lc = count_if(v.begin(), v.end(), bind2nd(greater<char>(), 'a'));
    cout << "\n小写字母: " << lc << "个" << endl;

    // 对向量v中的随机字符进行排序
    sort(v.begin(), v.end());
    print(v.begin(), v.end(), "排序后", "");
} ///:~
