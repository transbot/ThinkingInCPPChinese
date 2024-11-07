//: C06:Removing.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 从范围中删除（remove）元素的算法
// {L} Generators
#include <algorithm>
#include <cctype>
#include <string>
#include "Generators.h"
#include "PrintSequence.h"
using namespace std;

// IsUpper结构体定义了一个函数对象（也称为仿函数或functor），
// 用于判断一个字符是否为大写字母。
struct IsUpper { 
    bool operator()(char c) { 
        return isupper(c); 
    } 
};

int main() { 
    std::srand(std::time(nullptr));  // 设置随机数种子
    string v; 
    v.resize(25); 
    generate(v.begin(), v.end(), CharGen());  // 在字符串v中随机填充25个字符（均为字母）
    print(v.begin(), v.end(), "原始的v", "");  // 打印字符串v的内容

    string us(v.begin(), v.end());  // 创建新的字符串us，其内容与v相同
    sort(us.begin(), us.end());     // 对us进行排序

    // 使用unique来删除us中的重复元素，并获取新序列的“末端后”迭代器uend
    string::iterator it = us.begin(), cit = v.end(),
                          uend = unique(us.begin(), us.end()); 

    // 在序列中遍历并删除每个“唯一”的元素。
    // cit指向的是remove操作后，新形成的“逻辑末尾”；
    // 也就是说，[v.begin(), cit)包含了未被删除的元素，
    // 而[cit, v.end())包含了被删除的元素（这些元素的值是未定义的）。
    // 每次remove操作都会更新cit的位置。
    while(it != uend) { 
        cit = remove(v.begin(), cit, *it); 
        print(v.begin(), v.end(), "完整的v", ""); 
        print(v.begin(), cit, "伪v ", " ");
        cout << "删除的元素:\t" << *it << "\n伪v的最后一个元素:\t" << *cit << endl << endl; 
        ++it; // 移动到us中的下一个唯一字符
    } 

    // 重新生成v的内容
    generate(v.begin(), v.end(), CharGen()); 
    print(v.begin(), v.end(), "v", ""); 

    // 使用remove_if移除所有大写字母
    cit = remove_if(v.begin(), v.end(), IsUpper()); 
    print(v.begin(), cit, "执行remove_if IsUpper后的v", " "); 

    // 没有演示remove()和remove_if()的“copy”版本，
    // 因为它们是非拷贝版本的简单变体，你您应该无需示例就能理解。

    // 对删除操作后的范围进行排序
    sort(v.begin(), cit); 
    print(v.begin(), cit, "排序后的v", " "); 

    // 创建一个新的字符串v2，并使用unique_copy删除重复元素
    string v2; 
    v2.resize(cit - v.begin()); 
    unique_copy(v.begin(), cit, v2.begin()); 
    print(v2.begin(), v2.end(), "unique_copy", " "); 

    // 还是使用unique删除重复元素，但指定相等性比较谓词
    cit = unique(v.begin(), cit, equal_to<char>()); 
    print(v.begin(), cit, "unique equal_to<char>", " "); 
} ///:~
