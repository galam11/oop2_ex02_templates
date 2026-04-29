#pragma once

class Date
{
public:
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

private:
    int m_year;
    int m_month;
    int m_day;
};