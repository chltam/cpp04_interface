#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "interface.hpp"
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter{
  
  public:
    Character();
    Character(const std::string name);
    Character(const Character& ref);
    virtual ~Character() {}
    Character&  operator=(const Character& ref);
    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);

  private:
    std::string name_;
    AMateria*  inv_[4];
};

#endif