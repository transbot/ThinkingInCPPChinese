//: C03:Tracetst.cpp {-bor}
// ���ԡ�C++���˼��, ��2�桷
// ���ߣ�Bruce Eckel & Chuck Allison��
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳhttps://bookzhou.com���ء�

#include <iostream>
#include <fstream>
#include "../require.h"
using namespace std;

std::ofstream TRACEFILE__("TRACE1.OUT");
#define cout TRACEFILE__
int main() {
  ifstream f("temp.cpp");
  assure(f, "temp.cpp");
  cout << f.rdbuf(); // ���ļ�������ת����TRACE1.OUT�ļ���
} ///:~
