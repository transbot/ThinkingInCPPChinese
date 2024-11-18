//: C07:Valarray2.cpp {-bor}{-dmc}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ��ʾ��Ƭ������
#include "PrintValarray.h"
using namespace std;

int main() {
    int data[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
    valarray<int> v(data, 12);

    // ʹ����Ƭ��ȡһ���Ӽ�
    valarray<int> r1(v[slice(0, 4, 3)]);
    print("slice(0,4,3)", r1);

    // ������ȡ
    valarray<int> r2(v[v > 6]);
    print("����6��Ԫ��", r2);

    /* ���һ�е�ƽ��
       ע�⣬����valarray��Ϊ��ά�����һάչ����ʽ��
       ��ôslice��������������ȡ�߼��ϵġ��С���
       ���磬{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }����չ����4x3�����飺
       1  2  3
       4  5  6
       7  8  9
       10 11 12
       slice(0, 3, 4)��valarray��λ��0��ʼ���Բ���3��ȡ�ܹ�4��Ԫ�ص�һ���Ӽ���
       �����ÿ�����ȡ��������ġ���һ�С�����{ 1, 4, 7, 10}�� */
    v[slice(0, 4, 3)] *= valarray<int>(v[slice(0, 4, 3)]);
    print("��һ����ƽ����", v);

    // �ָ���һ��
    int idx[] = { 1, 4, 7, 10 };
    valarray<int> save(idx, 4);
    v[slice(0, 4, 3)] = save;
    print("�ָ����v", v);

    // gslice()���ڶ�ά��Ƭ��������ȡ������ά���Ӽ�
    // ��ȡ��ά�Ӽ���{ { 1, 3, 5 }, { 7, 9, 11 } }
    // ������μ�����
    valarray<size_t> siz(2);
    siz[0] = 2;
    siz[1] = 3;
    valarray<size_t> gap(2);
    gap[0] = 6;
    gap[1] = 2;
    valarray<int> r3(v[gslice(0, siz, gap)]);
    print("��ά��Ƭ", r3);

    // ʹ�ò���������ȡ�Ӽ����������������Ԫ�ر�����bool���ͣ�
    valarray<bool> mask(false, 5);
    mask[1] = mask[2] = mask[4] = true;
    valarray<int> r4(v[mask]);
    print("v[mask]", r4);

    // ʹ������������ȡ�Ӽ������������Ԫ�����ͱ�����size_t���ͣ�
    // ���������е�Ԫ�ر�ʾҪ��ȡ��Ԫ����ԭvalarray�е�����
    size_t idx2[] = { 2, 2, 3, 6 };
    valarray<size_t> mask2(idx2, 4);
    valarray<int> r5(v[mask2]);
    print("v[mask2]", r5);

    // ʹ������������и�ֵ
    valarray<char> text("now is the time", 15);
    valarray<char> caps("NITT", 4);
    valarray<size_t> idx3(4);
    idx3[0] = 0;
    idx3[1] = 4;
    idx3[2] = 7;
    idx3[3] = 11;
    text[idx3] = caps;
    print("����ĸ��д", text);

    return 0;
} ///:~
