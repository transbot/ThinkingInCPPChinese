//: C07:VectorCoreDump.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ʹ������ʧЧ
#include <iterator>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vi(10, 0);
    ostream_iterator<int> out(cout, " ");
    vector<int>::iterator i = vi.begin();
    *i = 47;
    copy(vi.begin(), vi.end(), out);
    cout << endl;
    // ǿ�����ƶ��ڴ棨Ҳ���Լ򵥵�����㹻��Ķ���
    vi.resize(vi.capacity() + 1);
    // ��ʱiָ�������ڴ棺
    *i = 48; // ����Υ��
    copy(vi.begin(), vi.end(), out); // vi[0]û�б仯
} ///:~
