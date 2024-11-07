//: C06:BinderValue.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ���󶨡�ʵ���ǿɱ��
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <cstdlib>
using namespace std;

// �ú�������0-99���������
// ����Ժܲ�μ��������İ��޸ĺ��BinderValue_CPP20.cpp����
int boundedRand() { return rand() % 100; }

int main() {
    const int SZ = 20;

    // Ӧʹ��vector�����滻C������飬����ߴ���İ�ȫ�ԡ�����ԣ�
    // ���������ִ� C++ �ı�̷�񡣲μ��������İ��޸ĺ��BinderValue_CPP20.cpp����
    int a[SZ], b[SZ] = {0};

    // ����20�������
    generate(a, a + SZ, boundedRand);

    // ��0-99�����ѡ��һ������Ϊ���ֵ������
    int val = boundedRand();

    // �Ƴ�����val��Ԫ�أ�ʣ��Ԫ�ؿ�����b���顣
    // bind2nd�����ã��μ��������İ��޸ĺ��BinderValue_CPP20.cpp����
    int* end = remove_copy_if(a, a + SZ, b, bind2nd(greater<int>(), val));
    
    // �������������
    sort(a, a + SZ);
    sort(b, end);

    // ������
    ostream_iterator<int> out(cout, " ");
    cout << "ԭʼ���У�" << endl;
    copy(a, a + SZ, out);
    cout << endl;

    cout << "С�ڵ���" << val << "��ֵ��" << endl;
    copy(b, end, out);
    cout << endl;
}
