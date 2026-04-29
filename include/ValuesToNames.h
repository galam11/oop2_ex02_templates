#pragma once
#include <iostream>
#include <string>

template <typename T>
class ValuesToNames
{
public:
    ValuesToNames(int value = 0);

    int getValue() const;
    void setValue(int value);

    std::string valuesAndNames();
private:
    int m_value = 0;
};

template<typename T>
ValuesToNames<T>::ValuesToNames(int value)
    : m_value(value) { }

template<typename T>
int ValuesToNames<T>::getValue() const
{
    return m_value;
}

template<typename T>
void ValuesToNames<T>::setValue(int value)
{
    m_value = value;
}

template<typename T>
std::string ValuesToNames<T>::valuesAndNames()
{
    std::string res = "(";

    for (int i = 1; i < T::SIZE - 1; i ++)
        res += std::to_string(i) + " - " + T::getName(i) + ", ";
    res += std::to_string(T::SIZE - 1) + " - " + T::getName(T::SIZE - 1) + ")";

    return res;
}

template <typename T>
std::istream& operator>>(std::istream& is, ValuesToNames<T>& vtn)
{
    int val;
    if (is >> val)
        vtn.setValue(val);

    return is;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const ValuesToNames<T>& vtn)
{
    std::string name = T::getName(vtn.getValue());
    if (name.empty())
        vtn.getValue();
    else
        os << name;

    return os;
}


