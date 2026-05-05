#include "CapacityValidator.h"

#include <macros.h>

CapacityValidator::CapacityValidator(Field<int>* totalPeople, Field<int>* adults,
                                     Field<int>* kids, Field<int>* pairRooms, Field<int>* familyRooms)
    : m_totalPeople(totalPeople), m_adults(adults),
        m_kids(kids), m_pairRooms(pairRooms), m_familyRooms(familyRooms) { }

bool CapacityValidator::validate()
{
    m_negCountRoomsErr = m_pairRooms->getValue() <= 0 && m_familyRooms->getValue() <= 0;
    m_totalPeopleKidsAdultsErr = m_totalPeople->getValue() != m_kids->getValue() + m_adults->getValue();
    m_totalPeopleTotalRoomsErr = m_totalPeople->getValue() > m_pairRooms->getValue() * 2 + m_familyRooms->getValue() * 5;
    m_roomsToTotalPeopleErr = m_totalPeople->getValue() < m_pairRooms->getValue() + m_familyRooms->getValue();


    if (m_negCountRoomsErr)
    {
        m_pairRooms->clear();
        m_familyRooms->clear();
    }

    if (m_totalPeopleKidsAdultsErr)
    {
        m_totalPeople->clear();
        m_kids->clear();
        m_adults->clear();
    }

    if (m_totalPeopleTotalRoomsErr)
    {
        m_totalPeople->clear();
        m_pairRooms->clear();
        m_familyRooms->clear();
    }

    if (m_roomsToTotalPeopleErr)
    {
        m_totalPeople->clear();
        m_pairRooms->clear();
        m_familyRooms->clear();
    }

    if (m_negCountRoomsErr || m_totalPeopleKidsAdultsErr || m_totalPeopleTotalRoomsErr || m_roomsToTotalPeopleErr)
        return false;

    return true;
}

std::string CapacityValidator::buildErrMessage() const
{
    return 
        (m_negCountRoomsErr         ? NEG_COUNT_ROOMS_ERR_MSG                   : "") +
        (m_totalPeopleKidsAdultsErr ? "\n" + TOTAL_PEOPLE_KIDS_ADULTS_ERR_MSG   : "") +
        (m_totalPeopleTotalRoomsErr ? "\n" + TOTAL_PEOPLE_TOTAL_ROOMS_ERR_MSG   : "") +
        (m_roomsToTotalPeopleErr    ? "\n" + ROOMS_TO_TOTAL_PEOPLE_ERR_MSG      : "");
}
