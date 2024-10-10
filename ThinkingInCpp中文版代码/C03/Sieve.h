//: C03:Sieve.h
// From "Thinking in C++, Volume 2", by Bruce Eckel & Chuck Allison.
// (c) 1995-2004 MindView, Inc. All Rights Reserved.
// See source code use permissions stated in the file 'License.txt',
// distributed with the code package available at www.MindView.net.
#ifndef SIEVE_H
#define SIEVE_H
#include <cmath>
#include <cstddef>
#include <string>
#include "../TestSuite/Test.h"
using std::size_t;
using std::sqrt;
using std::string;

class SieveTest : public TestSuite::Test {
    string sieveChars;
public:
    // 创建包含50个字符的一个字符串，并将每个元素设置为'P'，P代表质数
    SieveTest() : sieveChars(50, 'P') {}
    
    void run() {
        findPrimes();
        testPrimes();
    }
    
    bool isPrime(int p) {
        if(p == 0 || p == 1) return false;
        int root = int(sqrt(double(p)));
        for(int i = 2; i <= root; ++i)
            if(p % i == 0) return false;
        return true;
    }
    
    void findPrimes() {
        // 根据定义，0和1都不是质数。
        // 因此，将这些元素改为"N"表示非质数。
        sieveChars.replace(0, 2, "NN");
        
        // 遍历数组
        size_t sieveSize = sieveChars.size();
        int root = int(sqrt(double(sieveSize)));
        for(int i = 2; i <= root; ++i)
            // 找出所有倍数
            for(size_t factor = 2; factor * i < sieveSize; ++factor)
                sieveChars[factor * i] = 'N';        
        // 执行到这里， sieveChars字符数组的内容是：
        // NNPPNPNPNNNPNPNNNPNPNNNPNNNNNPNPNNNNNPNNNPNPNNNPNN
    }    
    
    void testPrimes() {
        size_t i = sieveChars.find('P');
        while(i != string::npos) {
            test_(isPrime(i++));
            i = sieveChars.find('P', i);
        }
        
        i = sieveChars.find_first_not_of('P');
        while(i != string::npos) {
            test_(!isPrime(i++));
            i = sieveChars.find_first_not_of('P', i);
        }
    }
};
#endif // SIEVE_H ///:~
