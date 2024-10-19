//: TestSuite:Suite.cpp {O}
// ���ԡ�C++���˼��, ��2�桷
// ���ߣ�Bruce Eckel & Chuck Allison
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include "Suite.h"
#include <iostream>
#include <cassert>
#include <cstddef>

using namespace std;
using namespace TestSuite;

void Suite::addTest(Test* t) throw(TestSuiteError) {
    // ��֤������Ч������һ�������
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

// ��ȡͨ������
long Suite::getNumPassed() const {
    long totPass = 0;
    for (size_t i = 0; i < tests.size(); ++i) {
        assert(tests[i]);
        totPass += tests[i]->getNumPassed();
    }
    return totPass;
}

// ��ȡʧ�ܴ���
long Suite::getNumFailed() const {
    long totFail = 0;
    for (size_t i = 0; i < tests.size(); ++i) {
        assert(tests[i]);
        totFail += tests[i]->getNumFailed();
    }
    return totFail;
}

// ����
void Suite::reset() {
    for (size_t i = 0; i < tests.size(); ++i) {
        assert(tests[i]);
        tests[i]->reset();
    }
} ///:~
