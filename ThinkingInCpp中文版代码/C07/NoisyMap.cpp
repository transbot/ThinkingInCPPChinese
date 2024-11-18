//: C07:NoisyMap.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 将Noisy映射到Noisy
//{L} Noisy
#include <map>
#include "Noisy.h"
using namespace std;

int main() {
    map<Noisy, Noisy> mnn;
    Noisy n1, n2;
    cout << "\n--------" << endl;
    mnn[n1] = n2;
    cout << "\n--------" << endl;
    cout << mnn[n1] << endl;
    cout << "\n--------" << endl;
} ///:~
