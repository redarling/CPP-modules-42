#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main(void)
{
    std::cout << "------Subject test-------" << std::endl
              << std::endl;
    
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter*     me = new Character("me");
    
    AMateria*       tmp;

    tmp = src->createMateria("invalid");
    tmp = src->createMateria("ice");
    me->equip(tmp);
    delete (tmp);

    tmp = src->createMateria("cure");
    me->equip(tmp);
    delete (tmp);
    
    ICharacter*     bob = new Character("bob");
    
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete (bob);
    delete (me);
    delete (src);

    std::cout << std::endl << "------Additional test------" 
              << std::endl << std::endl;

    ICharacter* Andrii = new Character("Andrii");
    ICharacter* CopyAndrii = new Character("CopyAndrii");

    std::cout << std::endl;

    AMateria* ice = new Ice();
    AMateria* cure = new Cure();

    std::cout << std::endl;

    Andrii->equip(ice);
    Andrii->equip(cure);
    Andrii->equip(ice);
    Andrii->equip(cure);
    Andrii->unequip(10);
    Andrii->unequip(-1);
    Andrii->unequip(3);
    Andrii->use(3, *CopyAndrii);
    Andrii->use(2, *CopyAndrii);
    Andrii->unequip(3);
    Andrii->equip(cure);
    Andrii->use(3, *CopyAndrii);
    Andrii->use(2, *CopyAndrii);
    Andrii->equip(cure);
    Andrii->equip(cure);
    Andrii->equip(cure);

    std::cout << std::endl;

    *CopyAndrii = *Andrii;
    CopyAndrii->equip(cure);
    CopyAndrii->use(2, *Andrii);
    CopyAndrii->use(0, *Andrii);
    
    std::cout << std::endl;

    delete (cure);
    delete (ice);
    delete (Andrii);
    delete (CopyAndrii);
    
    return (0);
}
