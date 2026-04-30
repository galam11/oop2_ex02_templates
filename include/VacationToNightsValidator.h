#pragma once

#include "FormValidator.h"

template<class A, class B>
class VacationToNightsValidator : public FormValidator
{
public:
    VacationToNightsValidator(A* a, B* b);

    bool validate() override;
private:
    A* m_a;
    B* m_b;
};

template<class A, class B>
VacationToNightsValidator<A, B>::VacationToNightsValidator(A*a, B *b)
    : m_a(a), m_b(b) { }

template<class A, class B>
bool VacationToNightsValidator<A, B>::validate()
{
    return false;
}
