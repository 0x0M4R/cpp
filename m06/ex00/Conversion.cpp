#include "Conversion.hpp"

Conversion::Conversion()
{

}

Conversion::Conversion( std::string input) : input(input)
{
    convert();
    display();
}

Conversion::~Conversion()
{

}


void Conversion::display( void )
{

    (i >= CHAR_MIN && i <= CHAR_MAX)?
        (std::isprint(i))?
            std::cout << "char : '" << static_cast<char>(i) << "'" << std::endl:
            std::cout << "char : Non displayable" << std::endl:
        std::cout << "char : impossible" << std::endl;
    (std::isfinite(d) && d <= INT_MAX && d >= INT_MIN)?
        std::cout << "int : " << i << std::endl:
        std::cout << "int : impossible" << std::endl;
    (std::isfinite(f) && d == static_cast<int>(d))?
        // (d == static_cast<int>(d))?
            std::cout << "float : " << f << ".0f" << std::endl:
            // std::cout << "float : " << f << "f" << std::endl:
        std::cout << "float : " << f << "f" << std::endl;
    (d == static_cast<int>(d) && std::isfinite(d))?
        std::cout << "double : " << d << ".0" << std::endl:
        std::cout << "double : " << d << std::endl;
}
void Conversion::convert( void )
{
    std::string in_f = "";
    if(input.at(input.length() - 1) == 'f')
            in_f = input.substr(0,input.length() - 1);
    std::istringstream o(input);
    int temp_i;
    float temp_f;
    double temp_d;
    if(o >> temp_d && o.eof() && !o.fail())
    {
        d = temp_d;
        type = 'd';
        f = static_cast<float>(d);
        i = static_cast<int>(d);
        return ;
    }
    o.str(input);
    o.clear();
    if (o >> temp_i && o.eof() && !o.fail())
    {
        i = temp_i;
        type = 'i';
        f = static_cast<float>(i);
        d = static_cast<double>(i);
        return ;
    }
    o.str(in_f);
    o.clear();
    if(o >> temp_f && o.eof() && !o.fail())
    {
        f = temp_f;
        type = 'f';
        d = static_cast<double>(f);
        i = static_cast<int>(f);
        return;
    }
    throw "invalid input";
    // std::cout << "invalid input"<<std::endl; //throw exception
}
