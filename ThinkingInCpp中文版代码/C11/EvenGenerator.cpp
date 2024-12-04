//: C11:EvenGenerator.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 当线程冲突时
//{L} ZThread
#include <iostream>
#include "EvenChecker.h"
#include "zthread/ThreadedExecutor.h"

using namespace ZThread;
using namespace std;

class EvenGenerator : public Generator {
    unsigned int currentEvenValue; // 无符号整型不会溢出
public:
    EvenGenerator() { currentEvenValue = 0; }
    ~EvenGenerator() { cout << "~EvenGenerator" << endl; }
    int nextValue() {
        ++currentEvenValue; // 危险点！
        ++currentEvenValue;
        return currentEvenValue;
    }
};

int main() {
    EvenChecker::test<EvenGenerator>();
} ///:~
