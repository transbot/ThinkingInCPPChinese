//: C04:Sbufget.cpp
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ���ļ����Ƶ���׼���
#include <fstream>
#include <iostream>
#include "../require.h"
using namespace std;

int main() {
    ifstream in("Sbufget.cpp");
    assure(in);
    streambuf& sb = *cout.rdbuf(); // ָ�������
    while (!in.get(sb).eof()) {
        if (in.fail())          // ���ֿ���
            in.clear();         // ������д����־λ��ʹ���ָ�����״̬
        cout << char(in.get()); // ����'\n'
    }
} ///:~