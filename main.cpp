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
  Character jack;
  jack = cosmo;
  cosmo.unequip(0);
  cosmo.unequip(1);
  jack.use(0, jack);
  jack.use(1, jack);
  // cosmo.use(0, cosmo);
  // cosmo.use(1, cosmo);
  // PRINT(cosmo.inv[0]->getType());
  // PRINT(cosmo.inv[1]->getType());

  return (0);
}