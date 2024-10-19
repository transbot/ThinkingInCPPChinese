//: TestSuite:Suite.h
// 来自《C++编程思想, 第2版》
// 作者：Bruce Eckel & Chuck Allison
// 译者：周靖(bookzhou.com)
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#ifndef SUITE_H
#define SUITE_H

#include <vector>
#include <stdexcept>
#include "../TestSuite/Test.h"

using std::vector;
using std::logic_error;

namespace TestSuite {
    class TestSuiteError : public logic_error {
    public:
        TestSuiteError(const string& s = "")
            : logic_error(s) {}
    };

    class Suite {
    private:
        string name;
        ostream* osptr;
        vector<Test*> tests;
        void reset();

        // 禁止的操作
        Suite(const Suite&);
        Suite& operator=(const Suite&);

    public:
        Suite(const string& name, ostream* osptr = &cout)
            : name(name) { this->osptr = osptr; }
        string getName() const { return name; }
        long getNumPassed() const;
        long getNumFailed() const;
        const ostream* getStream() const { return osptr; }
        void setStream(ostream* osptr) { this->osptr = osptr; }
        void addTest(Test* t) throw(TestSuiteError);
        void addSuite(const Suite&);
        void run();  // 反复调用 Test::run()
        long report() const;
        void free(); // 释放“测试”对象
    };

} // namespace TestSuite
#endif // SUITE_H
