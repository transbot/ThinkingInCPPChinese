//: C08:IntermediateCast.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <cassert>
#include <typeinfo>
using namespace std;

class B1 { public: virtual ~B1() {} };
class B2 { public: virtual ~B2() {} };
class MI : public B1, public B2 {}; // MI继承自B1和B2，因此是多重继承的一个例子
class Mi2 : public MI {}; // Mi2继承自MI，因此它间接继承了B1和B2 

int main() {
    // Mi2对象向上转型为B2*，由于Mi2是B2的派生类，因此这种转型是安全的
    B2* b2 = new Mi2; 

    // b2向下转型回Mi2*，由于b2实际上指向一个Mi2对象，因此这种转型是安全的
    Mi2* mi2 = dynamic_cast<Mi2*>(b2); 

    // 同样地，Mi2是MI的派生类，这个向下转型也会成功
    MI* mi = dynamic_cast<MI*>(b2);

    // 演示跨继承链转型
    B1* b1 = dynamic_cast<B1*>(b2);

    assert(typeid(b2) != typeid(Mi2*));
    assert(typeid(b2) == typeid(B2*));
    delete b2;
} ///:~
