//: C06:Transform.cpp {-mwcc}
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// 使用STL transform()算法
//{L} Counted
#include <iostream>
#include <vector>
#include <algorithm>
#include "Counted.h"
using namespace std;

template<class T> T* deleteP(T* x) {
    delete x;
    return 0; // 现代C++返回nullptr更加明确
}

template<class T> struct Deleter {
    T* operator()(T* x) {
        delete x;
        return 0; // 现代C++返回nullptr更加明确
    }
};


int main() {
    CountedVector cv("花");
    transform(cv.begin(), cv.end(), cv.begin(), deleteP<Counted>);
    CountedVector cv2("妖");
    transform(cv2.begin(), cv2.end(), cv2.begin(), Deleter<Counted>());
} ///:~
