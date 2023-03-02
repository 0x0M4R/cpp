#include <iostream>
#include <iomanip>
class Contact
{
    public:
        int id;
        std::string details[5];
};
class PhoneBook
{
    public:
        Contact contacts[8];
        std::string types[5];
        void add(int i);
        void search();
        int size;
};
std::string get_input(std::string msg);