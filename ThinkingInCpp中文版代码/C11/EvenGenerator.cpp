//: C11:EvenGenerator.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ���̳߳�ͻʱ
//{L} ZThread
#include <iostream>
#include "EvenChecker.h"
#include "zthread/ThreadedExecutor.h"

using namespace ZThread;
using namespace std;

class EvenGenerator : public Generator {
    unsigned int currentEvenValue; // �޷������Ͳ������
public:
    EvenGenerator() { currentEvenValue = 0; }
    ~EvenGenerator() { cout << "~EvenGenerator" << endl; }
    int nextValue() {
        ++currentEvenValue; // Σ�յ㣡
        ++currentEvenValue;
        return currentEvenValue;
    }
};

int main() {
    EvenChecker::test<EvenGenerator>();
} ///:~
