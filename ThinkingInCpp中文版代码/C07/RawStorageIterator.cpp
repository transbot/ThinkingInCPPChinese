//: C07:RawStorageIterator.cpp {-bor}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
// Demonstrate the raw_storage_iterator.
//{L} Noisy
#include <iostream>
#include <iterator>
#include <algorithm>
#include "Noisy.h"
using namespace std;

int main() {
  const int QUANTITY = 10;
  // Create raw storage and cast to desired type:
  Noisy* np = reinterpret_cast<Noisy*>(
    new char[QUANTITY * sizeof(Noisy)]);
  raw_storage_iterator<Noisy*, Noisy> rsi(np);
  for(int i = 0; i < QUANTITY; i++)
    *rsi++ = Noisy(); // Place objects in storage
  cout << endl;
  copy(np, np + QUANTITY,
    ostream_iterator<Noisy>(cout, " "));
  cout << endl;
  // Explicit destructor call for cleanup:
  for(int j = 0; j < QUANTITY; j++)
    (&np[j])->~Noisy();
  // Release raw storage:
  delete reinterpret_cast<char*>(np);
} ///:~
