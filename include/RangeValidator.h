#pragma once
#include "Validator.h"
#include <string>

template <class T>
class RangeValidator : public Validator<T>
{
public:
    RangeValidator(const T& min, const T& max, const std::string& message);

    bool validate(const T& value) override;

    std::string getErrMessage() override;
private:
    T m_min, m_max;
    std::string m_message;
};

template<class T>
RangeValidator<T>::RangeValidator(const T &min, const T &max, const std::string& message)
    : m_min(min), m_max(max) , m_message(message) { }

template<class T>
bool RangeValidator<T>::validate(const T &value)
{
    return value > m_min && value < m_max;
}

template<class T>
std::string RangeValidator<T>::getErrMessage()
{
    return m_message;
}
