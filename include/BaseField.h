#pragma once
#include <string>
#include <iostream>

class BaseField {
public:
    BaseField(const std::string& messg);
    virtual ~BaseField() = default;
    bool isValid() const;

    virtual void printField(std::ostream& os) const = 0;
    bool checkValidation();

    void fillIfNeeded();
    void clear();

private:
    std::string m_message;
    std::string m_errMessage;

    bool m_valid = false;
    bool m_empty = true;

protected:
    const std::string& getMessage() const;
    const std::string& getErrMessage() const;


    void appandErrMessage(std::string err);
    void clearErrMessage();

    virtual bool validate() = 0;
    virtual void fill() = 0;

};

std::ostream& operator<<(std::ostream& os, const BaseField* field);


