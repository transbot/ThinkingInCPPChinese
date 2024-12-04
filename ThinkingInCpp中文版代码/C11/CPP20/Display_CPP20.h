//: C11:Display_CPP20.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 防止 ostream 冲突
#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
#include <sstream>
#include <mutex>

class Display {
    // 在所有线程中共享一个这样的对象
    std::mutex iolock;

public:
    void output(std::ostringstream& os) {
        std::lock_guard<std::mutex> g(iolock); // 自动获取和释放锁
        std::cout << os.str();
    }
};
#endif // DISPLAY_H ///:~