//: C07:assocGen.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 创建与fill_n()和generate_n()等效的函数，
// 它们适用于关联容器。
#ifndef ASSOCGEN_H
#define ASSOCGEN_H

// 填充
template<class Assoc, class Count, class T>
void assocFill_n(Assoc& a, Count n, const T& val) {
    while(n-- > 0) a.insert(val);
}

// 生成
template<class Assoc, class Count, class Gen>
void assocGen_n(Assoc& a, Count n, Gen g) {
    while(n-- > 0) a.insert(g());
}
#endif // ASSOCGEN_H ///:~
