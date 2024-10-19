//: C03:Trace.h
// 来自《C++编程思想, 第2版》
// 作者：Bruce Eckel & Chuck Allison
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页https://bookzhou.com下载。

// 创建一个跟踪文件
#ifndef TRACE_H
#define TRACE_H
#include <fstream>

#ifdef TRACEON
std::ofstream TRACEFILE__("TRACE.OUT");
#define cout TRACEFILE__
#endif

#endif // TRACE_H ///:~
