//: C06:PtrFun1_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾʹ�����ּ����������ʱ��ptr_fun()��
// ���Ƕ��ܡ���װ��һ��������
#include <algorithm>
#include <cmath>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int d[] = { 123, 94, 10, 314, 315 };
const int DSZ = sizeof d / sizeof *d;

// �ú����ж�ʵ���ǲ���ż�����Ǿͷ���true��1���������򷵻�false��0��
bool isEven(int x) { return x % 2 == 0; }

void printResults(const vector<bool>& vb) {
    copy(vb.begin(), vb.end(), ostream_iterator<bool>(cout, " "));
    cout << endl;
}

int main() {
    // ʹ��lambda���ʽ
    vector<bool> vb1;
    transform(d, d + DSZ, back_inserter(vb1),
              [](int x) { return !isEven(x); });
    cout << "lambda���ʽ���: ";
    printResults(vb1);

    // ʹ��std::function
    vector<bool> vb2;
    transform(d, d + DSZ, back_inserter(vb2),
              std::function<bool(int)>([](int x) { return !isEven(x); }));
    cout << "std::function ���: ";
    printResults(vb2);

    // ʹ��std::bind
    vector<bool> vb3;
    transform(d, d + DSZ, back_inserter(vb3),
              std::bind(std::logical_not<bool>(), std::bind(isEven, std::placeholders::_1)));
    cout << "std::bind���: ";
    printResults(vb3);

    return 0;
}