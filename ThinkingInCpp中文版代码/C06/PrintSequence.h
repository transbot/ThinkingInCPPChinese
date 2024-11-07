//: C06:PrintSequence.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 打印任意序列的内容
#ifndef PRINTSEQUENCE_H
#define PRINTSEQUENCE_H
#include <algorithm>
#include <iostream>
#include <iterator>

// 定义一个模板函数，用于打印任意序列的内容
template<typename Iter>
void print(Iter first, Iter last, const char* nm = "",
           const char* sep = "\n",  // 默认分隔符
           std::ostream& os = std::cout) {
    // 如果提供了名称，则先打印名称
    // 现代C++可以将nm != 0改成nm != nullptr，这样更加清晰和安全
    if (nm != 0 && *nm != '\0') {
        os << nm << ": " << sep;
    }

    // 获取迭代器的值类型
    typedef typename std::iterator_traits<Iter>::value_type T;

    // 使用std::copy将序列中的元素拷贝到输出流中
    std::copy(first, last, std::ostream_iterator<T>(os, sep));

    // 打印换行符
    os << std::endl;
}
#endif // PRINTSEQUENCE_H ///:~
