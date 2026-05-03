#include "MailValidator.h"

bool MailValidator::validate(const std::string &value)
{
    size_t atIndex = value.find('@');
    size_t dotIndex = value.find('.');

    if (atIndex == std::string::npos || dotIndex == std::string::npos || atIndex > dotIndex)
        return false;

    std::string userName = value.substr(0, atIndex);
    std::string domainName = value.substr(atIndex + 1, dotIndex - atIndex - 1);
    std::string topLevelDomainName = value.substr(dotIndex + 1);

    return validate_name(userName) && validate_name(domainName) && validate_top_level_domain(topLevelDomainName);
}

std::string MailValidator::getErrMessage()
{
    return "\tError: Invalid mail format, format must be \'user_name@domain_name.top-level-domain\'.";
}

bool MailValidator::validate_name(const std::string &name)
{
    if (name.empty()) return false;

    for (char c : name)
        if (!(std::isalnum(c) || c == '.' || c == '-' || c == '_'))
            return false;

    return true;
}

bool MailValidator::validate_top_level_domain(const std::string &domain)
{
    if (domain.length() < 2)
        return false;

    for (char c : domain)
        if (!std::isalpha(static_cast<unsigned char>(c)))
            return false;

    return true;
}
