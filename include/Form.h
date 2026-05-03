#pragma once

#include <vector>
#include <iostream>


class BaseField;
class FormValidator;

class Form {
public:
    Form() = default;

    void addField(BaseField* field);
    void addValidator(FormValidator* validator);

    void fillForm() const;
    bool validateForm();

    void printForm(std::ostream& os) const;

private:
    std::vector<BaseField*> m_fields;
    std::vector<FormValidator*> m_validators;

    bool m_validFields = false;
};

std::ostream& operator<<(std::ostream& os, const Form& form);