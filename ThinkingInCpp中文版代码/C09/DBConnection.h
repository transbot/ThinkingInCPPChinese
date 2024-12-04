//: C09:DBConnection.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 使用混入类
#ifndef DBCONNECTION_H
#define DBCONNECTION_H
#include <cassert>
#include <string>
#include "Countable.h"
#include "Database.h"

using std::string;

class DBConnection : public Database, public Countable {
    DBConnection(const DBConnection&); // 禁止拷贝
    DBConnection& operator=(const DBConnection&);

protected:
    DBConnection(const string& dbStr) throw(DatabaseError) : Database(dbStr) {
        open();
    }
    ~DBConnection() {
        close();
    }

public:
    static DBConnection* create(const string& dbStr) throw(DatabaseError) {
        DBConnection* con = new DBConnection(dbStr);
        con->attach();
        assert(con->refCount() == 1);
        return con;
    }

    // 根据需要添加其他功能...
};
#endif // DBCONNECTION_H ///:~
