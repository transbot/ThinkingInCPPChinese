//: C04:Unitbuf.cpp {RunByHand}
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

#include <cstdlib>  // Ϊ��ʹ��abort()
#include <fstream>
using namespace std;

int main() {
  ofstream out("log.txt");
  // out.setf(ios::unitbuf);
  out << "one" << endl;
  out << "two" << endl;
  abort();
} ///:~
