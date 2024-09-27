//: C02:Date1.h
// ��Ϊ�Ƕ�Date.h�ĳ��γ��ԣ���������ΪDate1.h
#ifndef DATE1_H
#define DATE1_H
#include <string>

class Date {
public:
    // ��һ���ṹ�������澭����ʱ��
    struct Duration {
        int years;   // ��
        int months;  // ��
        int days;    // ��
        
        Duration(int y, int m, int d)
            : years(y), months(m), days(d) {}  // ���캯��
    };
    
    Date();  // Ĭ�Ϲ��캯��
    Date(int year, int month, int day);  // �������Ĺ��캯��
    Date(const std::string&);  // ���ַ�������
    
    // ��ȡ�ꡢ�¡���
    int getYear() const; 
    int getMonth() const; 
    int getDay() const; 
    
    // ������ת��Ϊ�ַ���
    std::string toString() const;  
    
    // ��Щ��Ԫ���������˱Ƚϲ��������Ա�Ƚ�����
    friend bool operator<(const Date&, const Date&);
    friend bool operator>(const Date&, const Date&);
    friend bool operator<=(const Date&, const Date&);
    friend bool operator>=(const Date&, const Date&);
    friend bool operator==(const Date&, const Date&);
    friend bool operator!=(const Date&, const Date&);
    
    // ������������֮��ļ��
    friend Date::Duration duration(const Date&, const Date&);
};

#endif // DATE1_H ///:~
