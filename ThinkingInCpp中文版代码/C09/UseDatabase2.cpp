//: C09:UseDatabase2.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ����Countable������
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
    // ʹ��db�����������ݿ�����...
};

int main() {
    DBConnection* db = DBConnection::create("MyDatabase");
    assert(db->refCount() == 1);
    DBClient c1(db);
    assert(db->refCount() == 2);
    DBClient c2(db);
    assert(db->refCount() == 3);

    // ʹ�����ݿ⣬Ȼ���ͷ�ԭʼ��������������
    db->detach();
    assert(db->refCount() == 2);
} ///:~
