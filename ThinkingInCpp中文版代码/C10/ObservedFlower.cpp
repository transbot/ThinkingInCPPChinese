//: C10:ObservedFlower.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾ�۲���ģʽ
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "Observable.h"
using namespace std;

class Flower {
    bool isOpen;
public:
    Flower() : isOpen(false),
        openNotifier(this), closeNotifier(this) {}
    void open() { // �򿪻���
        isOpen = true;
        openNotifier.notifyObservers();
        closeNotifier.open();
    }
    void close() { // �رջ���
        isOpen = false;
        closeNotifier.notifyObservers();
        openNotifier.close();
    }
    // ʹ�á��ڲ��ࡱ���÷���
    class OpenNotifier;
    friend class Flower::OpenNotifier;
    class OpenNotifier : public Observable {
        Flower* parent;
        bool alreadyOpen;
    public:
        OpenNotifier(Flower* f) : parent(f),
            alreadyOpen(false) {}
        void notifyObservers(Argument* arg = 0) {
            if(parent->isOpen && !alreadyOpen) {
                setChanged();
                Observable::notifyObservers();
                alreadyOpen = true;
            }
        }
        void close() { alreadyOpen = false; }
    } openNotifier;
    class CloseNotifier;
    friend class Flower::CloseNotifier;
    class CloseNotifier : public Observable {
        Flower* parent;
        bool alreadyClosed;
    public:
        CloseNotifier(Flower* f) : parent(f),
            alreadyClosed(false) {}
        void notifyObservers(Argument* arg = 0) {
            if(!parent->isOpen && !alreadyClosed) {
                setChanged();
                Observable::notifyObservers();
                alreadyClosed = true;
            }
        }
        void open() { alreadyClosed = false; }
    } closeNotifier;
};

class Bee {
    string name;
    // ���ڹ۲쿪�ŵġ��ڲ��ࡱ��
    class OpenObserver;
    friend class Bee::OpenObserver;
    class OpenObserver : public Observer {
        Bee* parent;
    public:
        OpenObserver(Bee* b) : parent(b) {}
        void update(Observable*, Argument *) {
            cout << "�۷� " << parent->name
                << " �����ʱ�䵽�ˣ�" << endl;
        }
    } openObsrv;
    // ���ڹ۲�رյ���һ�����ڲ��ࡱ��
    class CloseObserver;
    friend class Bee::CloseObserver;
    class CloseObserver : public Observer {
        Bee* parent;
    public:
        CloseObserver(Bee* b) : parent(b) {}
        void update(Observable*, Argument *) {
            cout << "�۷� " << parent->name
                << " ���ϴ�˯��ʱ�䵽�ˣ�" << endl;
        }
    } closeObsrv;
public:
    Bee(string nm) : name(nm),
        openObsrv(this), closeObsrv(this) {}
    Observer& openObserver() { return openObsrv; }
    Observer& closeObserver() { return closeObsrv;}
};

class Hummingbird {
    string name;
    class OpenObserver;
    friend class Hummingbird::OpenObserver;
    class OpenObserver : public Observer {
        Hummingbird* parent;
    public:
        OpenObserver(Hummingbird* h) : parent(h) {}
        void update(Observable*, Argument *) {
            cout << "���� " << parent->name
                << " �����ʱ�䵽�ˣ�" << endl;
        }
    } openObsrv;
    class CloseObserver;
    friend class Hummingbird::CloseObserver;
    class CloseObserver : public Observer {
        Hummingbird* parent;
    public:
        CloseObserver(Hummingbird* h) : parent(h) {}
        void update(Observable*, Argument *) {
            cout << "���� " << parent->name
                << " ���ϴ�˯��ʱ�䵽�ˣ�" << endl;
        }
    } closeObsrv;
public:
    Hummingbird(string nm) : name(nm),
        openObsrv(this), closeObsrv(this) {}
    Observer& openObserver() { return openObsrv; }
    Observer& closeObserver() { return closeObsrv;}
};

int main() {
    Flower f;
    Bee ba("A"), bb("B");
    Hummingbird ha("A"), hb("B");
    f.openNotifier.addObserver(ha.openObserver());
    f.openNotifier.addObserver(hb.openObserver());
    f.openNotifier.addObserver(ba.openObserver());
    f.openNotifier.addObserver(bb.openObserver());
    f.closeNotifier.addObserver(ha.closeObserver());
    f.closeNotifier.addObserver(hb.closeObserver());
    f.closeNotifier.addObserver(ba.closeObserver());
    f.closeNotifier.addObserver(bb.closeObserver());
    // ����B����������
    f.openNotifier.deleteObserver(hb.openObserver());
    // ������һЩ�۲��߸���Ȥ���¼���
    f.open();
    f.open(); // �Ѿ������ˣ�û�б仯��
    // �۷�A�����ϴ�˯����
    f.closeNotifier.deleteObserver(
        ba.closeObserver());
    f.close();
    f.close(); // �Ѿ������ˣ�û�б仯
    f.openNotifier.deleteObservers();
    f.open();
    f.close();
} ///:~