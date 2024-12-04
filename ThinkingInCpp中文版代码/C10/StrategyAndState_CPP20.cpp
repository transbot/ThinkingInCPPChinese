//: C10:StrategyAndState_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// �����ԡ����ģʽ
#include <iostream>
using namespace std;

// ���Խӿ�
class NameStrategy {
public:
    virtual void greet() = 0; // ���麯����������к�����Ϊ
};

// ��������������ĳ�����ֵ����
class SayHi : public NameStrategy { // ���еش��к�
public:
    void greet() override { // ʵ�ִ��к���Ϊ
        cout << "��ã�" << endl;
    }
};

class Ignore : public NameStrategy { // �Ӷ�����
public:
    void greet() override { // ʵ�ִ��к���Ϊ
        cout << "(��װû�����Է�)" << endl;
    }
};

class Admission : public NameStrategy { // ��ʵ�������ǶԷ������� 
public:
    void greet() override { // ʵ�ִ��к���Ϊ
        cout << "�Բ����������ǣ�" << endl;
    }
};

// �������ġ����Ʋ���
class Context {
    NameStrategy& strategy; // ���õ�ǰʹ�õĲ���

public:
    Context(NameStrategy& strat) : strategy(strat) {} // ���캯������ʼ������
    void greet() { // ���õ�ǰ���ԵĴ��к�����
        strategy.greet();
    }
};

int main() {
    SayHi sayhi; // �������д��к��Ĳ���
    Ignore ignore; // �����Ӷ������Ĳ���
    Admission admission; // ������ʵ�����������ֵĲ���

    // �������ֲ�ͬ�������ģ�ÿ��������ʹ�ò�ͬ�Ĳ���
    Context c1(sayhi), c2(ignore), c3(admission);
    c1.greet(); // ʹ�����д��к��Ĳ���
    c2.greet(); // ʹ���Ӷ������Ĳ���
    c3.greet(); // ʹ����ʵ�����������ֵĲ���
} ///:~