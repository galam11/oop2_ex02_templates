#include "CapacityValidator.h"

CapacityValidator::CapacityValidator(Field<int>* totalPeople, Field<int>* adults,
        Field<int>* kids, Field<int>* pairRooms, Field<int>* familyRooms)
    : m_totalPeople(totalPeople), m_adults(adults),
        m_kids(kids), m_pairRooms(pairRooms), m_familyRooms(familyRooms) { }

bool CapacityValidator::validate()
{
    return false;
}
