#pragma once

#include <vector>
#include <iostream>

#include "Validator.h"
#include "BaseField.h"

template<class T>
class Field : public BaseField
{
public:
    Field(const std::string& messg);

    const T& getValue() const;

    void addValidator(Validator<T>* validator);
    void fill() override;

private:
    T m_field;
	std::vector<Validator<T>*> m_validators;
    bool validate() const override;
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
    std::cout << getMessage();
    std::cin >> m_field;
}

template<class T>
bool Field<T>::validate() const
{
    for (auto validator : m_validators)
        if (!validator->validate(m_field))
            return false;
    return true;
}