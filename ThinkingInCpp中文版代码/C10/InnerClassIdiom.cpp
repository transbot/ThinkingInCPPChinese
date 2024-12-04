//: C10:InnerClassIdiom.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

//: C10:InnerClassIdiom.cpp
// ���ڲ��ࡱ���÷�ʾ��
#include <iostream>
#include <string>
using namespace std;

class Poingable { // ����һ���ӿ�
public:
    virtual void poing() = 0; // ���麯��
};

void callPoing(Poingable& p) { // ʹ�ýӿ�
    p.poing();
}

class Bingable { // ������һ���ӿ�
public:
    virtual void bing() = 0; // ���麯��
};

void callBing(Bingable& b) { // ʹ�ýӿ�
    b.bing();
}

class Outer { // �ⲿ��
private:
    string name;  // ˽�����ݳ�Ա
    class Inner1; // �����һ���ڲ���
    friend class Outer::Inner1; // �ڲ������ⲿ�����Ԫ
    class Inner1 : public Poingable { // ʵ��Poingable�ӿ�
    private:
        Outer* parent; // ָ���ⲿ���ָ��
    public:
        Inner1(Outer* p) : parent(p) {} // ���캯����ʼ��ָ��
        void poing() {
            cout << "poing called for " << parent->name
                 << endl; // �����ⲿ�������
        }
    } inner1; // �����ڲ���ʵ��

    class Inner2; // ����ڶ����ڲ���
    friend class Outer::Inner2; // �ڲ������ⲿ�����Ԫ
    class Inner2 : public Bingable { // ʵ��Bingable�ӿ�
    private:
        Outer* parent; // ָ���ⲿ���ָ��
    public:
        Inner2(Outer* p) : parent(p) {} // ���캯����ʼ��ָ��
        void bing() {
            cout << "bing called for " << parent->name
                 << endl; // �����ⲿ�������
        }
    } inner2; // �����ڲ���ʵ��

public:
    // ��ʼ���ⲿ����ڲ���ʵ��
    Outer(const string& nm) : name(nm), inner1(this), inner2(this) {} 
    // �����ڲ���ʵ�ֵĽӿڵ�����
    operator Poingable&() { return inner1; }
    operator Bingable&() { return inner2; }
};

int main() {
    Outer x("Ping Pong");
    // ģ������ת��Ϊ��������ͣ�
    callPoing(x); // ����x��Poingable�ӿ�
    callBing(x);  // ����x��Bingable�ӿ�
} ///:~
