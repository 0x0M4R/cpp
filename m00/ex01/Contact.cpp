#include "Contact.hpp"
std::string Contact::getDetail(int i)
{
    return details[i];
}
void Contact::setDetail(std::string detail, int i)
{
    details[i] = detail;
}
int Contact::getId()
{
    return id;
}
void Contact::setId(int i)
{
    id = i;
}