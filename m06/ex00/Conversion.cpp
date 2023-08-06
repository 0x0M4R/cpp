#include "Conversion.hpp"

Conversion::Conversion()
{

}

Conversion::Conversion( std::string input) : input(input)
{
    convert();
    std::cout << "type : " << type << std::endl;
    ( i >= CHAR_MIN && i <= CHAR_MAX )?
        (std::isprint(i))?
            std::cout << "char : " << static_cast<int>(i) << std::endl:
            std::cout << "char : Non displayable" << std::endl:
        std::cout << "char : impossible" << std::endl;
    std::cout << "int : " << i << std::endl;
    (i == static_cast<int>(f))? 
        std::cout << "float : " << f << ".0f" << std::endl:
        std::cout << "float : " << f << std::endl;
    (i == static_cast<int>(d))?
        std::cout << "double : " << d << ".0" << std::endl:
        std::cout << "double : " << d << std::endl;
}

Conversion::~Conversion()
{

}

// Conversion::Conversion( Conversion const & copy )
// {

// }

// Conversion &Conversion::operator=( Conversion const &copy )
// {

// }

void Conversion::convertAll( void )
{

}
void Conversion::convert( void )
{
    std::string in_f;
    if(input.find_last_of('f') != std::string::npos && input.length() > 1)
            in_f = input.substr(0,input.length() - 1);
    std::istringstream o(input);
    int temp_i;
    float temp_f;
    double temp_d;
    // char temp_c;
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
    std::cout << "invalid input"<<std::endl; //throw exception
}
