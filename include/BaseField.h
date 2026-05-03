#pragma once
#include <string>
#include <iostream>

class BaseField {
public:
    BaseField(const std::string& messg);
    virtual ~BaseField() = default;
    virtual void fill() = 0;
    bool isValid() const;

    virtual void printField(std::ostream& os) const = 0;

    bool checkValidation();
private:
    std::string m_message;
    bool m_valid = false;
    std::string m_errMessage;



protected:
    const std::string& getMessage() const;
    const std::string& getErrMessage() const;

    void appandErrMessage(std::string err);
    void clearErrMessage();

    virtual bool validate() = 0;
};


std::ostream& operator<<(std::ostream& os, const BaseField* field);


