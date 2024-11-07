//: C06:CopyStrings_CPP20.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
#include <iostream>
using namespace std;

int main() {
    // ʹ��lambda���ʽ����һ��ν�ʺ���
    // ��auto gt_n = [](int n) { return n > 4; };�Ľ��ͣ�
    //   - auto���ñ������Զ��ƶ����ͣ�������ƶ�Ϊһ���ɵ��ö���
    //   - []�������б�����û�в����κ��ⲿ������
    //   - (int n)�������б���ʾ��������һ��int������
    //   - return n > 4;�������壬����һ������ֵ����ʾn�Ƿ����4��
    auto  gt_n = [](int n) { return n > 4; };

    cout << gt_n(3) << endl; // ��ӡ0
    cout << gt_n(5) << endl; // ��ӡ1
}