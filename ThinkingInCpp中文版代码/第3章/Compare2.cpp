//: C03:Compare2.cpp
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison��
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾ���ص�compare()
#include <cassert>
#include <string>
using namespace std;

int main() {
    string first("This is a day that will live in infamy");
    string second("I don't believe that this is what "
                  "I signed up for");
    // �Ƚ������ַ����е�"his is"��
    assert(first.compare(1, 7, second, 22, 7) == 0);
    // �Ƚ�"his is a"��"his is w"��
    assert(first.compare(1, 9, second, 22, 9) < 0);
} ///:~
