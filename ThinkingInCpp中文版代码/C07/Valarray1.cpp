//: C07:Valarray1.cpp {-bor}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾvalarray�Ļ�������
#include "PrintValarray.h"
using namespace std;

double f(double x) {
    return 2.0 * x - 1.0;
}

int main() {
    double n[] = { 1.0, 2.0, 3.0, 4.0 };
    valarray<double> v(n, sizeof n / sizeof n[0]);
    print("v", v);

    valarray<double> sh(v.shift(1)); // ��������λ����������λ
    print("����1λ", sh);

    valarray<double> acc(v + sh);
    print("���", acc);

    valarray<double> trig(sin(v) + cos(acc));
    print("���Ǻ�������", trig);

    valarray<double> p(pow(v, 3.0));
    print("���η�", p);

    valarray<double> app(v.apply(f)); // ��f����Ӧ����v��ÿ��Ԫ��
    print("f(v)", app);

    valarray<bool> eq(v == app); // �ж�v��app�Ƿ����
    print("v == app��?", eq);

    double x = v.min(); // v����СԪ��
    double y = v.max(); // v�����Ԫ��
    double z = v.sum(); // v������Ԫ��֮��
    cout << "x����С�� = " << x << ", y����� = " << y << ", z���ܺͣ� = " << z << endl;

    return 0;
} ///:~
