#pragma once
#include "Validator.h"
#include <string>

class NameValidator : public Validator<std::string>
{
public:
    bool validate(const std::string& value) override;
    std::string getErrMessage() override;
};