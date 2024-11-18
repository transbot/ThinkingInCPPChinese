//: C08:CatchBadCast.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
#include <typeinfo>
#include "Security.h"
using namespace std;

int main() {
    Metal m;
    // 将Metal对象m绑定到Security类型的引用s，
    // 由于Metal继承自Investment，而Investment继承自Security，因此这是合法的。
    Security& s = m;

    try {
        // 尝试将Security引用s转型为Investment引用
        // 由于s实际上引用的是Metal对象，而Metal是Investment的子类，
        // 因此这个转型会成功。
        Investment& c = dynamic_cast<Investment&>(s);
        // 如果成功，会执行以下语句：
        cout << "s是一种Investment" << endl;
    } catch(bad_cast&) {
        cout << "s不是一种Investment" << endl;
    }

    try {
        // 尝试将Security引用s转型为Bond引用
        // 由于s实际上引用的是Metal对象，而Metal并不是Bond的子类，
        // 因此这个转型会失败。
        Bond& b = dynamic_cast<Bond&>(s);
        cout << "s是一种Bond" << endl;
    } catch(bad_cast&) {
        cout << "s不是一种Bond" << endl;
    }
} ///:~