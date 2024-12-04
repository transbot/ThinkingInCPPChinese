//: C10:FibonacciGenerator.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

#ifndef FIBONACCIGENERATOR_H
#define FIBONACCIGENERATOR_H

class FibonacciGenerator {
    int n;          // ��ǰ���ɵ�쳲���������λ�ã���0��ʼ������
    int val[2];     // ��int����洢����������ɵ�쳲�������

public:
    // ���캯������ʼ��쳲���������λ�ú�ֵ
    FibonacciGenerator() : n(0) { 
        val[0] = val[1] = 0; 
    }

    // ���غ������ò�������������һ��쳲�������
    int operator()() {
        int result = n > 2 ? val[0] + val[1] : n > 0 ? 1 : 0; // ����λ�ü���쳲�������
        ++n; // ����λ��
        val[0] = val[1]; // ����ǰһ��ֵ
        val[1] = result; // ���µ�ǰֵ
        return result;   // �������ɵ�쳲�������
    }

    // ��ȡ�����ɵ�쳲�������������
    int count() { 
        return n; 
    }
};

#endif // FIBONACCIGENERATOR_H ///:~