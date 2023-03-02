#include "PhoneBook.hpp"
PhoneBook::PhoneBook()
{
    size = 0;
}
void PhoneBook::add(int i)
{
    std::string types[5] = {"firstname", "lastname", "nickname", "phonenumber", "darkestsecret"}; 
    contacts[i].setId(i);
    for (int j=0;j<5;j++)
        contacts[i].setDetail(get_input("Enter " + types[j] + " : "), j);
    if (size < 8)
        size++;
}
void PhoneBook::search()
{
    for (int i=0; i < size; i++) {
        std::cout << std::setw(10) << contacts[i].getId() << '|';
        for (int j=0; j < 3;j++) {
            contacts[i].getDetail(j).length() >= 10 ?
            std::cout << std::setw(10) << contacts[i].getDetail(j).substr(0,9) + '.' << "|" :
            std::cout << std::setw(10) << contacts[i].getDetail(j) << '|';
        }
        std::cout << '\n';
    }
    if (size > 0) {
        std::string input;
        int index;
        input = get_input("Enter index of contact to display : ");
        try {
            index = std::stoi(input);
        }
        catch (...) {
            std::cout << "Error: input is not number \n";
            return ;
            }
        if(index < size) {
            for (int j=0;j<5;j++)
                std::cout << contacts[index].getDetail(j) << std::endl;
        }
        else
            std::cout << "Error: input is out of range \n";
    }
}