#include "Date.h"
#include <iomanip>


Date::Date()
    : Date(0 , 0, 0) { }

Date::Date(int year, int month, int day) :
    m_year(year), m_month(month), m_day(day) { }

Date Date::operator-(int years) const
{
    return Date(m_year - years, m_month, m_day);
}

bool Date::operator<=(const Date& other) const
{
    return *this == other || *this < other;
}

bool Date::operator<(const Date& other) const
{
    if (m_year != other.m_year)
        return m_year < other.m_year;

    if (m_month != other.m_month)
        return m_month < other.m_month;

    return m_day < other.m_day;
}

bool Date::operator>=(const Date& other) const
{
	return !(*this < other);
}

bool Date::operator>(const Date& other) const
{
    return !(*this <= other);
}

bool Date::operator==(const Date& other) const
{
    return m_year == other.m_year && m_month == other.m_month && m_day == other.m_day;
}

bool Date::operator!=(const Date& other) const
{
    return !(*this == other);
}

int Date::getYear() const
{
    return m_year;
}

int Date::getMonth() const
{
    return m_month;
}

int Date::getDay() const
{
    return m_day;
}

void Date::setDate(int year, int month, int day)
{
    m_year = year;
    m_month = month;
    m_day = day;
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{

    os << std::setfill('0')
       << std::setw(4) << date.getYear() << "-"
       << std::setw(2) << date.getMonth() << "-"
       << std::setw(2) << date.getDay();

    return os;
}


std::istream& operator>>(std::istream& is, Date& date)
{
    int y, m, d;
    char dash1, dash2;

    if (is >> y >> dash1 >> m >> dash2 >> d)
    {
        date.setDate(y,m,d);
    }
    return is;
}
