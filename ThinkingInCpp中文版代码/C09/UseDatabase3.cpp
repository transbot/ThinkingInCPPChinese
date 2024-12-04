//: C09:UseDatabase3.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ���Բ������Ļ�����
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
