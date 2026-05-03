#include "FormValidator.h"

bool FormValidator::checkValidation()
{
    m_valid = validate();
    return m_valid;
}

bool FormValidator::isValid() const
{
    return m_valid;
}

std::ostream& operator<<(std::ostream &os, const FormValidator &date)
{
    date.print(os);
    return os;
}

void FormValidator::print(std::ostream &os) const
{
    os << buildErrMessage();
}