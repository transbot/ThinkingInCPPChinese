//: C06:MemFun2_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾʹ�����ּ����������ʱ��mem_fun_ref��
// std::mem_fn��lambda���ʽ��
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Angle {
    int degrees;
public:
    Angle(int deg) : degrees(deg) {}
    int mul(int times) { return degrees *= times; }    
};

int main() {
    vector<Angle> va;
    for (int i = 0; i < 50; i += 10)
        va.push_back(Angle(i));   // �õ�0, 10, 20, 30, 40
    int x[] = { 1, 2, 3, 4, 5 };  // ׼������Щֵ���Ըղŵ�vector�еĶ�ӦԪ��

    // ʹ��lambda���ʽ
    cout << "lambda���ʽ���: ";
    transform(va.begin(), va.end(), x, ostream_iterator<int>(cout, " "),
              [](Angle& angle, int times) { return angle.mul(times); });
    cout << endl;
    // ���: 0 20 60 120 200

    // ʹ��std::mem_fn    
    vector<Angle> vb;
    for (int i = 0; i < 50; i += 10)
        vb.push_back(Angle(i));   // �õ�0, 10, 20, 30, 40
    cout << "std::mem_fn���: ";
    transform(vb.begin(), vb.end(), x,
              ostream_iterator<int>(cout, " "),
              mem_fn(&Angle::mul));
    cout << endl;
    // ���: 0 20 60 120 200

    return 0;
}