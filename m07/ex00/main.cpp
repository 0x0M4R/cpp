#include "whatever.hpp"
// template <class T>
class Data 
{
    private :
        int d;
    public:
        Data(void): d(0) {}
        Data(int d): d(d) {}
        Data &operater=( Data &c) {
            d=c.d;
            return (*this);
        }
        bool operator<=(Data const &c) const {
            return (d<=c.d);
        }
        bool operator>=(Data const &c) const {
            return (d>=c.d);
        }
        int getd() const { return n;}
};
std::ostream &operator<<( std::ostream & os, Data &c)
{
    return (os << c.getd());
}
int main()
{
    int i = 2;
    int j = 1;
    std::cout << "i : " << i << " , j : " << j << std::endl;
    swap(i,j);
    std::cout << "i : " << i << " , j : " << j << std::endl;
}