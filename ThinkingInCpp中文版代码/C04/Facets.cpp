//: C04:Facets.cpp {-bor}{-g++}{-mwcc}{-edg}
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison��
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ���Ļ��ҷ���
#include <iostream>
#include <locale>
#include <string>
using namespace std;

int main() {
    // ����Ϊ����/������������
    locale loc("fr-FR");
    cout.imbue(loc);
    string currency = use_facet<moneypunct<char> >(loc).curr_symbol();
    char point = use_facet<moneypunct<char> >(loc).decimal_point();
    cout << "�ҽ���׬��" << currency << 123.45 << "ŷ��" << endl;
} ///:~
