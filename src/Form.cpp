#include "Form.h"
#include "BaseField.h"
#include "FormValidator.h"


void Form::addField(BaseField* field)
{
    m_fields.push_back(field);
}

void Form::addValidator(FormValidator* validator)
{
   m_validators.push_back(validator);
}

void Form::fillForm() const
{
    for (auto field : m_fields)
        if (!field->isValid())
            field->fill();
}

bool Form::validateForm()
{
    bool valid = true;
    for (auto field : m_fields)
        if (!field->checkValidation())
            valid = false;

    if (!valid)
        return false;

    for (const auto formValidator : m_validators)
        if (!formValidator->validate())
            valid = false;

    return valid;
}

void Form::printForm(std::ostream& os) const
{
    if (m_fields.empty()) return;

    os << m_fields[0];
    for (int i = 0; i < m_fields.size(); i++)
        os << '\n' << m_fields[i];
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    form.printForm(os);
    return os;
}
