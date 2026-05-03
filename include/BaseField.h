#pragma once
#include <string>

class BaseField {
public:
    BaseField(const std::string& messg);
    virtual ~BaseField() = default;
    virtual void fill() = 0;
    bool isValid();

    std::string getErrMessage();
private:
    std::string m_message;
    bool m_valid = false;

    std::string m_errMessage;

protected:
    virtual bool validate() const = 0;

    const std::string& getMessage();
    void appandErrMessage(std::string err);
};





