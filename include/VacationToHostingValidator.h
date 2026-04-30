#pragma once

#include "FormValidator.h"

template<class A, class B>
class VacationToHostingValidator : public FormValidator
{
public:
    VacationToHostingValidator(A* a, B* b);

    bool validate() override;
private:
    A* m_a;
    B* m_b;
};

template<class A, class B>
VacationToHostingValidator<A, B>::VacationToHostingValidator(A*a, B *b)
    : m_a(a), m_b(b) { }

template<class A, class B>
bool VacationToHostingValidator<A, B>::validate()
{
    return false;
}
