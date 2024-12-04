//: C09:Database_CPP20.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <stdexcept>
#include <string>

// 自定义异常类，继承自std::runtime_error
struct DatabaseError : public std::runtime_error {
    explicit DatabaseError(const std::string& msg) : 
        std::runtime_error(msg) {}
};

class Database {
    std::string dbid;
public:
    explicit Database(const std::string& dbStr) : dbid(dbStr) {}
    virtual ~Database() = default;  // 使用默认析构函数

    void open() {
        try {
            std::cout << "已连接到 " << dbid << std::endl;
            // 模拟数据库连接失败的情况
            if (dbid.empty()) {
                throw DatabaseError("数据库ID为空");
            }
        } catch (const DatabaseError& e) {
            std::cerr << "异常: " << e.what() << std::endl;
            throw;  // 重新抛出异常
        }
    }

    void close() noexcept {  // 使用noexcept规范
        std::cout << dbid << " 已关闭" << std::endl;
    }

    // 其他数据库函数...
};

#endif // DATABASE_H