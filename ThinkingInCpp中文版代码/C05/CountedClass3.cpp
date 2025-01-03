//: C05:CountedClass3.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <iostream>
using namespace std;

template<class T> class Counted {
    static int count;
public:
    Counted() { ++count; }
    Counted(const Counted<T>&) { ++count; }
    ~Counted() { --count; }
    static int getCount() { return count; }
};

template<class T> int Counted<T>::count = 0;

// 奇特的类定义
class CountedClass : public Counted<CountedClass> {};
class CountedClass2 : public Counted<CountedClass2> {};

int main() {
    CountedClass a;
    cout << CountedClass::getCount() << endl; // 1
    CountedClass b;
    cout << CountedClass::getCount() << endl; // 2
    CountedClass2 c;
    cout << CountedClass2::getCount() << endl; // 1 (这次对了)
} ///:~
