//: C09:UseDatabase.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

#include "Database.h"
// ����ָ������滻Ϊ#include "Database_CPP20.h"

int main() {
    Database db("MyDatabase");
    db.open();
    // ʹ���������ݿ⹦��...
    db.close();
}
/* ���:
�����ӵ� MyDatabase
MyDatabase �ѹر�
*/ ///:~
