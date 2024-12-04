//: C11:EvenGenerator_CPP20.cpp
//  当线程冲突时

#include <iostream>
#include "EvenChecker_CPP20.h"

using namespace std;

class EvenGenerator : public Generator {
    unsigned int currentEvenValue; // 无符号整型不会溢出
public:
    EvenGenerator() { currentEvenValue = 0; }
    ~EvenGenerator() { cout << "~EvenGenerator" << endl; }
    int nextValue() {
        ++currentEvenValue; // 危险点！
        // this_thread::yield(); 
        ++currentEvenValue;
        return currentEvenValue;
    }
};

int main() {
    EvenChecker::test<EvenGenerator>();
} ///:~
