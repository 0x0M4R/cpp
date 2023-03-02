#include "PhoneBook.hpp"
std::string get_input(std::string msg)
{
    std::string input = "";
    while(input.length() == 0) {
        std::cout << msg;
        std::getline(std::cin, input);
        if (std::cin.eof()) {
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
    std::string command;
    while(1) {
        command = get_input("Enter command : ");
        if (command == "ADD") {
            phone.add(i);
            i++;
            if (i == 8)
                i=0;
        }
        else if (command == "SEARCH")
            phone.search();
        else if (command == "EXIT")
            return (1);
    }
}