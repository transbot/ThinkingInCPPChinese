//: C05:ApplySequence.h
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Apply a function to an STL sequence container.

// const, 0 arguments, any type of return value:
template<class Seq, class T, class R>
void apply(Seq& sq, R (T::*f)() const) {
  typename Seq::iterator it = sq.begin();
  while(it != sq.end())
    ((*it++)->*f)();
}

// const, 1 argument, any type of return value:
template<class Seq, class T, class R, class A>
void apply(Seq& sq, R(T::*f)(A) const, A a) {
  typename Seq::iterator it = sq.begin();
  while(it != sq.end())
    ((*it++)->*f)(a);
}

// const, 2 arguments, any type of return value:
template<class Seq, class T, class R,
         class A1, class A2>
void apply(Seq& sq, R(T::*f)(A1, A2) const,
    A1 a1, A2 a2) {
  typename Seq::iterator it = sq.begin();
  while(it != sq.end())
    ((*it++)->*f)(a1, a2);
}

// Non-const, 0 arguments, any type of return value:
template<class Seq, class T, class R>
void apply(Seq& sq, R (T::*f)()) {
  typename Seq::iterator it = sq.begin();
  while(it != sq.end())
    ((*it++)->*f)();
}

// Non-const, 1 argument, any type of return value:
template<class Seq, class T, class R, class A>
void apply(Seq& sq, R(T::*f)(A), A a) {
  typename Seq::iterator it = sq.begin();
  while(it != sq.end())
    ((*it++)->*f)(a);
}

// Non-const, 2 arguments, any type of return value:
template<class Seq, class T, class R,
         class A1, class A2>
void apply(Seq& sq, R(T::*f)(A1, A2),
    A1 a1, A2 a2) {
  typename Seq::iterator it = sq.begin();
  while(it != sq.end())
    ((*it++)->*f)(a1, a2);
}
// Etc., to handle maximum likely arguments ///:~
