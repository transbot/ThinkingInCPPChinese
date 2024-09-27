//: C02:Date1.h
// 因为是对Date.h的初次尝试，所以命名为Date1.h
#ifndef DATE1_H
#define DATE1_H
#include <string>

class Date {
public:
    // 用一个结构体来保存经过的时间
    struct Duration {
        int years;   // 年
        int months;  // 月
        int days;    // 日
        
        Duration(int y, int m, int d)
            : years(y), months(m), days(d) {}  // 构造函数
    };
    
    Date();  // 默认构造函数
    Date(int year, int month, int day);  // 带参数的构造函数
    Date(const std::string&);  // 从字符串构造
    
    // 获取年、月、日
    int getYear() const; 
    int getMonth() const; 
    int getDay() const; 
    
    // 将日期转换为字符串
    std::string toString() const;  
    
    // 这些友元函数重载了比较操作符，以便比较日期
    friend bool operator<(const Date&, const Date&);
    friend bool operator>(const Date&, const Date&);
    friend bool operator<=(const Date&, const Date&);
    friend bool operator>=(const Date&, const Date&);
    friend bool operator==(const Date&, const Date&);
    friend bool operator!=(const Date&, const Date&);
    
    // 计算两个日期之间的间隔
    friend Date::Duration duration(const Date&, const Date&);
};

#endif // DATE1_H ///:~
