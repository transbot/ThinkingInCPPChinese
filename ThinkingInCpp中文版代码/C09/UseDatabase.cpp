//: C09:UseDatabase.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

#include "Database.h"
// 上述指令可以替换为#include "Database_CPP20.h"

int main() {
    Database db("MyDatabase");
    db.open();
    // 使用其他数据库功能...
    db.close();
}
/* 输出:
已连接到 MyDatabase
MyDatabase 已关闭
*/ ///:~
