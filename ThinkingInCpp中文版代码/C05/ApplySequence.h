//: C05:ApplySequence.h
// ���ߣ�Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// �й�Դ�����ʹ����ɣ�����Ĵ����������License.txt�ļ���
// �ô�����ɴ�www.MindView.net�����İ�������ҳbookzhou.com���ء�
// ��һ������Ӧ����STL��������

// const���޲Ρ����ⷵ��ֵ���͵ĳ�Ա����f��
template<class Seq, class T, class R>
void apply(Seq& sq, R (T::*f)() const) {
    typename Seq::iterator it = sq.begin();
    while(it != sq.end())
        ((*it++)->*f)();
}

// const���������������ⷵ��ֵ���͵ĳ�Ա����f��
template<class Seq, class T, class R, class A>
void apply(Seq& sq, R(T::*f)(A) const, A a) {
    typename Seq::iterator it = sq.begin();
    while(it != sq.end())
        ((*it++)->*f)(a);
}

// const���������������ⷵ��ֵ���͵ĳ�Ա����f��
template<class Seq, class T, class R, class A1, class A2>
void apply(Seq& sq, R(T::*f)(A1, A2) const, A1 a1, A2 a2) {
    typename Seq::iterator it = sq.begin();
    while(it != sq.end())
        ((*it++)->*f)(a1, a2);
}

// ��const���޲Ρ����ⷵ��ֵ���͵ĳ�Ա����f��
template<class Seq, class T, class R>
void apply(Seq& sq, R (T::*f)()) {
    typename Seq::iterator it = sq.begin();
    while(it != sq.end())
        ((*it++)->*f)();
}

// ��const���������������ⷵ��ֵ���͵ĳ�Ա����f��
template<class Seq, class T, class R, class A>
void apply(Seq& sq, R(T::*f)(A), A a) {
    typename Seq::iterator it = sq.begin();
    while(it != sq.end())
        ((*it++)->*f)(a);
}

// ��const���������������ⷵ��ֵ���͵ĳ�Ա����f��
template<class Seq, class T, class R, class A1, class A2>
void apply(Seq& sq, R(T::*f)(A1, A2), A1 a1, A2 a2) {
    typename Seq::iterator it = sq.begin();
    while(it != sq.end)
        ((*it++)->*f)(a1, a2);
}
// �ȵȡ�����֧�ֿ��ܵ�����������  ///:~
