//: C09:UseDatabase2.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 测试Countable混入类
 #include <cassert>
#include "DBConnection.h"

class DBClient {
    DBConnection* db;
public:
    DBClient(DBConnection* dbCon) {
        db = dbCon;
        db->attach();
    }
    ~DBClient() {
        db->detach();
    }
    // 使用db进行其他数据库请求...
};

int main() {
    DBConnection* db = DBConnection::create("MyDatabase");
    assert(db->refCount() == 1);
    DBClient c1(db);
    assert(db->refCount() == 2);
    DBClient c2(db);
    assert(db->refCount() == 3);

    // 使用数据库，然后释放原始创建的连接引用
    db->detach();
    assert(db->refCount() == 2);
} ///:~
