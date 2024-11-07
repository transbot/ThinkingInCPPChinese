//: C06:Manipulations_CPP20.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 演示基本序列操作
 //{L} Generators
// NString
#include <vector>
#include <string>
#include <functional> 
#include <algorithm>
#include "PrintSequence.h"
#include "NString.h"
#include "Generators.h"
#include <random> // 为了使用现代C++需要的随机数生成器。
using namespace std;

int main() {
    vector<int> v1(10);
    // 将生成器应用于序列，打印生成的序列（整数0-9）
    generate(v1.begin(), v1.end(), SkipGen());
    print(v1.begin(), v1.end(), "v1", " ");

    // 创建和v1一样大小的另一个向量v2
    vector<int> v2(v1.size());
    
    // 从v1的最后一个元素开始，逆向拷贝到v2的最后一个位置，
    // 直到v1的第一个元素被拷贝到v2的第一个位置。
    // 因此，拷贝后v2的内容将和v1一致。    
    copy_backward(v1.begin(), v1.end(), v2.end());
    print(v2.begin(), v2.end(), "copy_backward", " ");
    
    // 反转v1的内容，并拷贝到v2的起始位置
    reverse_copy(v1.begin(), v1.end(), v2.begin());
    print(v2.begin(), v2.end(), "reverse_copy", " ");
    
    // 原地反转v1的内容
    reverse(v1.begin(), v1.end());
    print(v1.begin(), v1.end(), "reverse", " ");
    
    int half = v1.size() / 2; // 使用交换算法时，范围必须等长
    // 交换v1前半部分和后半部分的内容
    swap_ranges(v1.begin(), v1.begin() + half, v1.begin() + half);
    print(v1.begin(), v1.end(), "swap_ranges", " ");
    
    // 从一个新的序列开始
    generate(v1.begin(), v1.end(), SkipGen());
    print(v1.begin(), v1.end(), "v1", " ");
    
    // 演示“旋转”，版本1
    int third = v1.size() / 3;
    // 以下循环将v1的前三分之一不断“旋转”到后面
    for(int i = 0; i < 10; i++) {
        rotate(v1.begin(), v1.begin() + third, v1.end());
        print(v1.begin(), v1.end(), "rotate", " ");
    }
    
    // 演示"旋转"，版本2
    cout << "第二个旋转示例:" << endl;  
    char c[] = "山魈让她等一等，星夜兼程的情人。";
    const char CSZ = strlen(c);
    // 以下循环将字符数组c的前两个字符（一个汉字）不断“旋转”到后面
    for(int i = 0; i < 10; i++) {
        rotate(c, c + 2, c + CSZ);
        print(c, c + CSZ, "", "");
    }
    
    // 生成并打印"abcd"所有的排列
    cout << "abcd的所有n!种排列:" << endl;
    int nf = 4 * 3 * 2 * 1; // 共有这么多种排列
    char p[] = "abcd";    
    for(int i = 0; i < nf; i++) {
        next_permutation(p, p + 4);
        print(p, p + 4, "", "");
    }
    
    // 生成并打印"abcd"所有的排列，但改为使用prev_permutation
    cout << "使用prev_permutation:" << endl;
    // 生成并打印"abcd"的所有“前一个”排列
    for(int i = 0; i < nf; i++) {
        prev_permutation(p, p + 4);
        print(p, p + 4, "", "");
    }
    
    // 随机打乱一个单词:
    cout << "随机打乱一个单词:" << endl;
    string s("hello");
    cout << s << endl;
    // 随机打乱字符串 "hello" 并打印结果
    for(int i = 0; i < 5; i++) {
        // 使用std::shuffle替代random_shuffle
        // std::random_device是一个非确定性的随机数生成器，通常用于初始化随机数引擎（例如，std::mt19937），
        // 以确保每次运行程序时都能生成不同的随机数序列。
        std::random_device rd;
        std::mt19937 g(rd());
        shuffle(s.begin(), s.end(), g);
        // random_shuffle函数已从C++14弃用，从C++17移除
        // random_shuffle(s.begin(), s.end());
        cout << s << endl;
    }
    
    // NString是一种“编号字符串”，跟踪记录了其所含单词的出现次数（参见6.3.1节）
    NString sa[] = { "a", "b", "c", "d", "a", "b", "c", "d",
                     "a", "b", "c", "d", "a", "b", "c"};
    const int SASZ = sizeof sa / sizeof *sa;
    vector<NString> ns(sa, sa + SASZ);
    print(ns.begin(), ns.end(), "ns", " ");
    
    // 使用partition对ns进行分区，分区点是第一个大于"b"的元素
    // 现代C++应使用lambda表达式替换bind2nd
    /* vector<NString>::iterator it = partition(ns.begin(), ns.end(),
                                             bind2nd(greater<NString>(), "b")); */
    auto it = partition(ns.begin(), ns.end(),
                                        [](const NString& nstr) { return nstr > "b"; });
    cout << "分区点: " << *it << endl;
    print(ns.begin(), ns.end(), "", " ");
    
    // 重新加载向量
    copy(sa, sa + SASZ, ns.begin());

    // 使用stable_partition对ns进行分区，分区点是第一个大于"b"的元素，但保持原来的相对顺序
    // 现代C++应使用lambda表达式替换bind2nd
    // it = stable_partition(ns.begin(), ns.end(), bind2nd(greater<NString>(), "b"));
    it = stable_partition(ns.begin(), ns.end(), [](const NString& nstr) { return nstr > "b"; });

    cout << "稳定分区: " << endl;
    cout << "分区点: " << *it << endl;
    print(ns.begin(), ns.end(), "", " ");
}
///:~