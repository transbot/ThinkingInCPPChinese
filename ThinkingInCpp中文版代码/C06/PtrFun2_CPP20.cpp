//: C06:PtrFun2_CPP20.cpp
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

double d[] = { 1.23, 91.370, 56.661, 23.230, 19.959, 1.0, 3.14159 };
const int DSZ = sizeof d / sizeof *d;

void printResults(const vector<double>& vd) {
    copy(vd.begin(), vd.end(), ostream_iterator<double>(cout, " "));
    cout << endl;
}

int main() {
    // ʹ��Lambda���ʽ
    vector<double> vd1;
    transform(d, d + DSZ, back_inserter(vd1),
              [](double x) { return pow(x, 2.0); });
    cout << "Lambda���ʽ���: ";
    printResults(vd1);

    // ʹ��std::function
    vector<double> vd2;
    transform(d, d + DSZ, back_inserter(vd2),
              std::function<double(double)>([](double x) { return pow(x, 2.0); }));
    cout << "std::function���: ";
    printResults(vd2);

    // ʹ��std::bind
    vector<double> vd3;
    transform(d, d + DSZ, back_inserter(vd3),
        std::bind(static_cast<double(*)(double, double)>(pow), std::placeholders::_1, 2.0));
    cout << "std::bind���: ";
    printResults(vd3);

    return 0;
}