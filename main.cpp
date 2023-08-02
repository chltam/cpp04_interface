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

  // PRINT("-----extra test 1-----");
  // // Character cosmo("Cosmo");
  // Character* cosmo = new Character("cosmo");
  // Character cosmomo = *cosmo;
  // IMateriaSource* src2 = new MateriaSource();
  // src2->learnMateria(new Ice());
  // AMateria* ice = src2->createMateria("ice");
  // // Cure cure;

  // cosmomo.equip(ice);
  // cosmomo.use(0, *cosmo);
  // delete cosmo;
  // delete src2;
  return 0;
}