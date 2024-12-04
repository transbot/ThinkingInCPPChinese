//: C11:ThreadLocalVariables_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// �Զ�Ϊÿ���̷߳����Լ��Ĵ洢
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <atomic> // ԭ�Ӳ���

using namespace std;

// ����һ���࣬���ڹ����ֲ߳̾�����
class ThreadLocalVariables {
    thread_local static int value; // �ֲ߳̾�������ÿ���߳����Լ��ĸ���
    atomic<bool> canceled; // ԭ�Ӳ�������������ȡ������

public:
    ThreadLocalVariables() : canceled(false) {
        value = 0; // ��ʼ���ֲ߳̾�����
    }

    void increment() {
        ++value; // �����ֲ߳̾�������ֵ
    }

    int get() const {
        return value; // ��ȡ�ֲ߳̾�������ֵ
    }

    void cancel() {
        canceled.store(true); // ����ȡ����־
    }

    bool isCanceled() const {
        return canceled.load(); // ���ȡ����־
    }
};

// ��ʼ����̬��Ա����
thread_local int ThreadLocalVariables::value = 0;

// ����һ���࣬���ڷ��ʺͲ����ֲ߳̾�����
class Accessor {
    int id; // �̱߳�ʶ��
    shared_ptr<ThreadLocalVariables> tlv; // ������ֲ߳̾������������

public:
    Accessor(shared_ptr<ThreadLocalVariables> tl, int idn) : id(idn), tlv(tl) {
        // ���캯������ʼ���̱߳�ʶ���͹������
    }

    void operator()() {
        while (!tlv->isCanceled()) {
            tlv->increment(); // �����ֲ߳̾�������ֵ
            cout << *this << endl; // �����ǰ�̵߳�״̬
            this_thread::sleep_for(chrono::milliseconds(10)); // ����һЩ�ӳ٣��Ա������߳��л�������
            this_thread::yield(); // �ó���ǰ�̵߳�ִ��Ȩ
        }
    }

    friend ostream& operator<<(ostream& os, const Accessor& a) {
        return os << "#" << a.id << ": " << a.tlv->get(); // ����̱߳�ʶ�����ֲ߳̾�������ֵ
    }
};

int main() {
    cout << "�밴<Enter>���˳�" << endl;

    try {
        auto tlv = make_shared<ThreadLocalVariables>(); // ����һ��������ֲ߳̾������������
        const int SZ = 5; // �����߳�����
        vector<thread> threads; // ���ڴ洢�����߳�

        for (int i = 0; i < SZ; i++) {
            threads.emplace_back(Accessor(tlv, i)); // ��������������߳�
        }

        cin.get(); // �ȴ��û���<Enter>��
        tlv->cancel(); // ����ȡ����־������Accessor�����˳�

        for (auto& t : threads) {
            t.join(); // �ȴ������߳̽���
        }
    } catch (exception& e) {
        cerr << e.what() << endl; // ���񲢴�����ܵ��쳣
    }

    return 0; 
}