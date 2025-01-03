//: C07:FEditTest.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
//{L} FileEditor

// 测试FileEditor工具
#include <sstream>
#include "FileEditor.h"
#include "../require.h"
using namespace std;

int main(int argc, char* argv[]) {
    FileEditor file;
    if(argc > 1) {
        file.open(argv[1]);
    } else {
        file.open("FEditTest.cpp");
    }

    // 对行进行某种操作...
    int i = 1;
    FileEditor::iterator w = file.begin();
    while(w != file.end()) {
        ostringstream ss;
        ss << i++;
        *w = ss.str() + ": " + *w;
        ++w;
    }

    // 现在将它们发送到cout：
    file.write();
} ///:~
