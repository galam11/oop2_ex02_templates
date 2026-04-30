#pragma once

#include "FormValidator.h"
#include "Field.h"

class CapacityValidator : public FormValidator
{
public:
    CapacityValidator(Field<int>* totalPeople, Field<int>* adults,
        Field<int>* kids, Field<int>* pairRooms, Field<int>* familyRooms);

    bool validate() override;
private:
    Field<int>* m_totalPeople;
    Field<int>* m_adults;
    Field<int>* m_kids;
    Field<int>* m_pairRooms;
    Field<int>* m_familyRooms;
};
