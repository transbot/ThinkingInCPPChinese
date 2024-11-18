//: C07:SimpleGenerators.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�

// ������������������һ����������pair
#include <iostream>
#include <utility>

// �������������Լ���ֵ
template<typename T>
class IncrGen {
    T i;
public:
    IncrGen(T ii) : i(ii) {}
    T operator()() { return i++; }
};

// ������������һ�� STL pair<>
template<typename T1, typename T2>
class PairGen {
    T1 i;
    T2 j;
public:
    PairGen(T1 ii, T2 jj) : i(ii), j(jj) {}
    std::pair<T1,T2> operator()() {
        return std::pair<T1,T2>(i++, j++);
    }
};

namespace std {
    // ����ȫ��operator<<�����ڴ�ӡ�κ� STL pair<>
    template<typename F, typename S>
    ostream& operator<<(ostream& os, const pair<F,S>& p) {
        return os << p.first << "\t" << p.second << endl;
    }
} ///:~
