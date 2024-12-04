//: C09:Database.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// һ�����͵���Դ��
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
        std::cout << "�����ӵ� " << dbid << std::endl;
    }

    void close() {
        std::cout << dbid << " �ѹر�" << std::endl;
    }

    // �������ݿ⺯��...
};
#endif // DATABASE_H ///:~
