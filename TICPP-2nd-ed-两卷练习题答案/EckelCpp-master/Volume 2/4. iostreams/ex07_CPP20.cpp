/*
 字符串流支持简单的转换，但这有一定的代价。编写一个程序，
 对比atoi()和stringstream转换系统，
 体会stringstream所产生的开销。
*/

#include <iostream>
#include <sstream>
#include <ctime>
#include <vector>
#include <string>
#include <chrono>

// 使用 atoi 进行转换
void atoiConversion(const std::vector<std::string>& strings) {
    for (const auto& str : strings) {
        int num = atoi(str.c_str());
        // 不做任何处理，只是为了模拟转换
    }
}

// 使用 std::stringstream 进行转换
void stringstreamConversion(const std::vector<std::string>& strings) {
    for (const auto& str : strings) {
        int num;
        std::stringstream ss(str);
        ss >> num;
        // 不做任何处理，只是为了模拟转换
    }
}

int main() {
    // 定义测试字符串数组
    std::vector<std::string> testStrings;
    for (int i = 0; i < 1000000; ++i) {
        testStrings.push_back(std::to_string(i));
    }

    // 测量atoi转换的时间
    auto startAtoi = std::chrono::high_resolution_clock::now();
    atoiConversion(testStrings);
    auto endAtoi = std::chrono::high_resolution_clock::now();
    auto durationAtoi = std::chrono::duration_cast<std::chrono::milliseconds>(endAtoi - startAtoi);

    // 测量std::stringstream转换的时间
    auto startStrstream = std::chrono::high_resolution_clock::now();
    stringstreamConversion(testStrings);
    auto endStrstream = std::chrono::high_resolution_clock::now();
    auto durationStrstream = std::chrono::duration_cast<std::chrono::milliseconds>(endStrstream - startStrstream);

    // 输出结果
    std::cout << "atoi转换花了 " << durationAtoi.count() << " 毫秒。" << std::endl;
    std::cout << "std::stringstream转换花了 " << durationStrstream.count() << " 毫秒。" << std::endl;

    return 0;
}