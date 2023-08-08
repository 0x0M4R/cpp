#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
int main()
{
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());

    AMateria* tmp;

    ICharacter* me = new Character("me");
    ICharacter* omar = new Character("omar");

    me->equip(src->createMateria("ice"));
    me->equip(src->createMateria("cure"));
    me->use(0,*omar);
    me->use(1,*omar);
    
    omar->equip(src->createMateria("ice"));
    tmp = src->createMateria("ice");
    omar->use(0, *me);
    omar->use(1, *me);
    omar->unequip(1);
    omar->use(1,*me);
    delete tmp;
    delete me;
    delete omar;
    delete src;
    return 0;
}