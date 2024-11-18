//: C07:RawStorageIterator.cpp {-bor}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾraw_storage_iterator���÷�
//{L} Noisy
#include <iostream>
#include <iterator>
#include <algorithm>
#include "Noisy.h"
using namespace std;

int main() {
    const int QUANTITY = 10;
    // ����ԭʼ�洢��ת��ΪĿ������
    Noisy* np = reinterpret_cast<Noisy*>(
        new char[QUANTITY * sizeof(Noisy)]);
    raw_storage_iterator<Noisy*, Noisy> rsi(np);
    for(int i = 0; i < QUANTITY; i++)
        *rsi++ = Noisy(); // ���������洢��
    cout << endl;
    copy(np, np + QUANTITY,
         ostream_iterator<Noisy>(cout, " "));
    cout << endl;
    // ��ʽ������������������Դ����
    for(int j = 0; j < QUANTITY; j++)
        (&np[j])->~Noisy();
    // �ͷ�ԭʼ�洢
    delete reinterpret_cast<char*>(np);
} ///:~
