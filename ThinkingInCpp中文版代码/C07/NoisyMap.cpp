//: C07:NoisyMap.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��Noisyӳ�䵽Noisy
//{L} Noisy
#include <map>
#include "Noisy.h"
using namespace std;

int main() {
    map<Noisy, Noisy> mnn;
    Noisy n1, n2;
    cout << "\n--------" << endl;
    mnn[n1] = n2;
    cout << "\n--------" << endl;
    cout << mnn[n1] << endl;
    cout << "\n--------" << endl;
} ///:~
