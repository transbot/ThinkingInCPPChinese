//: C05:Urand.h {-bor}
// ���ԡ�C++���˼��, ��2��
// ���ߣ�Bruce Eckel & Chuck Allison
// ���ߣ��ܾ�(bookzhou.com)
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ����������������ɲ��ظ��������
#ifndef URAND_H
#define URAND_H

#include <bitset>
#include <cstddef>
#include <cstdlib>
#include <ctime>

using std::size_t;
using std::bitset;

template<size_t UpperBound> class Urand {
    bitset<UpperBound> used;

public:
    Urand() { srand(time(0)); } // ��ʼ�������    
    size_t operator()();        // ��������������
};

template<size_t UpperBound> 
inline size_t Urand<UpperBound>::operator()() {
    if (used.count() == UpperBound)
        used.reset(); // ���¿�ʼ�����bitset��
    
    size_t newval;

    while (used[newval = rand() % UpperBound])
        ; // ֱ���ҵ����ظ���ֵ
    
    used[newval] = true;
    return newval;
}

#endif // URAND_H ///:~
