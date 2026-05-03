#pragma once

#include "FormValidator.h"

template<class A, class B>
class VacationToNightsValidator : public FormValidator
{
public:
    VacationToNightsValidator(A* a, B* b);

    bool validate() override;
private:
    A* m_vacationField;
    B* m_nightsField;
};

template<class A, class B>
VacationToNightsValidator<A, B>::VacationToNightsValidator(A*a, B *b)
    : m_vacationField(a), m_nightsField(b) { }

template<class A, class B>
bool VacationToNightsValidator<A, B>::validate()
{
    int vacationVal = m_vacationField->getValue().getValue();
    int nights = m_nightsField->getValue();

    if (vacationVal == 1 && nights < 3)
        return false;

    if (vacationVal == 2 && (nights < 1 || nights > 5))
        return false;

    return true;
}
