#include "BaseField.h"

BaseField::BaseField(const std::string &messg)
    : m_message(messg) { }

const std::string& BaseField::getMessage()
{
    return m_message;
}

bool BaseField::isValid()
{
    if (!m_valid && validate())
        m_valid = true;

    return m_valid;
}

std::string BaseField::getErrMessage()
{
    return m_errMessage;
}

void BaseField::appandErrMessage(std::string err)
{
    if (m_errMessage != "")
        m_errMessage += "\n\n";

    m_errMessage += err;
}