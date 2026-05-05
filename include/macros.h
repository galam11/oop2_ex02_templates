#pragma once
#include <string>

const std::string WEEKEND_BREAK_FAST_ERR_MSG = "(*) With 'Weekend' vaction type you cant have 'Breakfast' hosting type.";
const std::string MID_WEEK_FULL_BOARD_ERR_MSG = "(*) With 'Mid-week' vaction type you cant have 'Full board' hosting type.";

const std::string MID_WEEK_NIGHTS_CONT_ERR_MSG = "(*) 'Mid-week' vacation's vacation days must be between 1 to 5.";
const std::string WEEK_END_NIGHTS_CONT_ERR_MSG = "(*) 'Weekend' vacation's vacation days must be at least 3 days.";

const std::string NEG_COUNT_ROOMS_ERR_MSG = "(*) You cant get a negetive amount of rooms.";
const std::string TOTAL_PEOPLE_KIDS_ADULTS_ERR_MSG = "(*) Total people isn't equalls kids and adults.";
const std::string TOTAL_PEOPLE_TOTAL_ROOMS_ERR_MSG = "(*) Not enough beds to all the peaple";
const std::string ROOMS_TO_TOTAL_PEOPLE_ERR_MSG = "(*) There are two manny rooms - you cant have empty rooms";


const std::string ID_ERR_MSG = "\tError: Invalid ID, ID must be 8 or 9 digits and contain the correct control digit.";
const std::string MAIL_ERR_MSG = "\tError: Invalid mail format, format must be 'user_name@domain_name.top-level-domain'.";;
const std::string NAME_ERR_MSG = "\tError: Name must be at length >= 3 and must not contain numbers.";
const std::string VACATION_ERR_MSG = "\tError: Date must be in the future and within the current year.";


const std::string LINE_SEPERATOR = "-------------------------------------------------------------------------";

