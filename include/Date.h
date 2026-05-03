#pragma once
#include <iostream>

class Date
{
public:
    Date();
    Date(int year, int month, int day);

    Date operator-(int years) const;

    bool operator<=(const Date&) const;
    bool operator>=(const Date&) const;
    bool operator<(const Date&) const;
    bool operator>(const Date&) const;
    bool operator==(const Date&) const;
    bool operator!=(const Date&) const;

    int getYear() const;
    int getMonth() const;
    int getDay() const;

    void setDate(int year, int month, int day);
private:
    int m_year;
    int m_month;
    int m_day;
};

std::ostream& operator<<(std::ostream& os, const Date& date);
std::istream& operator>>(std::istream& is, Date& date);