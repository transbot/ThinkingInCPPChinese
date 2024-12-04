//: C11:EvenChecker_CPP20.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

#ifndef EVENCHECKER_H
#define EVENCHECKER_H

#include <iostream>
#include <memory>
#include <thread>
#include <vector>
#include <future>
#include <atomic>

class Generator {
protected:
    std::atomic<bool> canceled;
public:
    Generator() : canceled(false) {}
    virtual ~Generator() = default;
    virtual int nextValue() = 0;
    void cancel() { canceled.store(true); }
    bool isCanceled() const { return canceled.load(); }
};

class EvenChecker {
    std::shared_ptr<Generator> generator;
    int id;
public:
    EvenChecker(std::shared_ptr<Generator> g, int ident) : generator(g), id(ident) {}
    ~EvenChecker() {
        std::cout << "~EvenChecker " << id << std::endl;
    }
    void operator()() {
        while(!generator->isCanceled()) {
            int val = generator->nextValue();
            if(val % 2 != 0) {
                std::cout << val << " ����ż����" << std::endl;
                generator->cancel(); // ȡ������EvenChecker
            }
        }
    }
    // testģ����Բ����κ����͵�������
    template<typename GenType>
    static void test(int n = 10) {
        std::cout << "��Ctrl+C�˳�" << std::endl;
        try {
            std::vector<std::future<void>> futures;
            auto generator = std::make_shared<GenType>();
            for(int i = 0; i < n; i++) {
                futures.emplace_back(std::async(std::launch::async, EvenChecker(generator, i)));
            }
            for(auto& fut : futures) {
                fut.get(); // �ȴ������������
            }
        } catch(std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
};

#endif // EVENCHECKER_H ///:~