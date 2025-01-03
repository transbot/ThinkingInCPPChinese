//: C09:Database.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 一个典型的资源类
#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <stdexcept>
#include <string>

struct DatabaseError : std::runtime_error {
    DatabaseError(const std::string& msg) : 
        std::runtime_error(msg) {}
};

class Database {
    std::string dbid;
public:
    Database(const std::string& dbStr) : dbid(dbStr) {}
    virtual ~Database() {}

    void open() throw(DatabaseError) {
        std::cout << "已连接到 " << dbid << std::endl;
    }

    void close() {
        std::cout << dbid << " 已关闭" << std::endl;
    }

    // 其他数据库函数...
};
#endif // DATABASE_H ///:~
