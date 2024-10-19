//: TestSuite:Suite.h
// ���ԡ�C++���˼��, ��2�桷
// ���ߣ�Bruce Eckel & Chuck Allison
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
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

        // ��ֹ�Ĳ���
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
        void run();  // �������� Test::run()
        long report() const;
        void free(); // �ͷš����ԡ�����
    };

} // namespace TestSuite
#endif // SUITE_H
