//: C07:BitSet.cpp {-bor}
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ����bitset��
#include <bitset>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <cstddef>
#include <iostream>
#include <string>
using namespace std;

const int SZ = 32; // ��bitset�Ĵ�С����Ϊ����32��������λ
typedef bitset<SZ> BS; // Ϊbitset<SZ>�������BS

// ����һ�����bitset
template<int bits> bitset<bits> randBitset() {
    // rand()��������16λ�������������������ڳ�ʼ��bitset r�ĵ�16λ
    bitset<bits> r(rand());

    // ͨ��ѭ�����ϵ���rand()��ÿ������16λ�������
    // Ȼ����Щ�����ƴ��������ͨ����λOR�����γ�һ��
    // �����ġ��ܹ���bitsλ�����bitset��
    for(int i = 0; i < bits/16 - 1; i++) {
        r <<= 16; // ����16λ
        // ʹ���µ�16λ�뵱ǰbitset���а�λOR���������ʣ���λ
        r |= bitset<bits>(rand());
    }
    return r; // �������ɵ�bitset
}

int main() {
    srand(time(0)); // ��ʼ�������������

    // �����ͬ��С��bitset���ֽ���
    cout << "sizeof(bitset<16>) = " << sizeof(bitset<16>) << endl;
    cout << "sizeof(bitset<32>) = " << sizeof(bitset<32>) << endl;
    cout << "sizeof(bitset<48>) = " << sizeof(bitset<48>) << endl;
    cout << "sizeof(bitset<64>) = " << sizeof(bitset<64>) << endl;
    cout << "sizeof(bitset<65>) = " << sizeof(bitset<65>) << endl;

    // ��������������ɵ�bitset����32λ��
    BS a(randBitset<SZ>()), b(randBitset<SZ>());

    // ��bitsetת��Ϊunsigned long����
    unsigned long ul = a.to_ulong();
    cout << a << endl; // ���bitset a

    // ���ַ���ת��Ϊbitset
    string cbits("111011010110111");
    cout << "��Ϊ�ַ��� = " << cbits << endl;

    // ʹ�������ַ�������ʼ��bitset
    cout << BS(cbits) << " [BS(cbits)]" << endl;

    // ���ַ���������2��ʼ��ĩβ��������Ӵ�����ʼ��bitset
    cout << BS(cbits, 2) << " [BS(cbits, 2)]" << endl;

    // ���ַ�������2��ʼ������11��������Ӵ�����ʼ��bitset
    cout << BS(cbits, 2, 11) << " [BS(cbits, 2, 11)]" << endl;

    // ���bitset a��b
    cout << a << " [a]" << endl;
    cout << b << " [b]" << endl;

    // ��λAND����
    cout << (a & b) << " [a & b]" << endl;
    cout << (BS(a) &= b) << " [a &= b]" << endl;

    // ��λOR����
    cout << (a | b) << " [a | b]" << endl;
    cout << (BS(a) |= b) << " [a |= b]" << endl;

    // ��λXOR����
    cout << (a ^ b) << " [a ^ b]" << endl;
    cout << (BS(a) ^= b) << " [a ^= b]" << endl;
    cout << a << " [a]" << endl; // ���ο�

    // �߼����Ʋ�������0��䣩
    cout << (BS(a) <<= SZ/2) << " [a <<= (SZ/2)]" << endl;
    cout << (a << SZ/2) << endl;
    cout << a << " [a]" << endl; // ���ο�

    // �߼����Ʋ�������0��䣩
    cout << (BS(a) >>= SZ/2) << " [a >>= (SZ/2)]" << endl;
    cout << (a >> SZ/2) << endl;
    cout << a << " [a]" << endl; // ���ο�

    // ��������λΪ1
    cout << BS(a).set() << " [a.set()]" << endl;

    // ����ĳ���ض�λΪ1
    for(int i = 0; i < SZ; i++)
        if(!a.test(i)) {
            cout << BS(a).set(i) << " [a.set(" << i <<")]" << endl;
            break; // ֻ��һ������
        }

    // ��������λΪ0
    cout << BS(a).reset() << " [a.reset()]" << endl;

    // ����ĳ���ض�λΪ0
    for(int j = 0; j < SZ; j++)
        if(a.test(j)) {
            cout << BS(a).reset(j) << " [a.reset(" << j <<")]" << endl;
            break; // ֻ��һ������
        }

    // ��ת����λ
    cout << BS(a).flip() << " [a.flip()]" << endl;

    // ��λȡ��
    cout << ~a << " [~a]" << endl;
    cout << a << " [a]" << endl; // ���ο�

    // ��תĳ���ض�λ
    cout << BS(a).flip(1) << " [a.flip(1)]" << endl;

    // ����һ���յ�bitset
    BS c;
    cout << c << " [c]" << endl;

    // ���bitset c��ͳ����Ϣ
    cout << "c.count() = " << c.count() << endl;
    cout << "c.any() = " << (c.any() ? "true" : "false") << endl;
    cout << "c.none() = " << (c.none() ? "true" : "false") << endl;

    // ����ĳЩλ������Ϊ1��
    c[1].flip(); c[2].flip();
    cout << c << " [c]" << endl;
    cout << "c.count() = " << c.count() << endl;
    cout << "c.any() = " << (c.any() ? "true" : "false") << endl;
    cout << "c.none() = " << (c.none() ? "true" : "false") << endl;

    // ������������
    c.reset();
    for(size_t k = 0; k < c.size(); k++)
        if(k % 2 == 0)
            c[k].flip();
    cout << c << " [c]" << endl;

    // ����bitset c
    c.reset();

    // �������ĳЩλ
    for(size_t ii = 0; ii < c.size(); ii++)
        c[ii] = (rand() % 100) < 25;
    cout << c << " [c]" << endl;

    // ���ĳһλ�Ƿ�Ϊ1
    if(c[1])
        cout << "c[1] == true" << endl;
    else
        cout << "c[1] == false" << endl;
} ///:~