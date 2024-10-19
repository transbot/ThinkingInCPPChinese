//: TestSuite:Test.h
// 来自《C++编程思想, 第2版》
// 作者：Bruce Eckel & Chuck Allison
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#ifndef TEST_H
#define TEST_H

#include <string>
#include <iostream>
#include <cassert>

using std::string;
using std::ostream;
using std::cout;

// fail_()使用下划线后缀来避免与ios::fail()冲突。
// 为了保持一致，test_()和succeed_()也使用了下划线后缀。
#define test_(cond) \
    do_test(cond, #cond, __FILE__, __LINE__)
#define fail_(str) \
    do_fail(str, __FILE__, __LINE__)

namespace TestSuite {

class Test {
    // 指向输出流的指针，用于输出测试结果（默认为标准输出cout）
    ostream* osptr;
    // 记录测试通过的次数
    long nPass;
    // 记录测试失败的次数
    long nFail;

    // Disallowed: 下面两个构造函数和赋值操作符被禁止使用
    Test(const Test&);
    Test& operator=(const Test&);

protected:
    // 用于执行测试并报告结果的辅助函数
    void do_test(bool cond, const string& lbl, const char* fname, long lineno);
    // 用于报告测试失败的辅助函数
    void do_fail(const string& lbl, const char* fname, long lineno);

public:
    // 构造函数，可以指定输出流，默认为标准输出cout
    Test(ostream* osptr = &cout) {
        this->osptr = osptr;
        nPass = nFail = 0;
    }

    virtual ~Test() {}  // 虚构析构函数，用于释放资源

    // 纯虚函数，需由子类实现，用于执行具体的测试逻辑
    virtual void run() = 0;

    // 获取测试通过的次数
    long getNumPassed() const { return nPass; }
    // 获取测试失败的次数
    long getNumFailed() const { return nFail; }
    // 获取输出流指针
    const ostream* getStream() const { return osptr; }
    // 设置输出流指针
    void setStream(ostream* osptr) { this->osptr = osptr; }
    // 记录一次测试通过
    void succeed_() { ++nPass; }
    // 生成测试报告
    long report() const;
    // 虚函数，用于重置测试结果计数器
    virtual void reset() { nPass = nFail = 0; }
};

} // namespace TestSuite

#endif // TEST_H///:~
