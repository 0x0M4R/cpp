#include "PhoneBook.hpp"
void PhoneBook::add(int i)
{
    contacts[i].id = i;
    std::cout << "Enter firstname : ";
    std::cin >> contacts[i].firstname;
    std::cout << "Enter lastname : ";
    std::cin >> contacts[i].lastname;
    std::cout << "Enter nickname : ";
    std::cin >> contacts[i].nickname;
    std::cout << "Enter phonenumber : ";
    std::cin >> contacts[i].phonenumber;
    std::cout << "Enter darkestsecret : ";
    std::cin >> contacts[i].darkestsecret;
    size++;
}
void PhoneBook::search()
{
    for (int i=0; i< size; i++)
    {
    std::cout << std::setw(10) << contacts[i].id << '|';
    (contacts[i].firstname.length() > 10) ? std::cout << std::setw(10) << contacts[i].firstname.substr(0,9) << ".|" : std::cout << std::setw(10) << contacts[i].firstname << '|';
    (contacts[i].lastname.length() > 10) ? std::cout << std::setw(10) << contacts[i].lastname.substr(0,9) << ".|" : std::cout << std::setw(10) << contacts[i].lastname << '|';
    (contacts[i].nickname.length() > 10) ? std::cout << std::setw(10) << contacts[i].nickname.substr(0,9) << ".|" : std::cout << std::setw(10) << contacts[i].firstname << "|\n";
    }
}
int main()
{
    int i = 0;
    PhoneBook phone;
    phone.size = 0;
    while(1)
    {
        std::string command;
        std::cout << "Enter command : ";
        std::cin >> command;
        if (command == "ADD")
        {
            phone.add(i);
            i++;
        }
        else if (command == "SEARCH")
        {
            phone.search();
        }
        else if (command == "EXIT")
        {
            return (1);
        }
    }
}