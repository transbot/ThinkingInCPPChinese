//: C04:Seeking.cpp
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��iostream�ж�λ
#include <cassert>
#include <cstddef>
#include <cstring>
#include <fstream>
#include "../require.h"
using namespace std;

int main() {
  const int STR_NUM = 5, STR_LEN = 50; // �����ַ���������ÿ���ַ����ĳ���
  char origData[STR_NUM][STR_LEN] = {
    "��ֻ����û�а�����ξ��������",
    "���������������ӷ��������۱��ڣ�",
    "������׷����ȥ�ĸ��ס�",
    "�������ĺ��ӡ�",
    "�����Ҽ������һ�����ԭ�����Լ���"
  };
  char readData[STR_NUM][STR_LEN] = {{ 0 }};
  ofstream out("�����ˡ�����.bin", ios::out | ios::binary);
  assure(out, "�����ˡ�����.bin");
  for(int i = 0; i < STR_NUM; i++)
    out.write(origData[i], STR_LEN);
  out.close();
  ifstream in("�����ˡ�����.bin", ios::in | ios::binary);
  assure(in, "�����ˡ�����.bin");

  // ��ȡ�ļ��д洢�ĵ�һ���ı�
  in.read(readData[0], STR_LEN);
  assert(strcmp(readData[0], "��ֻ����û�а�����ξ��������")
      == 0);  
  
  // ���ļ�β��ǰ�ƶ� -STR_LEN ���ֽ�
  in.seekg(-STR_LEN, ios::end); // ��λ�����ļ��д洢�����һ�п�ͷ
  in.read(readData[1], STR_LEN);
  assert(strcmp(readData[1], "�����Ҽ������һ�����ԭ�����Լ���")
      == 0);
  
  // ���Զ�λ�������ڶ��ļ�ʹ��operator[]��  
  in.seekg(3 * STR_LEN); // ��λ���ļ��д洢�ĵ�4���ı���ͷ
  in.read(readData[2], STR_LEN); // ��ȡ��4���ı�
  assert(strcmp(readData[2], "�������ĺ��ӡ�") == 0);  

  // �ӵ�ǰλ����󣨷����ƶ�
  in.seekg(-STR_LEN * 2, ios::cur); // �ӵ�4��ĩβ��λ���˵�3�п�ͷ
  in.read(readData[3], STR_LEN);
  assert(strcmp(readData[3], "������׷����ȥ�ĸ��ס�") == 0);

  // ���ļ��Ŀ�ͷ��λ
  in.seekg(1 * STR_LEN, ios::beg);
  in.read(readData[4], STR_LEN); // ��λ���˵�2�п�ͷ
  assert(strcmp(readData[4], "���������������ӷ��������۱��ڣ�")
    == 0);
} ///:~
