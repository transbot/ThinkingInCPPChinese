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
    // ��һ���ṹ�������澭����ʱ��
    struct Duration {
        int years, months, days;
        Duration(int y, int m, int d)
            : years(y), months(m), days(d) {}
    };

    // һ���쳣��
    struct DateError : public std::logic_error {
        DateError(const std::string& msg = "")
            : std::logic_error(msg) {}
    };

    // ���캯��
    Date();
    Date(int year, int month, int day) throw(DateError);
    Date(const std::string&) throw(DateError);

    // ��ȡ�ꡢ�¡���
    int getYear() const;
    int getMonth() const;
    int getDay() const;

    // ������ת��Ϊ�ַ���
    std::string toString() const;

    // ������������֮��ļ��
    friend Duration duration(const Date&, const Date&);

    // ��Щ��Ԫ���������˱Ƚϲ��������Ա�Ƚ�����
    friend bool operator<(const Date&, const Date&);
    friend bool operator<=(const Date&, const Date&);
    friend bool operator>(const Date&, const Date&);
    friend bool operator>=(const Date&, const Date&);
    friend bool operator==(const Date&, const Date&);
    friend bool operator!=(const Date&, const Date&);

    // ��Щ��Ԫ��������������������������
    friend std::ostream& operator<<(std::ostream&, const Date&);
    friend std::istream& operator>>(std::istream&, Date&);
};
#endif // DATE_H ///:~
