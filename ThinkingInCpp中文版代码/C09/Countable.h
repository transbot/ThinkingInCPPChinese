//: C09:Countable.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 混入（mixin）类
#ifndef COUNTABLE_H
#define COUNTABLE_H
#include <cassert>
class Countable {
    long count;
protected:
    Countable() { count = 0; }
    virtual ~Countable() { assert(count == 0); } // 析构函数必须是虚函数
public:
    long attach() { return ++count; }
    long detach() {
        // 引用计数变成零，就执行delete this操作
        return (--count > 0) ? count : (delete this, 0);
    }
    long refCount() const { return count; } // 引用计数
};
#endif // COUNTABLE_H ///:~
