//: C10:Observer.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// �۲��߽ӿ�
#ifndef OBSERVER_H
#define OBSERVER_H

// ����������Observable�࣬��ΪObserver�ӿ���ʹ����Observable*����
class Observable;

// ʵ���࣬����Ϊ�գ���Ϊ���ݵ��κ�ʵ�����͵Ļ���
// ��������ȷ��update�����ܽ��ܲ�ͬ���͵�����
class Argument {};

// �۲��߽ӿ�
class Observer {
public:
    // �����۲�������仯ʱ���ɱ��۲��������Ը���
    // ����o�Ƿ����仯�ı��۲����
    // ����arg�Ǵ��ݵĶ�����Ϣ���������������͵Ķ���ͨ���̳�Argument����ʵ��
    virtual void update(Observable* o, Argument* arg) = 0;
    
    virtual ~Observer() {} // ����������ȷ����ȷ������Դ
};
#endif // OBSERVER_H ///:~