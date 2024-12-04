//: C09:DBConnection2.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// �������Ļ�����
 #ifndef DBCONNECTION2_H
#define DBCONNECTION2_H
#include <cassert>
#include <string>
#include "Database.h"

using std::string;

template<class Counter>
class DBConnection : public Database, public Counter {
    DBConnection(const DBConnection&); // ��ֹ����
    DBConnection& operator=(const DBConnection&);

protected:
    DBConnection(const string& dbStr) throw(DatabaseError)
    : Database(dbStr) {
        open();
    }
    ~DBConnection() {
        close();
    }

public:
    static DBConnection* create(const string& dbStr)
    throw(DatabaseError) {
        DBConnection* con = new DBConnection(dbStr);
        con->attach();
        assert(con->refCount() == 1);
        return con;
    }

    // ������Ҫ�����������...
};
#endif // DBCONNECTION2_H ///:~
