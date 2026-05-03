#include "CapacityValidator.h"

CapacityValidator::CapacityValidator(Field<int>* totalPeople, Field<int>* adults,
        Field<int>* kids, Field<int>* pairRooms, Field<int>* familyRooms)
    : m_totalPeople(totalPeople), m_adults(adults),
        m_kids(kids), m_pairRooms(pairRooms), m_familyRooms(familyRooms) { }

bool CapacityValidator::validate()
{

    if (m_pairRooms->getValue() <= 0 && m_familyRooms->getValue() <= 0)
        return false;

    if (m_totalPeople->getValue() != m_kids->getValue() + m_adults->getValue())
        return false;

    if (m_totalPeople->getValue() > m_pairRooms->getValue() * 2 + m_familyRooms->getValue() * 5)
        return false;

    if (m_totalPeople->getValue() < m_pairRooms->getValue() + m_familyRooms->getValue())
        return false;

    return true;
}
