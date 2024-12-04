//: C11:Runnable_CPP20.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#ifndef RUNNABLE_H
#define RUNNABLE_H

// Runnable接口定义了一个通用的任务执行接口
class Runnable {
public:
    // 纯虚函数run，需要在派生类中实现
    virtual void run() = 0;
    // 虚析构函数，确保派生类的析构函数也能被正确调用
    virtual ~Runnable() {}
};

#endif // RUNNABLE_H ///:~