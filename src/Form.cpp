#include "Form.h"

#include <macros.h>

#include "BaseField.h"
#include "FormValidator.h"


void Form::addField(BaseField* field)
{
    m_fields.push_back(field);
}

void Form::addValidator(FormValidator* validator)
{
    std::cout<< "Heare!" << std::endl;
   m_validators.push_back(validator);
}

void Form::fillForm() const
{
    for (auto field : m_fields)
        field->fillIfNeeded();
}

bool Form::validateForm()
{
    bool valid = true;
    for (auto field : m_fields)
        if (!field->checkValidation())
            valid = false;

    m_validFields = valid;

    if (!valid)
        return false;

    for (const auto formValidator : m_validators)
        if (!formValidator->checkValidation())
            valid = false;

    return valid;
}

void Form::printForm(std::ostream& os) const
{
    if (m_fields.empty()) return;

    os << m_fields[0];
    for (int i = 1; i < m_fields.size(); i++)
        os << '\n' << m_fields[i];

    if (m_validFields)
    {
        for (auto validator : m_validators)
        {
            os << '\n' << (*validator);
        }
    }


}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    form.printForm(os);
    return os;
}
