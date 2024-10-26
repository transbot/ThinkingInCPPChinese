//: C05:ApplySequence.h
// 作者：Bruce Eckel & Chuck Allison
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// 有关源代码的使用许可，请参阅代码包附带的License.txt文件，
// 该代码包可从www.MindView.net或中文版译者主页bookzhou.com下载。
// 将一个函数应用于STL序列容器

// const、无参、任意返回值类型的成员函数f：
template<class Seq, class T, class R>
void apply(Seq& sq, R (T::*f)() const) {
    typename Seq::iterator it = sq.begin();
    while(it != sq.end())
        ((*it++)->*f)();
}

// const、单个参数、任意返回值类型的成员函数f：
template<class Seq, class T, class R, class A>
void apply(Seq& sq, R(T::*f)(A) const, A a) {
    typename Seq::iterator it = sq.begin();
    while(it != sq.end())
        ((*it++)->*f)(a);
}

// const、两个参数、任意返回值类型的成员函数f：
template<class Seq, class T, class R, class A1, class A2>
void apply(Seq& sq, R(T::*f)(A1, A2) const, A1 a1, A2 a2) {
    typename Seq::iterator it = sq.begin();
    while(it != sq.end())
        ((*it++)->*f)(a1, a2);
}

// 非const、无参、任意返回值类型的成员函数f：
template<class Seq, class T, class R>
void apply(Seq& sq, R (T::*f)()) {
    typename Seq::iterator it = sq.begin();
    while(it != sq.end())
        ((*it++)->*f)();
}

// 非const、单个参数、任意返回值类型的成员函数f：
template<class Seq, class T, class R, class A>
void apply(Seq& sq, R(T::*f)(A), A a) {
    typename Seq::iterator it = sq.begin();
    while(it != sq.end())
        ((*it++)->*f)(a);
}

// 非const、两个参数、任意返回值类型的成员函数f：
template<class Seq, class T, class R, class A1, class A2>
void apply(Seq& sq, R(T::*f)(A1, A2), A1 a1, A2 a2) {
    typename Seq::iterator it = sq.begin();
    while(it != sq.end)
        ((*it++)->*f)(a1, a2);
}
// 等等……以支持可能的最大参数数量  ///:~
