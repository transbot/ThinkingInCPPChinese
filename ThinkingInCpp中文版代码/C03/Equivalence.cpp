//: C03:Equivalence.cpp
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s2("That"), s1("This");
    // ��ֵ��һ�������Ű�Χ������ֵ
    // ����ֵ��һ��string����
    if("That" == s2)
        cout << "ƥ��" << endl;
    // ���������һ���ַ������Ҳ���������
    // ָ��C���null��ֹ�ַ�����ָ�룺
    if(s1 != s2.c_str())
        cout << "��ƥ��" << endl;
} ///:~
