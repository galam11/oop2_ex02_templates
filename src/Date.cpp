#include "Date.h"

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

