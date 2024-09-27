//: C02:Date.cpp {O}
#include "Date.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <algorithm> // 用于swap()
#include <ctime>
#include <cassert>
#include <iomanip>

using namespace std;

namespace {
    const int daysInMonth[][13] = {
        { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
        { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
    };

    inline bool isleap(int y) { // 判断是否闰年
        return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
    }
}

Date::Date() {
    // 获取当前日期
    time_t tval = time(0);
    struct tm *now = localtime(&tval);
    year = now->tm_year + 1900;
    month = now->tm_mon + 1;
    day = now->tm_mday;
}

Date::Date(int yr, int mon, int dy) throw(Date::DateError) {
    if (!(1 <= mon && mon <= 12))
        throw DateError("为Date构造函数提供了无效的“月”");
    if (!(1 <= dy && dy <= daysInMonth[isleap(year)][mon]))
        throw DateError("为Date构造函数提供了无效的“日”");
    year = yr;
    month = mon;
    day = dy;
}

Date::Date(const std::string& s) throw(Date::DateError) {
    // 假设格式为YYYYMMDD
    if (!(s.size() == 8))
        throw DateError("为Date构造函数提供了无效的字符串");
    for (int n = 8; --n >= 0;)
        if (!isdigit(s[n]))
            throw DateError("为Date构造函数提供了无效的字符串");
    string buf = s.substr(0, 4);
    year = atoi(buf.c_str());
    buf = s.substr(4, 2);
    month = atoi(buf.c_str());
    buf = s.substr(6, 2);
    day = atoi(buf.c_str());
    if (!(1 <= month && month <= 12))
        throw DateError("为Date构造函数提供了无效的“月”");
    if (!(1 <= day && day <= daysInMonth[isleap(year)][month]))
        throw DateError("为Date构造函数提供了无效的“日”");
}

int Date::getYear() const { return year; }
int Date::getMonth() const { return month; }
int Date::getDay() const { return day; }

string Date::toString() const {
    ostringstream os;
    os.fill('0');
    os << setw(4) << year
       << setw(2) << month
       << setw(2) << day;
    return os.str();
}

int Date::compare(const Date& d2) const {
    int result = year - d2.year;
    if (result == 0) {
        result = month - d2.month;
        if (result == 0)
            result = day - d2.day;
    }
    return result;
}

int Date::daysInPrevMonth(int year, int month) {
    if (month == 1) {
        --year;
        month = 12;
    }
    else
        --month;
    return daysInMonth[isleap(year)][month];
}

bool operator<(const Date& d1, const Date& d2) {
    return d1.compare(d2) < 0;
}

bool operator<=(const Date& d1, const Date& d2) {
    return d1 < d2 || d1 == d2;
}

bool operator>(const Date& d1, const Date& d2) {
    return !(d1 < d2) && !(d1 == d2);
}

bool operator>=(const Date& d1, const Date& d2) {
    return !(d1 < d2);
}

bool operator==(const Date& d1, const Date& d2) {
    return d1.compare(d2) == 0;
}

bool operator!=(const Date& d1, const Date& d2) {
    return !(d1 == d2);
}

Date::Duration
duration(const Date& date1, const Date& date2) {
    int y1 = date1.year;
    int y2 = date2.year;
    int m1 = date1.month;
    int m2 = date2.month;
    int d1 = date1.day;
    int d2 = date2.day;

    // 计算比较结果
    int order = date1.compare(date2);
    if (order == 0)
        return Date::Duration(0, 0, 0);
    else if (order > 0) {
        // 使date1在date2 之前
        using std::swap;
        swap(y1, y2);
        swap(m1, m2);
        swap(d1, d2);
    }

    int years = y2 - y1;
    int months = m2 - m1;
    int days = d2 - d1;
    assert(years > 0 ||
           years == 0 && months > 0 ||
           years == 0 && months == 0 && days > 0);

    // 做显而易见的修正（必须先调整天数），
    // 如果前一个月是二月，并且天数 < -28，则这是循环的一部分。
    int lastMonth = m2; // 初始化第二个日期的月份
    int lastYear = y2; // 初始化第二个日期的年份

    // 调整天数days，确保它不为负数。
    // 如果days小于零，那么就从前面一个月借天数。
    while (days < 0) {
        // 向月借
        assert(months > 0); // 确保months符合要求，否则无法向前借
        // 获取前一个月的天数，并将其加到 days 上
        days += Date::daysInPrevMonth(lastYear, lastMonth--); 
        --months; // 向前借了天数后，减少一个月
    }

    // 如果在调整天数之后，months变成了负数，那么就需要从前面一年借月份
    if (months < 0) {
        // 向年借
        assert(years > 0);
        months += 12;
        --years;
    }

    // 返回Duration结构体
    return Date::Duration(years, months, days);
}

ostream& operator<<(ostream& os, const Date& d) {
    char fillc = os.fill('0');
    os << setw(2) << d.getMonth() << '–'
       << setw(2) << d.getDay() << '–'
       << setw(4) << setfill(fillc) << d.getYear();
    return os;
}

istream& operator>>(istream& is, Date& d) {
    is >> d.month;
    char dash;
    is >> dash;
    if (dash != '-')
        is.setstate(ios::failbit);
    is >> d.day;
    is >> dash;
    if (dash != '-')
        is.setstate(ios::failbit);
    is >> d.year;
    return is;
} ///:~
