//: C09:Interfaces2.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

//: C09:Interfaces2.cpp
// ͨ��ģ��ʵ����ʽ�ӿڼ̳�
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// ����Able�࣬ʵ�ֶ������
class Able {
    int myData;  // ��Ա�������洢����
public:
    Able(int x) { myData = x; }  // ���캯������ʼ����Ա����

    // ʵ�� print ������������ݵ�ָ������
    void print(ostream& os) const { 
        os << myData;  // �����������ָ������
    }

    // ʵ�� toInt �������������ݵ�����ֵ
    int toInt() const { 
        return myData;  // ���ش洢������
    }

    // ʵ��toString�������������ݵ��ַ�����ʾ
    string toString() const {
        ostringstream os;  // �����ַ���������
        os << myData;      // ������д���ַ�����
        return os.str();   // �����ַ�����������
    }
};

// ����ģ�庯�� testPrintable������Printable�ӿڵķ���
template<class Printable>
void testPrintable(const Printable& p) {
    p.print(cout);  // ����Printable�ӿڵ�print�������������������׼���
    cout << endl;   // ���뻻�з�
}

// ����ģ�庯�� testIntable������Intable�ӿڵķ���
template<class Intable>
void testIntable(const Intable& n) {
    cout << n.toInt() + 1 << endl;  // ����Intable�ӿڵ� toInt�������������1�����
}

// ����ģ�庯�� testStringable������Stringable�ӿڵķ���
template<class Stringable>
void testStringable(const Stringable& s) {
    cout << s.toString() + "th" << endl;  // ����Stringable�ӿڵ�toString�����������ƴ�Ӻ����
}

int main() {
    Able a(7);  // ����Able��Ķ��󣬳�ʼ������Ϊ 7

    // ����Printable�ӿ�
    testPrintable(a);  // �����7

    // ����Intable�ӿ�
    testIntable(a);  // �����8

    // ���� Stringable �ӿ�
    testStringable(a);  // �����7th

    return 0;
}