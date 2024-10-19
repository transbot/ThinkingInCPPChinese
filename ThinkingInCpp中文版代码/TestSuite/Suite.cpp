//: TestSuite:Suite.cpp {O}
// 来自《C++编程思想, 第2版》
// 作者：Bruce Eckel & Chuck Allison
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include "Suite.h"
#include <iostream>
#include <cassert>
#include <cstddef>

using namespace std;
using namespace TestSuite;

void Suite::addTest(Test* t) throw(TestSuiteError) {
    // 验证测试有效并且有一个输出流
    if (t == 0)
        throw TestSuiteError("Null test in Suite::addTest");
    else if (osptr && !t->getStream())
        t->setStream(osptr);
    tests.push_back(t);
    t->reset();
}

void Suite::addSuite(const Suite& s) {
    for (size_t i = 0; i < s.tests.size(); ++i) {
        assert(tests[i]);
        addTest(s.tests[i]);
    }
}

void Suite::free() {
    for (size_t i = 0; i < tests.size(); ++i) {
        delete tests[i];
        tests[i] = 0;
    }
}

void Suite::run() {
    reset();
    for (size_t i = 0; i < tests.size(); ++i) {
        assert(tests[i]);
        tests[i]->run();
    }
}

long Suite::report() const {
    if (osptr) {
        long totFail = 0;
        *osptr << "Suite \"" << name << "\"\n=======";
        size_t i;
        for (i = 0; i < name.size(); ++i)
            *osptr << '=';
        *osptr << "=" << endl;
        for (i = 0; i < tests.size(); ++i) {
            assert(tests[i]);
            totFail += tests[i]->report();
        }
        *osptr << "=======";
        for (i = 0; i < name.size(); ++i)
            *osptr << '=';
        *osptr << "=" << endl;
        return totFail;
    } else
        return getNumFailed();
}

// 获取通过次数
long Suite::getNumPassed() const {
    long totPass = 0;
    for (size_t i = 0; i < tests.size(); ++i) {
        assert(tests[i]);
        totPass += tests[i]->getNumPassed();
    }
    return totPass;
}

// 获取失败次数
long Suite::getNumFailed() const {
    long totFail = 0;
    for (size_t i = 0; i < tests.size(); ++i) {
        assert(tests[i]);
        totFail += tests[i]->getNumFailed();
    }
    return totFail;
}

// 重置
void Suite::reset() {
    for (size_t i = 0; i < tests.size(); ++i) {
        assert(tests[i]);
        tests[i]->reset();
    }
} ///:~
