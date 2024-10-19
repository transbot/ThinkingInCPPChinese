//: C04:Manips.cpp
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ʹ�ò���Ԫ��manipulator����дFormat.cpp
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    ofstream trc("trace.out");
    int i = 47;
    float f = 2300114.414159;
    char* s = "���и�����";

    trc << setiosflags(ios::unitbuf | ios::showbase | ios::uppercase | ios::showpos);

    trc << i << endl;
    trc << hex << i << endl
        << oct << i << endl;

    trc.setf(ios::left, ios::adjustfield);
    trc << resetiosflags(ios::showbase)
        << dec << setfill('0');

    trc << "����ַ�: " << trc.fill() << endl;
    trc << setw(10) << i << endl;

    trc.setf(ios::right, ios::adjustfield);
    trc << setw(10) << i << endl;

    trc.setf(ios::internal, ios::adjustfield);
    trc << setw(10) << i << endl;

    trc << i << endl; // Without setw(10)

    trc << resetiosflags(ios::showpos)
        << setiosflags(ios::showpoint)
        << "���� = " << trc.precision() << endl;

    trc.setf(ios::scientific, ios::floatfield);
    trc << f << resetiosflags(ios::uppercase) << endl;

    trc.setf(ios::fixed, ios::floatfield);
    trc << f << endl;

    trc << f << endl;

    trc << setprecision(20);
    trc << "���� = " << trc.precision() << endl;
    trc << f << endl;

    trc.setf(ios::scientific, ios::floatfield);
    trc << f << endl;

    trc.setf(ios::fixed, ios::floatfield);
    trc << f << endl;

    trc << setw(10) << s << endl;
    trc << setw(40) << s << endl;

    trc.setf(ios::left, ios::adjustfield);
    trc << setw(40) << s << endl;
} ///:~
