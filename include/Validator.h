#pragma once
#include <string>

template <class T>
class Validator
{
public:
	virtual ~Validator() = default;

	virtual bool validate(const T& value) = 0;

	virtual std::string getErrMessage() = 0;
};