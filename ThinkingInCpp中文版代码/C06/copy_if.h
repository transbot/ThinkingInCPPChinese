//: C06:copy_if.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 自定义STL风格的算法
#ifndef COPY_IF_H
#define COPY_IF_H

template<typename ForwardIter, typename OutputIter,
    typename UnaryPred>
OutputIter copy_if(ForwardIter begin, ForwardIter end,
    OutputIter dest, UnaryPred f) {
    while (begin != end) {
        if (f(*begin)) *dest++ = *begin;
        ++begin;
    }
    return dest;
}
#endif // COPY_IF_H ///:~
