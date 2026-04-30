#pragma once

class FormValidator
{
public:
	virtual ~FormValidator() = default;

	virtual bool validate() = 0;
};