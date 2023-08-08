#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
// #include "IMateriaSource.hpp"
#include "Character.hpp"
// #include "ICharacter.hpp"
int main()
{
    IMateriaSource* src;
    IMateriaSource* src1 = new MateriaSource();
    src = src1;
    // MateriaSource new1;
    // MateriaSource new2;
    // new1 = new2;
    // src->learnMateria(new Ice());
    // // src->learnMateria(new Cure());
    // ICharacter* me = new Character("me");
    // std::cout << "\nDeep copy test copy constructor:\n" << std::endl;
	// Character bob("bob");
    // AMateria* tmp;
    // tmp = src->createMateria("ice");
    // bob.equip(tmp);
	// {
	// 	Character cpy;
    //     cpy = bob;
	// 	std::cout << "\nbefore deletion: " << tmp->getType() << std::endl;
	// }
	// std::cout << "\ncopied after deletion: " << tmp->getType() << std::endl;

    // AMateria* tmp;
    // tmp = src->createMateria("ice");
    // tmp->use(me);
    // me->equip(tmp);
    // tmp = src->createMateria("cure");
    // me->equip(tmp);
    // ICharacter* bob = new Character("bob");
    // me->use(0, *bob);
    // me->use(1, *bob);
    // delete bob;
    // delete me;
    // delete src;
    // return 0;
}