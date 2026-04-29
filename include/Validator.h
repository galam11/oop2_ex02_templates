#pragma once

template <class T>
class Validator
{
public:
	virtual ~Validator() = default;

	virtual bool validate(const T& value) = 0;
};