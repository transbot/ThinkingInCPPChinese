//: C04:Ostring.cpp {RunByHand}
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾ����ַ�����ostringstream
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    cout << "����һ��������һ����������һ���ַ����� ";
    int i;
    float f;
    cin >> i >> f;
    cin >> ws; // ����հ��ַ�
    string stuff;
    getline(cin, stuff); // ��ȡ������������
    ostringstream os;
    os << "���� = " << i << endl;
    os << "������ = " << f << endl;
    os << "�ַ��� = " << stuff << endl;
    string result = os.str();
    cout << result << endl;
} ///:~
