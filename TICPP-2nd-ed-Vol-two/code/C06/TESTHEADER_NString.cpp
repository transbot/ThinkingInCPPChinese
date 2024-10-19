//: .\C06:TESTHEADER_NString.cpp
//: C06:NString.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// A "numbered string" that keeps track of the
// number of occurrences of the word it contains.
// Only compare on the first element
// Keep track of the number of occurrences:
// Implicit operator= and copy-constructor are OK here.
// Need this for sorting. Notice it only
// compares strings, not occurrences:
// For sorting with greater<NString>:
// To get at the string directly:
// Because NString::vp is a template and we are using the
// inclusion model, it must be defined in this header file:
// NSTRING_H ///:~
#include"NString.h"
int main() {}
