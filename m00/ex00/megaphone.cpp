#include <iostream>
// #include <string>
int main(int argc, char *argv[])
{
    for(int i = 1; i < argc; i++)
    {
        std::string tmp = argv[i];
        for(size_t j = 0; j < tmp.length(); j++)
            std::cout << (char)toupper(tmp[j]);
    }
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << "\n";
    return(1);
}