#include "BaseField.h"

BaseField::BaseField(const std::string &messg)
    : m_message(messg) { }


bool BaseField::isValid() const
{
    return m_valid;
}

bool BaseField::checkValidation()
{
    if (!m_valid)
        m_valid = validate();
    return m_valid;
}

void BaseField::clearErrMessage()
{
    m_errMessage = "";
}

void BaseField::appandErrMessage(std::string err)
{
    if (m_errMessage != "")
        m_errMessage += "\n\n";

    m_errMessage += err;
}

const std::string & BaseField::getMessage() const
{
    return m_message;
}

const std::string & BaseField::getErrMessage() const
{
    return m_errMessage;
}

std::ostream& operator<<(std::ostream& os, const BaseField* field)
{
    field->printField(os);
}
