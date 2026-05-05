#include "VacationDateValidator.h"
#include "macros.h"

VacationDateValidator::VacationDateValidator(const Date &date)
    : m_currentDate(date) { }


bool VacationDateValidator::validate(const Date &value)
{
    return value > m_currentDate && value.getYear() == m_currentDate.getYear();
}

std::string VacationDateValidator::getErrMessage()
{
    return VACATION_ERR_MSG;
}
