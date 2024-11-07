//: C06:MemFun2.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ͨ���������õ��ó�Ա����
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
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
    for(int i = 0; i < 50; i += 10)
        va.push_back(Angle(i));   // �õ�0, 10, 20, 30, 40
    int x[] = { 1, 2, 3, 4, 5 };  // ׼������Щֵ���Ըղŵ�vector�еĶ�ӦԪ��

    // ʹ��mem_fun_ref��Angle::mul��Ա��������Ϊ�ɵ��ö���
    // �����ݸ�transform����vector��ÿ��Angle�������mul������
    // ��������Զ�Ӧ��xֵ��������������
    transform(va.begin(), va.end(), x,
              ostream_iterator<int>(cout, " "),
              mem_fun_ref(&Angle::mul));
    cout << endl;
    // ���: 0 20 60 120 200
} ///:~
