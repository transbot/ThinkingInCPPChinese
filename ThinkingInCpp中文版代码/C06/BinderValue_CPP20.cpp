//: C06:BinderValue_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ԭ�����ĸĶ���
// - ��boundedRand()�У�ʹ��������ԡ��ɶ����ԺͿ���ֲ�Ը��ѵ������������
// - ʹ��lambda���ʽ�滻��ʱ��bind2nd
// - ʹ��vector�滻��C��������
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <random>
#include <vector>

using namespace std;

// �ú�������0-99���������ʹ�ø��ִ��������������
int boundedRand() {
    // ʹ��Mersenne Twister��Ϊ���������
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 99);
    return dis(gen);
}

int main() {
    const int SZ = 20;
    vector<int> a(SZ), b(SZ);

    // ����20�������
    generate(a.begin(), a.end(), boundedRand);

    // ��0-99�����ѡ��һ������Ϊ���ֵ������
    int val = boundedRand();

    // �Ƴ�����val��Ԫ�أ�ʣ��Ԫ�ؿ�����b����
    auto end = remove_copy_if(a.begin(), a.end(), b.begin(), [val](int x) { return x > val; });

    // �������������
    sort(a.begin(), a.end());
    sort(b.begin(), end);

    // ������    
    ostream_iterator<int> out(cout, " ");
    cout << "ԭʼ���У�" << endl;
    copy(a.begin(), a.end(), out);
    cout << endl;

    cout << "С�ڵ���" << val << "��ֵ��" << endl;
    copy(b.begin(), end, out);
    cout << endl;

}