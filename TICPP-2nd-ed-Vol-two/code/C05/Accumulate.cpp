//: C05:Accumulate.cpp
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
// Passes a "function" as a parameter at compile time.
#include <iostream>
using namespace std;

// Accumulates the results of F(0)..F(n)
template<int n, template<int> class F> struct Accumulate {
  enum { val = Accumulate<n-1, F>::val + F<n>::val };
};

// The stopping criterion (returns the value F(0))
template<template<int> class F> struct Accumulate<0, F> {
  enum { val = F<0>::val };
};

// Various "functions":
template<int n> struct Identity {
  enum { val = n };
};

template<int n> struct Square {
  enum { val = n*n };
};

template<int n> struct Cube {
  enum { val = n*n*n };
};

int main() {
  cout << Accumulate<4, Identity>::val << endl; // 10
  cout << Accumulate<4, Square>::val << endl;   // 30
  cout << Accumulate<4, Cube>::val << endl;     // 100
} ///:~
