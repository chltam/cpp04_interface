#include "Character.hpp"

Character::Character() {
  for (int i = 0; i < 4; i++)
    inv_[i] = NULL;
  PRINT_LOG("Character default constructor called");
}

Character::Character(const std::string name) : name_(name){
  for (int i = 0; i < 4; i++)
    inv_[i] = NULL;
  PRINT_LOG("Character NAME constructor called");
}

std::string const&  Character::getName() const{
  return (name_);
}

void  Character::equip(AMateria* m)
{
  for (int i = 0; i < 4; i++){
    if (inv_[i] == NULL)
    {
      inv_[i] = m;
      return ;
    }
  }
}

void  Character::unequip(int idx)
{
  if (idx < 0 || idx > 3){
    PRINT_ERROR("index index number");
    return ;
  }
  inv_[idx] = NULL;
}

void  Character::use(int idx, ICharacter& target)
{
  if (inv_[idx] == NULL)
    return ;
  if (idx < 0 || idx > 3){
    PRINT_ERROR("index index number");
    return ;
  }
  inv_[idx]->use(target);
}