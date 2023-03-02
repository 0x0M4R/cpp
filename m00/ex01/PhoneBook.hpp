#include "Contact.hpp"
class PhoneBook
{
    public:
        Contact contacts[8];
        std::string types[5];
        void add(int i);
        void search();
        int size;
};