//: C11:EvenChecker_CPP20.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

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
                std::cout << val << " 不是偶数！" << std::endl;
                generator->cancel(); // 取消所有EvenChecker
            }
        }
    }
    // test模板可以测试任何类型的生成器
    template<typename GenType>
    static void test(int n = 10) {
        std::cout << "按Ctrl+C退出" << std::endl;
        try {
            std::vector<std::future<void>> futures;
            auto generator = std::make_shared<GenType>();
            for(int i = 0; i < n; i++) {
                futures.emplace_back(std::async(std::launch::async, EvenChecker(generator, i)));
            }
            for(auto& fut : futures) {
                fut.get(); // 等待所有任务完成
            }
        } catch(std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
};

#endif // EVENCHECKER_H ///:~