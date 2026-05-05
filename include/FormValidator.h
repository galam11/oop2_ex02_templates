#pragma once
#include <string>
#include <ostream>

class FormValidator
{
public:
	virtual ~FormValidator() = default;

	bool checkValidation();
	bool isValid() const;

	void print(std::ostream& os) const;

private:
	bool m_valid = false;

protected:
	virtual bool validate() = 0;
	virtual std::string buildErrMessage() const = 0;

};

std::ostream& operator<<(std::ostream& os, const FormValidator& date);
