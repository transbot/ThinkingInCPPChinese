//: C11:Runnable_CPP20.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#ifndef RUNNABLE_H
#define RUNNABLE_H

// Runnable�ӿڶ�����һ��ͨ�õ�����ִ�нӿ�
class Runnable {
public:
    // ���麯��run����Ҫ����������ʵ��
    virtual void run() = 0;
    // ������������ȷ�����������������Ҳ�ܱ���ȷ����
    virtual ~Runnable() {}
};

#endif // RUNNABLE_H ///:~