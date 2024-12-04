// C11:SynchronousExecutor_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ʹ���ִ�C++��׼��ʵ��һ��������SynchronousExecutor�Ĺ���
#include <iostream>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>
#include "LiftOff_CPP20.h"

// SynchronousExecutor�࣬����˳��ִ������
class SynchronousExecutor {
    std::queue<std::function<void()>> tasks; // �������
    std::mutex mtx; // �����������������
    std::condition_variable cv; // ����������������ͬ��
    bool stop = false; // ��ֹ��־
    bool done = false; // ������ɱ�־

public:
    // �ύ����ִ����
    void execute(std::function<void()> task) {
        std::unique_lock<std::mutex> lock(mtx);
        tasks.push(std::move(task));
        cv.notify_one();
    }

    // ��ʼִ������
    void run() {
        while (true) {
            std::function<void()> task;
            {
                std::unique_lock<std::mutex> lock(mtx);
                cv.wait(lock, [this] { return !tasks.empty() || stop; });
                if (stop && tasks.empty()) {
                    done = true;
                    cv.notify_all(); // ֪ͨ���߳����������
                    return; // ���ﷵ�أ�����ѭ��
                }
                task = std::move(tasks.front());
                tasks.pop();
            }
            task();
        }
    }

    // ִֹͣ������
    void shutdown() {
        std::unique_lock<std::mutex> lock(mtx);
        stop = true;
        cv.notify_all();
    }

    // �ȴ������������
    void waitForCompletion() {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this] { return done; });
    }
};

int main() {
    SynchronousExecutor executor;

    // �ύ����
    for (int i = 0; i < 5; ++i) {
        executor.execute([i]() {
            LiftOff liftOff(10, i);
            liftOff.run();
        });
    }

    // ��main�߳�����������
    executor.run();

    // ����ֹͣ��־
    executor.shutdown();

    // �ȴ������������
    executor.waitForCompletion();

    return 0;
}