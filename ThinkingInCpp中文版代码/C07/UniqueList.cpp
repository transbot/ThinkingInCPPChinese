//: C07:UniqueList.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ����list��unique()����
#include <iostream>
#include <iterator>
#include <list>
using namespace std;

int a[] = { 1, 3, 1, 4, 1, 5, 1, 6, 1 };
const int ASZ = sizeof a / sizeof *a;

int main() {
    // �������
    ostream_iterator<int> out(cout, " ");
    list<int> li(a, a + ASZ);

    li.unique();
    // Ŷ��û���Ƴ��ظ���
    copy(li.begin(), li.end(), out);
    cout << endl;

    // ����������
    li.sort();
    copy(li.begin(), li.end(), out);
    cout << endl;

    // ����unique()�ͻ���������
    li.unique();
    copy(li.begin(), li.end(), out);
    cout << endl;
} ///:~
