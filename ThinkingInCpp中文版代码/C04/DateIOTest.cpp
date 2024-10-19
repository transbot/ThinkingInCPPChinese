//: C04:DateIOTest.cpp
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
//{L} ../C02/Date
#include <iostream>
#include <sstream>
#include "../C02/Date.h"  // Date���ڵ�2�¶���
using namespace std;

void testDate(const string& s) {
    istringstream os(s);
    Date d;
    os >> d;
    if (os)
        cout << d << endl;
    else
        cout << "������� \"" << s << "\"" << endl;
}

int main() {
    testDate("08-10-2023");
    testDate("8-10-2023");
    testDate("08 - 10 - 2023");
    testDate("A-10-2023");
    testDate("08%10/2023");
} ///:~
