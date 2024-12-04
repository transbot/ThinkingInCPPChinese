//: C10:SingletonPattern.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

#include <iostream>
using namespace std;

class Singleton {
    static Singleton s;
    int i;
    Singleton(int x) : i(x) { } // ˽�й��캯��
    Singleton& operator=(Singleton&); // ������ֵ
    Singleton(const Singleton&); // ������������
public:
    static Singleton& instance() { return s; } // ��ȡΨһʵ����ע�ⷵ�ص�������
    int getValue() { return i; } // ��ȡֵ
    void setValue(int x) { i = x; } // ����ֵ
};

Singleton Singleton::s(47); // ������ⲿ��̬ʵ������ĳ�Ա����s

int main() {
    // ���þ�̬��Ա������ȡSingleton���Ψһʵ��
    Singleton& s = Singleton::instance(); 

    // ����getValue������ȡ�����ʵ���ĳ�ʼֵ��Ӧ���47
    cout << s.getValue() << endl; 

    // ��ȡSingleton���ͬһ��ʵ��
    Singleton& s2 = Singleton::instance(); 
    
    s2.setValue(9); // ͨ��s2������ã���ʵ����ֵ����Ϊ9
    cout << s.getValue() << endl; // Ӧ���9
} ///:~
