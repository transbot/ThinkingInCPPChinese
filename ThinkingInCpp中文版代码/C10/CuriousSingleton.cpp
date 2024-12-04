//: C10:CuriousSingleton.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ����ġ������ԡ�����ʵ�ַ��루������
#include <iostream>
using namespace std;

template<class T>
class Singleton {
    Singleton(const Singleton&); // ������������
    Singleton& operator=(const Singleton&); // ������ֵ
protected:
    Singleton() {} // �ܱ������캯��
    virtual ~Singleton() {} // ����������
public:
    static T& instance() {
        static T theInstance;
        return theInstance;
    }
};

// һ��ʾ���࣬ת��Ϊ����
class MyClass : public Singleton<MyClass> {
    int x;
protected:
    friend class Singleton<MyClass>; // ��Singleton<MyClass>����Ϊ��Ԫ
    MyClass() { x = 0; } // ˽�й��캯��
public:
    void setValue(int n) { x = n; }    // ����ֵ
    int getValue() const { return x; } // ��ȡֵ
};

int main() {
    MyClass& m = MyClass::instance();
    cout << m.getValue() << endl;
    m.setValue(1);
    cout << m.getValue() << endl;
} ///:~
