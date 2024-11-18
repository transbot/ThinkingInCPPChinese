//: C07:Noisy.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ���ٸ��ֶ��������졢�����ȣ�
#ifndef NOISY_H
#define NOISY_H
#include <iostream>
using std::endl;
using std::cout;
using std::ostream;

class Noisy {
    static long create, assign, copycons, destroy;
    long id;

public:
    Noisy() : id(create++) { // Ĭ�Ϲ��캯��
        cout << "d[" << id << "]" << endl;
    }
    Noisy(const Noisy& rv) : id(rv.id) { // �������캯��
        cout << "c[" << id << "]" << endl;
        ++copycons;
    }
    Noisy& operator=(const Noisy& rv) {
        cout << "(" << id << ")=[" << rv.id << "]" << endl;
        id = rv.id;
        ++assign;
        return *this;
    }
    friend bool operator<(const Noisy& lv, const Noisy& rv) {
        return lv.id < rv.id;
    }
    friend bool operator==(const Noisy& lv, const Noisy& rv) {
        return lv.id == rv.id;
    }
    ~Noisy() {
        cout << "~[" << id << "]" << endl;
        ++destroy;
    }
    friend ostream& operator<<(ostream& os, const Noisy& n) { // ���ز����
        return os << n.id;
    }
    friend class NoisyReport;
};

struct NoisyGen {
    Noisy operator()() { return Noisy(); }
};

// ����ģʽ������ֻ��һ��ʵ������������ֹʱ���Զ�����ͳ����Ϣ
class NoisyReport {
    static NoisyReport nr;
    NoisyReport() {} // ˽�й��캯��
    NoisyReport & operator=(NoisyReport &) = delete; // ��ֹ��ֵ
    NoisyReport(const NoisyReport&) = delete; // ��ֹ��������
public:
    ~NoisyReport() {
        cout << "\n-------------------\n"
             << "����Noisy����: " << Noisy::create << "\n"
             << "��������: " << Noisy::copycons << "\n"
             << "��ֵ: " << Noisy::assign << "\n"
             << "����: " << Noisy::destroy << endl;
    }
};
#endif // NOISY_H ///:~
