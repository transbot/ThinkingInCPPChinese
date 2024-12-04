//: C09:Database_CPP20.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <stdexcept>
#include <string>

// �Զ����쳣�࣬�̳���std::runtime_error
struct DatabaseError : public std::runtime_error {
    explicit DatabaseError(const std::string& msg) : 
        std::runtime_error(msg) {}
};

class Database {
    std::string dbid;
public:
    explicit Database(const std::string& dbStr) : dbid(dbStr) {}
    virtual ~Database() = default;  // ʹ��Ĭ����������

    void open() {
        try {
            std::cout << "�����ӵ� " << dbid << std::endl;
            // ģ�����ݿ�����ʧ�ܵ����
            if (dbid.empty()) {
                throw DatabaseError("���ݿ�IDΪ��");
            }
        } catch (const DatabaseError& e) {
            std::cerr << "�쳣: " << e.what() << std::endl;
            throw;  // �����׳��쳣
        }
    }

    void close() noexcept {  // ʹ��noexcept�淶
        std::cout << dbid << " �ѹر�" << std::endl;
    }

    // �������ݿ⺯��...
};

#endif // DATABASE_H