#include "Character.hpp"

Character::Character() {
  for (int i = 0; i < 4; i++)
    inv_[i] = NULL;
  floor_ = NULL;
  PRINT_LOG("Character default constructor called");
}

Character::Character(const std::string name) : name_(name){
  for (int i = 0; i < 4; i++)
    inv_[i] = NULL;
  floor_ = NULL;
  PRINT_LOG("Character NAME constructor called");
}

Character::Character(const Character& ref)
{
  this->name_ = ref.name_;
  for (int i = 0; i < 4; i++) {
    if (ref.inv_[i] != NULL)
      this->inv_[i] = ref.inv_[i]->clone();
    else
      this->inv_[i] = NULL;
  }
  this->floor_ = NULL;
  PRINT_LOG("Character COPY constructor called");
}

Character::~Character()
{
  for (int i = 0; i < 4; i++)
  {
    if (inv_[i] != NULL)
      delete inv_[i];
  }
  cleanFloor();
}

Character&  Character::operator=(const Character& ref)
{
  this->name_ = ref.name_;
  for (int i = 0; i < 4; i++) {
    if (this->inv_[i] != NULL) {
      delete this->inv_[i];
      this->inv_[i] = NULL;
    }
  }
  for (int i = 0; i < 4; i++) {
    if (ref.inv_[i] != NULL)
      this->inv_[i] = ref.inv_[i]->clone();
    else
      this->inv_[i] = NULL;
  }
  this->floor_ = NULL;
  return (*this);
}

std::string const&  Character::getName() const{
  return (name_);
}

void  Character::equip(AMateria* m)
{
  if (!m) {
    PRINT_WARNING("nothing to equip");
    return ;
  }
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
    PRINT_ERROR("invalid index number");
    return ;
  }
  if (!inv_[idx]) {
    PRINT_WARNING("nothing to unequip");
    return ;
  }
  dropMateria(inv_[idx]);
  inv_[idx] = NULL;
}

void  Character::use(int idx, ICharacter& target)
{
  if (inv_[idx] == NULL)
    return ;
  if (idx < 0 || idx > 3){
    PRINT_ERROR("invalid index number");
    return ;
  }
  inv_[idx]->use(target);
}

void  Character::dropMateria(AMateria* trash)
{
  Floor*  drop = new Floor;
  drop->trash = trash;
  drop->next = NULL;
  if (floor_ == NULL)
  {
    floor_ = drop;
    return ;
  }
  Floor* last = floor_;
  while (last->next != NULL)
    last = last->next;
  last->next = drop;
}

void  Character::cleanFloor()
{
  if (floor_ == NULL)
    return ;
  while (floor_)
  {
    Floor* temp = floor_;
    floor_ = floor_->next;
    delete temp->trash;
    delete temp;
  }
  
}
