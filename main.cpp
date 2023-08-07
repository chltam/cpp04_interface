#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
  PRINT("-----basic test-----");
  IMateriaSource* src = new MateriaSource();
  src->learnMateria(new Ice());
  src->learnMateria(new Cure());
  ICharacter* me = new Character("me");
  AMateria* tmp;
  tmp = src->createMateria("ice");
  me->equip(tmp);
  tmp = src->createMateria("cure");
  me->equip(tmp);
  ICharacter* bob = new Character("bob");
  me->use(0, *bob);
  me->use(1, *bob);
  delete bob;
  delete me;
  delete src;

  PRINT("-----extra test 1-----");
  Character cosmo("cosmo");
  Character jack("jack");
  Ice* ice = new Ice();
  Cure* cure = new Cure();

  cosmo.equip(ice);
  cosmo.equip(cure);

  Character cosmomo(cosmo);
  cosmomo.equip(new Ice);
  cosmomo = cosmo;
  cosmo.unequip(0);
  cosmo.unequip(1);
  
  cosmomo.use(0, jack);
  cosmomo.use(1, jack);


  PRINT("-----extra test 2-----");
  Character nick("nick");
  MateriaSource* src2 = new MateriaSource;
  src2->learnMateria(new Ice);
  src2->learnMateria(new Cure);
  
  MateriaSource dllm = *src2;
  delete src2;

  nick.equip(dllm.createMateria("ice"));
  nick.equip(dllm.createMateria("cure"));
  nick.equip(dllm.createMateria("wtffff"));
  nick.use(0, cosmo);
  nick.use(1, cosmo);
  nick.use(2, cosmo);
  nick.unequip(3);
  return 0;
}