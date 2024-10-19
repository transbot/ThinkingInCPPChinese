//: TestSuite:Test.h
// ���ԡ�C++���˼��, ��2�桷
// ���ߣ�Bruce Eckel & Chuck Allison
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#ifndef TEST_H
#define TEST_H

#include <string>
#include <iostream>
#include <cassert>

using std::string;
using std::ostream;
using std::cout;

// fail_()ʹ���»��ߺ�׺��������ios::fail()��ͻ��
// Ϊ�˱���һ�£�test_()��succeed_()Ҳʹ�����»��ߺ�׺��
#define test_(cond) \
    do_test(cond, #cond, __FILE__, __LINE__)
#define fail_(str) \
    do_fail(str, __FILE__, __LINE__)

namespace TestSuite {

class Test {
    // ָ���������ָ�룬����������Խ����Ĭ��Ϊ��׼���cout��
    ostream* osptr;
    // ��¼����ͨ���Ĵ���
    long nPass;
    // ��¼����ʧ�ܵĴ���
    long nFail;

    // Disallowed: �����������캯���͸�ֵ����������ֹʹ��
    Test(const Test&);
    Test& operator=(const Test&);

protected:
    // ����ִ�в��Բ��������ĸ�������
    void do_test(bool cond, const string& lbl, const char* fname, long lineno);
    // ���ڱ������ʧ�ܵĸ�������
    void do_fail(const string& lbl, const char* fname, long lineno);

public:
    // ���캯��������ָ���������Ĭ��Ϊ��׼���cout
    Test(ostream* osptr = &cout) {
        this->osptr = osptr;
        nPass = nFail = 0;
    }

    virtual ~Test() {}  // �鹹���������������ͷ���Դ

    // ���麯������������ʵ�֣�����ִ�о���Ĳ����߼�
    virtual void run() = 0;

    // ��ȡ����ͨ���Ĵ���
    long getNumPassed() const { return nPass; }
    // ��ȡ����ʧ�ܵĴ���
    long getNumFailed() const { return nFail; }
    // ��ȡ�����ָ��
    const ostream* getStream() const { return osptr; }
    // ���������ָ��
    void setStream(ostream* osptr) { this->osptr = osptr; }
    // ��¼һ�β���ͨ��
    void succeed_() { ++nPass; }
    // ���ɲ��Ա���
    long report() const;
    // �麯�����������ò��Խ��������
    virtual void reset() { nPass = nFail = 0; }
};

} // namespace TestSuite

#endif // TEST_H///:~
