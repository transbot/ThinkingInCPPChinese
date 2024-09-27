//: C02:Date.h
#ifndef DATE_H
#define DATE_H

#include <string>
#include <stdexcept>
#include <iosfwd>

class Date {
private:
    int year, month, day;
    int compare(const Date&) const;
    static int daysInPrevMonth(int year, int month);

public:
    // 用一个结构体来保存经过的时间
    struct Duration {
        int years, months, days;
        Duration(int y, int m, int d)
            : years(y), months(m), days(d) {}
    };

    // 一个异常类
    struct DateError : public std::logic_error {
        DateError(const std::string& msg = "")
            : std::logic_error(msg) {}
    };

    // 构造函数
    Date();
    Date(int year, int month, int day) throw(DateError);
    Date(const std::string&) throw(DateError);

    // 获取年、月、日
    int getYear() const;
    int getMonth() const;
    int getDay() const;

    // 将日期转换为字符串
    std::string toString() const;

    // 计算两个日期之间的间隔
    friend Duration duration(const Date&, const Date&);

    // 这些友元函数重载了比较操作符，以便比较日期
    friend bool operator<(const Date&, const Date&);
    friend bool operator<=(const Date&, const Date&);
    friend bool operator>(const Date&, const Date&);
    friend bool operator>=(const Date&, const Date&);
    friend bool operator==(const Date&, const Date&);
    friend bool operator!=(const Date&, const Date&);

    // 这些友元函数重载了输入和输出流操作符
    friend std::ostream& operator<<(std::ostream&, const Date&);
    friend std::istream& operator>>(std::istream&, Date&);
};
#endif // DATE_H ///:~
