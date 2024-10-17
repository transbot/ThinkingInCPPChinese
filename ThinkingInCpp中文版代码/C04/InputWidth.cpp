//: C04:InputWidth.cpp
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison��
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾ��setwӦ��������ʱ������
#include <cassert>
#include <cmath>
#include <iomanip>
#include <limits>
#include <sstream>
#include <string>
using namespace std;

int main() {
  istringstream is("one 2.34 five");
  string temp;
  is >> setw(2) >> temp;
  assert(temp == "on");
  is >> setw(2) >> temp;
  assert(temp == "e");
  double x;
  is >> setw(2) >> x;
  double relerr = fabs(x - 2.34) / x;
  assert(relerr <= numeric_limits<double>::epsilon());
} ///:~
