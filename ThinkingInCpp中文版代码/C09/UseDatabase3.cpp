//: C09:UseDatabase3.cpp
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。

// 测试参数化的混入类
#include <cassert>
#include "Countable.h"
#include "DBConnection2.h"

class DBClient {
    DBConnection<Countable>* db;
public:
    DBClient(DBConnection<Countable>* dbCon) {
        db = dbCon;
        db->attach();
    }
    ~DBClient() {
        db->detach();
    }
};

int main() {
    DBConnection<Countable>* db =
    DBConnection<Countable>::create("MyDatabase");
    assert(db->refCount() == 1);
    DBClient c1(db);
    assert(db->refCount() == 2);
    DBClient c2(db);
    assert(db->refCount() == 3);
    db->detach();
    assert(db->refCount() == 2);
} ///:~
