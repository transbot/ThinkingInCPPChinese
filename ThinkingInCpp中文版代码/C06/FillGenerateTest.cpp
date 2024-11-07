//: C06:FillGenerateTest.cpp
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾ����䡱�͡����ɡ��㷨
//{L} Generators
#include <vector>
#include <algorithm>
#include <string>
#include <ctime> // Ϊ��ÿ�����ж���ò�ͬ�����������
#include "Generators.h"
#include "PrintSequence.h"
using namespace std;

int main() {
    // ������������ӣ��Ա�ÿ�ζ�������v4����䲻ͬ�����������
    std::srand(std::time(nullptr));  

    // ����һ������5��Ԫ�ص�vector������"ɽ��"�������Ԫ��
    vector<string> v1(5);
    fill(v1.begin(), v1.end(), "ɽ��");
    print(v1.begin(), v1.end(), "v1", " ");
    // �����v1:  ɽ�� ɽ�� ɽ�� ɽ�� ɽ��

    // ����һ���յ�vector���������в���7��"����"Ԫ��
    vector<string> v2;
    fill_n(back_inserter(v2), 7, "����");
    print(v2.begin(), v2.end(), "v2", " ");
    // �����v2:  ���� ���� ���� ���� ���� ���� ����

    // ����һ������10��Ԫ�ص�vector����ʹ��SkipGen����������Ԫ��
    // SkipGen���������4��ʼ��ÿ�ε���5������һ������
    vector<int> v3(10);
    generate(v3.begin(), v3.end(), SkipGen(4, 5));
    print(v3.begin(), v3.end(), "v3", " ");
    // �����v3:  4 9 14 19 24 29 34 39 44 49

    // ����һ���յ�vector����ʹ��URandGen����������15�����������ΧΪ0-29��
    vector<int> v4;
    generate_n(back_inserter(v4), 15, URandGen(30));
    print(v4.begin(), v4.end(), "v4", " ");
    // �����v4:  ��������У�ÿ�����н����ͬ��
} ///:~
