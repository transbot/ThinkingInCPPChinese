//: C04:Strfile.cpp
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾ�ļ���I/O��
// ����ʾget()��getline()֮�������
#include <fstream>
#include <iostream>
#include "../require.h"
using namespace std;

int main() {
    const int SZ = 100; // ָ����������С
    char buf[SZ];
    {
        ifstream in("Strfile.cpp");  // ��ȡ
        assure(in, "Strfile.cpp");   // ��֤�Ƿ��
        ofstream out("Strfile.out"); // д��
        assure(out, "Strfile.out");  // ��֤�Ƿ��
        int i = 1;                   // �кż�����

        // ��Ϊ������������룺
        while (in.get(buf, SZ)) { // �������б���\n
            in.get(); // ������һ���ַ�(\n)
            cout << buf << endl; // �������\n
            // ���ļ�����ͱ�׼I/O���죺
            out << i++ << ": " << buf << endl;
        }
    } // ���������ر�in��out

    ifstream in("Strfile.out");
    assure(in, "Strfile.out");
    // ��Ϊ������������룺
    while (in.getline(buf, SZ)) { // �Ƴ�\n
        char* cp = buf;
        while (*cp != ':')
            ++cp;
        cp += 2; // ����": "
        cout << cp << endl; // ���Ǳ���Ҫ���\n
    }
} ///:~

