//: C09:Interfaces.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ӿڼ̳�
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// ����Printable�ӿ���
class Printable {
public:
    virtual ~Printable() {}  // ������������ȷ���������������������ȷ����
    virtual void print(ostream&) const = 0;  // ���麯���������ӡ����
};

// ����Intable�ӿ���
class Intable {
public:
    virtual ~Intable() {}  // ������������ȷ���������������������ȷ����
    virtual int toInt() const = 0;  // ���麯��������ת��Ϊ�����ķ���
};

// ����Stringable�ӿ���
class Stringable {
public:
    virtual ~Stringable() {}  // ������������ȷ���������������������ȷ����
    virtual string toString() const = 0;  // ���麯��������ת��Ϊ�ַ����ķ���
};

// ����Able�࣬ͬʱ�̳� Printable��Intable �� Stringable �ӿ�
class Able : public Printable, public Intable, public Stringable {
    int myData;  // ��Ա�������洢����
public:
    Able(int x) { myData = x; }  // ���캯������ʼ����Ա����

    // ʵ��Printable �ӿڵ�print����
    void print(ostream& os) const { 
        os << myData;  // �����������ָ������
    }

    // ʵ��Intable�ӿڵ�toInt����
    int toInt() const { 
        return myData;  // ���ش洢������
    }

    // ʵ��Stringable�ӿڵ�toString����
    string toString() const {
        ostringstream os;  // �����ַ���������
        os << myData;      // ������д���ַ�����
        return os.str();   // �����ַ�����������
    }
};

// ����Printable�ӿڵķ���
void testPrintable(const Printable& p) {
    p.print(cout); // ����Printable�ӿڵ�print�������������������׼���
    cout << endl;  // ���뻻�з�
}

// ����Intable�ӿڵķ���
void testIntable(const Intable& n) {
    // ����Intable�ӿڵ�toInt�������������1�����
    cout << n.toInt() + 1 << endl;  
}

// ����Stringable�ӿڵķ���
void testStringable(const Stringable& s) {
    // ����Stringable�ӿڵ�toString�����������ƴ�Ӻ����
    cout << s.toString() + "th" << endl; 
}

int main() {
    Able a(7);  // ����Able��Ķ��󣬳�ʼ������Ϊ7

    // ����Printable�ӿ�
    testPrintable(a);   // �����7

    // ����Intable�ӿ�
    testIntable(a);     // �����8

    // ����Stringable�ӿ�
    testStringable(a);  // �����7th

    return 0;
}
