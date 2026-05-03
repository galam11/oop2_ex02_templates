#pragma once

#include <vector>
#include <iostream>

#include "Validator.h"
#include "BaseField.h"
#include "macros.h"

template<class T>
class Field : public BaseField
{
public:
    Field(const std::string& messg);

    const T& getValue() const;

    void addValidator(Validator<T>* validator);
    void fill() override;
    void printField(std::ostream &os) const override;
private:
    T m_field;
	std::vector<Validator<T>*> m_validators;
    bool validate() override;
};


template<class T>
Field<T>::Field(const std::string& messg)
    : BaseField(messg)
{
}

template<class T>
const T& Field<T>::getValue() const
{
    return m_field;
}

template<class T>
void Field<T>::addValidator(Validator<T>* validator)
{
    m_validators.push_back(validator);
}

template<class T>
void Field<T>::fill()
{
    std::cout << getMessage() << " >> ";
    std::cin >> m_field;
}

template<class T>
void Field<T>::printField(std::ostream &os) const
{
    os << LINE_SEPERATOR << '\n';

    os << getMessage() << " = " << m_field << '\n';
    if (!isValid())
        os << getErrMessage() << '\n';

    os << LINE_SEPERATOR;
}

template<class T>
bool Field<T>::validate()
{
    clearErrMessage();
    bool valid = true;

    for (auto validator : m_validators)
        if (!validator->validate(m_field))
        {
            appandErrMessage(validator->getErrMessage());
            valid = false;
        }

    return valid;
}

