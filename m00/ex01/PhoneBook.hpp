#include "Contact.hpp"
class PhoneBook
{
    private:
        Contact contacts[8];
        int size;
    public:
        PhoneBook();
        void add(int i);
        void search();
};
std::string get_input(std::string msg);