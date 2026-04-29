#pragma once
#include <string>
#include <vector>
#include <iostream>

#include "Validator.h"

template<class T>
class Field
{
public:
    Field(const std::string& messg);

    void addValidator(Validator<T>* validator);
    void fill();
    bool isValid();
private:
    T m_field;
    std::string m_message;
	std::vector<Validator<T>*> m_validators;
};


template<class T>
Field<T>::Field(const std::string& messg)
    : m_message(messg)
{
}

template<class T>
void Field<T>::addValidator(Validator<T>* validator)
{
    m_validators.push_back(validator);
}

template<class T>
void Field<T>::fill()
{
    std::cout << m_message;
    std::cin >> m_field;
}

template<class T>
bool Field<T>::isValid()
{
    for (auto validator : m_validators)
        if (!validator->validate(m_field))
            return false;
    return true;
}