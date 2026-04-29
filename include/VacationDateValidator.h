#pragma once
#include "Validator.h"
#include "Date.h"
#include <string>

class VacationDateValidator : public Validator<Date>
{
public:
    VacationDateValidator(const Date& date);
    bool validate(const Date& value) override;

private:
    Date m_currentDate;
};

