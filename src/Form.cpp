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
        field->fill();
}

bool Form::validateForm()
{
    bool valid = true;
    for (auto field : m_fields)
        if (!field->isValid())
            valid = false;

    if (!valid)
        return false;

    for (const auto formValidator : m_validators)
        if (!formValidator->validate())
            valid = false;

    return valid;
}

void Form::printForm()
{
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    return os;
}
