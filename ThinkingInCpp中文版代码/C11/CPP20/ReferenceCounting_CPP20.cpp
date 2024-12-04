//: C11:ReferenceCounting_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ʹ��shared_ptr����ָ���ֹ��������
// ʹ�û������������������ݣ���ֹ����߳�ͬʱ����
// ���ڣ�����ʼ��������ȷ�Ľ����2000000
#include <thread>
#include <mutex>
#include <memory>
#include <iostream>

class Count {
public:
    int n = 0;
    std::mutex mtx;
    void increment() {
        std::lock_guard<std::mutex> lock(mtx);
        n++;
    }
};

int main() {
    std::shared_ptr<Count> count = std::make_shared<Count>();
    std::thread t1([](std::shared_ptr<Count> c) {
        for (int i = 0; i < 1000000; ++i) {
            c->increment();
        }
    }, count);
    std::thread t2([](std::shared_ptr<Count> c) {
        for (int i = 0; i < 1000000; ++i) {
            c->increment();
        }
    }, count);

    t1.join();
    t2.join();

    std::cout << count->n << std::endl;
    return 0;
}