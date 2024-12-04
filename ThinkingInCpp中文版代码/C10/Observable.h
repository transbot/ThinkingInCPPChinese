//: C10:Observable.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ���۲�����
#ifndef OBSERVABLE_H
#define OBSERVABLE_H
#include <set>
#include "Observer.h"

class Observable {
    bool changed; // ����Ƿ��Ѹ���
    std::set<Observer*> observers; // ��set�洢�˹۲���

protected:
    virtual void setChanged() { changed = true; } // �����Ѹ��ı��
    virtual void clearChanged() { changed = false; } // ����Ѹ��ı��

public:
    virtual void addObserver(Observer& o) { // ��ӹ۲���
        observers.insert(&o);
    }
    virtual void deleteObserver(Observer& o) { // ɾ���ض��۲���
        observers.erase(&o);
    }
    virtual void deleteObservers() { // ɾ�����й۲���
        observers.clear();
    }
    virtual int countObservers() { // �۲�������
        return observers.size();
    }
    virtual bool hasChanged() { return changed; } // ��ѯ�Ƿ��Ѹ���

    // ��������Ѹ��ģ���֪ͨ���й۲���
    virtual void notifyObservers(Argument* arg = 0) {
        if (!hasChanged()) return;
        clearChanged(); // ���١��Ѹ��ġ�
        for (auto it = observers.begin(); it != observers.end(); ++it)
            (*it)->update(this, arg);
    }

    virtual ~Observable() {} // ����������ȷ����ȷ������Դ
};
#endif // OBSERVABLE_H ///:~
