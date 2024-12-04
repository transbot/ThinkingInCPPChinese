//: C11:BasicThreads.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// Thread类最基本的应用
//{L} ZThread
#include <iostream>
#include "LiftOff.h"
#include "zthread/Thread.h"
using namespace ZThread;
using namespace std;

int main() {
    try {
        Thread t(new LiftOff(10));
        cout << "点火倒计时" << endl;
    } catch(Synchronization_Exception& e) {
        cerr << e.what() << endl;
    }
} ///:~
