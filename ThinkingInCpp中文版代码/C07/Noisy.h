//: C07:Noisy.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 跟踪各种对象活动（构造、析构等）
#ifndef NOISY_H
#define NOISY_H
#include <iostream>
using std::endl;
using std::cout;
using std::ostream;

class Noisy {
    static long create, assign, copycons, destroy;
    long id;

public:
    Noisy() : id(create++) { // 默认构造函数
        cout << "d[" << id << "]" << endl;
    }
    Noisy(const Noisy& rv) : id(rv.id) { // 拷贝构造函数
        cout << "c[" << id << "]" << endl;
        ++copycons;
    }
    Noisy& operator=(const Noisy& rv) {
        cout << "(" << id << ")=[" << rv.id << "]" << endl;
        id = rv.id;
        ++assign;
        return *this;
    }
    friend bool operator<(const Noisy& lv, const Noisy& rv) {
        return lv.id < rv.id;
    }
    friend bool operator==(const Noisy& lv, const Noisy& rv) {
        return lv.id == rv.id;
    }
    ~Noisy() {
        cout << "~[" << id << "]" << endl;
        ++destroy;
    }
    friend ostream& operator<<(ostream& os, const Noisy& n) { // 重载插入符
        return os << n.id;
    }
    friend class NoisyReport;
};

struct NoisyGen {
    Noisy operator()() { return Noisy(); }
};

// 单例模式（该类只有一个实例），程序终止时会自动报告统计信息
class NoisyReport {
    static NoisyReport nr;
    NoisyReport() {} // 私有构造函数
    NoisyReport & operator=(NoisyReport &) = delete; // 禁止赋值
    NoisyReport(const NoisyReport&) = delete; // 禁止拷贝构造
public:
    ~NoisyReport() {
        cout << "\n-------------------\n"
             << "创建Noisy对象: " << Noisy::create << "\n"
             << "拷贝构造: " << Noisy::copycons << "\n"
             << "赋值: " << Noisy::assign << "\n"
             << "析构: " << Noisy::destroy << endl;
    }
};
#endif // NOISY_H ///:~
