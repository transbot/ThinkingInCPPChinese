//: C08:CheckedCast2.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 使用RTTI的dynamic_cast
#include <vector>
#include "../purge.h"
#include "Security.h"

using namespace std;

int main() {
    vector<Security*> portfolio;
    portfolio.push_back(new Metal);
    portfolio.push_back(new Investment);
    portfolio.push_back(new Bond);
    portfolio.push_back(new Stock);

    for(vector<Security*>::iterator it = portfolio.begin();
        it != portfolio.end(); ++it) {
        Investment* cm = dynamic_cast<Investment*>(*it);
        if(cm)
            cm->special();
        else
            cout << "不是一个Investment" << endl;
    }

    cout << "从中间指针强制转型：" << endl;
    Security* sp = new Metal;
    Investment* cp = dynamic_cast<Investment*>(sp);
    if(cp)
        cout << "它是一个Investment" << endl;
    Metal* mp = dynamic_cast<Metal*>(sp);
    if(mp)
        cout << "它也是一个Metal!" << endl;

    purge(portfolio);
} ///:~
