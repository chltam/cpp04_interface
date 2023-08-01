#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
  Ice ice;
  Cure  cure;

  Ice* two = ice.clone();
  Cure* three = cure.clone();
  Character cosmo("cosmo");

  ice.use(cosmo);
  cure.use(cosmo);

  cosmo.equip(two);
  cosmo.equip(three);
  cosmo.use(0, cosmo);
  cosmo.use(1, cosmo);
  // PRINT(cosmo.inv[0]->getType());
  // PRINT(cosmo.inv[1]->getType());
  // delete two;
  // delete three;

  return (0);
}