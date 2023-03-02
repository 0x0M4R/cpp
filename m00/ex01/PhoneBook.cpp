#include "PhoneBook.hpp"
void PhoneBook::add(int i)
{
    contacts[i].id = i;
    for (int j=0;j<5;j++)
    {
        std::cout << "Enter " + types[j] + " : ";
        std::getline(std::cin,contacts[i].details[j]);
    }
    if (size < 8)
        size++;
}
void PhoneBook::search()
{
    for (int i=0; i < size; i++)
    {
        std::cout << std::setw(10) << contacts[i].id << '|';
        for (int j=0; j < 3;j++)
        {
            contacts[i].details[j].length() >= 10 ?
            std::cout << std::setw(10) << contacts[i].details[j].substr(0,9) + '.' << "|" :
            std::cout << std::setw(10) << contacts[i].details[j] << '|';
        }
        std::cout << '\n';
    }
    if (size > 0)
    {
        std::string input;
        int index;
        std::cout << "Enter index of contact to display : ";
        std::getline(std::cin, input);
        try{ index = std::stoi(input);}
        catch (...) {
            std::cout << "Error: input is not number \n";
            return ;}
        if(index < size)
        {
            for (int j=0;j<5;j++)
                std::cout << contacts[index].details[j] << std::endl;
        }
        else
            std::cout << "Error: input is out of range \n";
    }
}
int main()
{
    int i = 0;
    PhoneBook phone;
    phone.size = 0;
    std::string command;
    phone.types[0] = "firstname";
    phone.types[1] = "lastname";
    phone.types[2] = "nickname";
    phone.types[3] = "phonenumber";
    phone.types[4] = "darkestsecret"; 
    while(1)
    {
        std::cout << "Enter command : ";
        std::getline(std::cin, command);
        if (command == "ADD")
        {
            phone.add(i);
            i++;
            if (i == 8)
                i=0;
        }
        else if (command == "SEARCH")
            phone.search();
        else if (command == "EXIT")
        {
            return (1);
        }
    }
}