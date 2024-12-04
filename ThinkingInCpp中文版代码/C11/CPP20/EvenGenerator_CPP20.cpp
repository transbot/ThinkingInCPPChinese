//: C11:EvenGenerator_CPP20.cpp
//  ���̳߳�ͻʱ

#include <iostream>
#include "EvenChecker_CPP20.h"

using namespace std;

class EvenGenerator : public Generator {
    unsigned int currentEvenValue; // �޷������Ͳ������
public:
    EvenGenerator() { currentEvenValue = 0; }
    ~EvenGenerator() { cout << "~EvenGenerator" << endl; }
    int nextValue() {
        ++currentEvenValue; // Σ�յ㣡
        // this_thread::yield(); 
        ++currentEvenValue;
        return currentEvenValue;
    }
};

int main() {
    EvenChecker::test<EvenGenerator>();
} ///:~
