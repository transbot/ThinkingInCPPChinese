//: C10:TemplateMethod.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ģ�巽���ļ���ʾ
#include <iostream>
using namespace std;

// Ӧ�ó�������
class ApplicationFramework {
protected:
    // ��Ҫ����������ʵ�ֵ��Զ��巽��
    virtual void customize1() = 0;
    virtual void customize2() = 0;

public:
    // ģ�巽�����������㷨�ĹǼ�
    void templateMethod() {
        for(int i = 0; i < 5; i++) {
            customize1(); // ���õ�һ���Զ��巽��
            customize2(); // ���õڶ����Զ��巽��
        }
    }
};

// ����һ���µġ�Ӧ�ó��򡱣��̳���Ӧ�ó�����
class MyApp : public ApplicationFramework {
protected:
    // ʵ���Զ��巽��customize1
    void customize1() { cout << "Hello "; }

    // ʵ���Զ��巽��customize2
    void customize2() { cout << "World!" << endl; }
};

int main() {
    MyApp app; // ����MyApp����
    app.templateMethod(); // ����ģ�巽��
} ///:~