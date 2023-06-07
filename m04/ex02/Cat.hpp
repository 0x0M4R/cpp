#ifndef CAT_HPP
#define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"
class Cat : public Animal {
    private:
    class Brain* catbrain;
    public:
    Cat();
    Cat(Cat const & copy);
    ~Cat();
    void makeSound() const;
};
#endif
