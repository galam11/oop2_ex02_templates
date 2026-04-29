#pragma once
#include "Validator.h"
#include <cstdint>

class IdValidator : public Validator<uint32_t>
{
public:
    bool validate(const uint32_t& value) override;
};