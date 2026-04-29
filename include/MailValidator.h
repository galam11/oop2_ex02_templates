#pragma once
#include "Validator.h"
#include <string>

class MailValidator : public Validator<std::string>
{
public:
    bool validate(const std::string& value) override;

private:
    bool validate_name(const std::string& name);
    bool validate_top_level_domain(const std::string& domain);
};