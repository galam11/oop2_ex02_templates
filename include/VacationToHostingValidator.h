#pragma once

#include "FormValidator.h"

template<class A, class B>
class VacationToHostingValidator : public FormValidator
{
public:
    VacationToHostingValidator(A* a, B* b);

    bool validate() override;
private:
    A* m_vacationField;
    B* m_hostingField;
};

template<class A, class B>
VacationToHostingValidator<A, B>::VacationToHostingValidator(A*a, B *b)
    : m_vacationField(a), m_hostingField(b) { }

template<class A, class B>
bool VacationToHostingValidator<A, B>::validate()
{
    int vacationVal = m_vacationField->getValue().getValue();
    int hostingVal = m_hostingField->getValue().getValue();

    if (vacationVal == 1 && hostingVal == 1)
        return false;

    if (vacationVal == 2 && hostingVal == 3)
        return false;

    return true;
}
