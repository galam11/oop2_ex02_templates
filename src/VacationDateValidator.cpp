#include "VacationDateValidator.h"

VacationDateValidator::VacationDateValidator(const Date &date)
    : m_currentDate(date) { }


bool VacationDateValidator::validate(const Date &value)
{
    return value > m_currentDate && value.getYear() == m_currentDate.getYear();
}

std::string VacationDateValidator::getErrMessage()
{
    return "\tError: Date must be in the future and within the current year.";
}
