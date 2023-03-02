#include "PhoneBook.hpp"
#include <limits>
void PhoneBook::add(int i)
{
    contacts[i].id = i;
    for (int j=0;j<5;j++)
        contacts[i].details[j] = get_input("Enter " + types[j] + " : ");
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
        input = get_input("Enter index of contact to display : ");
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

std::string get_input(std::string msg)
{
    std::string input = "";
    while(input.length() == 0)
    {
        std::cout << msg;
        std::getline(std::cin, input);
        if (std::cin.eof())
        {
            clearerr(stdin);
            std::cin.clear();
            std::cout << std::endl;
        }
    }
    return input;
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
        command = get_input("Enter command : ");
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