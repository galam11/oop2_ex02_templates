#pragma once

#include "FormValidator.h"
#include "macros.h"

template<class A, class B>
class VacationToHostingValidator : public FormValidator
{
public:
    VacationToHostingValidator(A* a, B* b);

    bool validate() override;
private:
    std::string buildErrMessage() const override;

    A* m_vacationField;
    B* m_hostingField;

    bool m_weekendBreakFastErr = false;
    bool m_midWeekFullBoardErr = false;
};

template<class A, class B>
VacationToHostingValidator<A, B>::VacationToHostingValidator(A*a, B *b)
    : m_vacationField(a), m_hostingField(b) { }

template<class A, class B>
bool VacationToHostingValidator<A, B>::validate()
{
    int vacationVal = m_vacationField->getValue().getValue();
    int hostingVal = m_hostingField->getValue().getValue();

    m_weekendBreakFastErr = vacationVal == 1 && hostingVal == 1;
    m_midWeekFullBoardErr = vacationVal == 2 && hostingVal == 3;

    if (m_midWeekFullBoardErr || m_weekendBreakFastErr)
    {
        m_vacationField->clear();
        m_hostingField->clear();
        return false;
    }

    return true;
}

template<class A, class B>
std::string VacationToHostingValidator<A, B>::buildErrMessage() const
{
    return (m_weekendBreakFastErr ? WEEKEND_BREAK_FAST_ERR_MSG : "") +
        (m_midWeekFullBoardErr ? "\n" + MID_WEEK_FULL_BOARD_ERR_MSG : "");
}
