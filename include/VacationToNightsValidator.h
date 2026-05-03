#pragma once

#include "FormValidator.h"

template<class A, class B>
class VacationToNightsValidator : public FormValidator
{
public:
    VacationToNightsValidator(A* a, B* b);

    bool validate() override;

    std::string buildErrMessage() const override;
private:
    A* m_vacationField;
    B* m_nightsField;

    bool m_midWeekNightsContErr = false;
    bool m_weekEndNightsContErr = false;
};

template<class A, class B>
VacationToNightsValidator<A, B>::VacationToNightsValidator(A*a, B *b)
    : m_vacationField(a), m_nightsField(b) { }

template<class A, class B>
bool VacationToNightsValidator<A, B>::validate()
{
    int vacationVal = m_vacationField->getValue().getValue();
    int nights = m_nightsField->getValue();

    m_midWeekNightsContErr = vacationVal == 1 && nights < 3;
    m_weekEndNightsContErr = vacationVal == 2 && (nights < 1 || nights > 5);

    if (m_midWeekNightsContErr || m_weekEndNightsContErr)
    {
        m_vacationField->clear();
        m_nightsField->clear();
        return false;
    }

    return true;
}

template<class A, class B>
std::string VacationToNightsValidator<A, B>::buildErrMessage() const
{
    return (m_midWeekNightsContErr ? MID_WEEK_NIGHTS_CONT_ERR_MSG : "") +
        (m_weekEndNightsContErr ? "\n" + WEEK_END_NIGHTS_CONT_ERR_MSG : "");
}
