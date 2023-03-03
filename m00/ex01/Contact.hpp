#include <iostream>
#include <iomanip>
class Contact
{
    private:
        int id;
        std::string details[5];
    public:
        std::string getDetail(int i);
        void setDetail(std::string detail, int i);
        int getId();
        void setId(int i);
};