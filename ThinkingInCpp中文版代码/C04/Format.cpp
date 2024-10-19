//: C04:Format.cpp
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾ���ָ�ʽ������
#include <fstream>
#include <iostream>
#include "../require.h"
using namespace std;
#define D(A) T << #A << endl; A

int main() {
    ofstream T("format.out");
    assure(T);

    D(int i = 47;)
    D(float f = 2300114.414159;)
    const char* s = "���и�����";

    D(T.setf(ios::unitbuf);)
    D(T.setf(ios::showbase);)
    D(T.setf(ios::uppercase | ios::showpos);)
    D(T << i << endl;) // Ĭ����ʮ����
    D(T.setf(ios::hex, ios::basefield);) // ʮ������
    D(T << i << endl;)
    D(T.setf(ios::oct, ios::basefield);) // �˽���
    D(T << i << endl;)
    D(T.unsetf(ios::showbase);)
    D(T.setf(ios::dec, ios::basefield);)
    D(T.setf(ios::left, ios::adjustfield);)
    D(T.fill('0');)
    D(T << "����ַ�: " << T.fill() << endl;)
    D(T.width(10);)
    T << i << endl;
    D(T.setf(ios::right, ios::adjustfield);)
    D(T.width(10);)
    T << i << endl;
    D(T.setf(ios::internal, ios::adjustfield);)
    D(T.width(10);)
    T << i << endl;
    D(T << i << endl;) // û��width(10)

    D(T.unsetf(ios::showpos);)
    D(T.setf(ios::showpoint);)
    D(T << "���� = " << T.precision() << endl;)
    D(T.setf(ios::scientific, ios::floatfield);)
    D(T << endl << f << endl;)
    D(T.unsetf(ios::uppercase);)
    D(T << endl << f << endl;)
    D(T.setf(ios::fixed, ios::floatfield);)
    D(T << f << endl;)
    D(T.precision(20);)
    D(T << "���� = " << T.precision() << endl;)
    D(T << endl << f << endl;)
    D(T.setf(ios::scientific, ios::floatfield);)
    D(T << endl << f << endl;)
    D(T.setf(ios::fixed, ios::floatfield);)
    D(T << f << endl;)

    D(T.width(10);)
    T << s << endl;
    D(T.width(40);)
    T << s << endl;
    D(T.setf(ios::left, ios::adjustfield);)
    D(T.width(40);)
    T << s << endl;
} ///:~
