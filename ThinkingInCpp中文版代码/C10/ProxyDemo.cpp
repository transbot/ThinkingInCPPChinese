//: C10:ProxyDemo.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ����ģʽ�ļ���ʾ
#include <iostream>
using namespace std;

// ����һ�����࣬���д����ʵ���඼��Ҫʵ������������淶�Ľӿ�
class ProxyBase {
public:
    virtual void f() = 0;   // ���麯�����������ʵ��
    virtual void g() = 0;   // ���麯�����������ʵ��
    virtual void h() = 0;   // ���麯�����������ʵ��
    virtual ~ProxyBase() {} // ������������ȷ���������������������ȷ����
};

// ʵ���࣬�̳���ProxyBase��ʵ�������д��麯��
class Implementation : public ProxyBase {
public:
    void f() { cout << "Implementation.f()" << endl; } // ʵ��f()����
    void g() { cout << "Implementation.g()" << endl; } // ʵ��g()����
    void h() { cout << "Implementation.h()" << endl; } // ʵ��h()����
};

// �����࣬�̳���ProxyBase��������ʵ�����ָ��
class Proxy : public ProxyBase {
    ProxyBase* implementation; // ����ʵ�����ָ��
public:
    Proxy() { implementation = new Implementation(); } // �ڹ��캯���д���ʵ�������
    ~Proxy() { delete implementation; } // �������������ͷ�ʵ�������

    // ������ת����ʵ����
    void f() { implementation->f(); } // ת��f()����
    void g() { implementation->g(); } // ת��g()����
    void h() { implementation->h(); } // ת��h()����
};

int main() {
    Proxy p; // �����������
    p.f(); // ͨ������������f()
    p.g(); // ͨ������������g()
    p.h(); // ͨ������������h()
} ///:~