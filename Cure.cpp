#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){
  PRINT_LOG("Cure default constructor called");
}

Cure::Cure(const Cure& ref) : AMateria() {
  type_ = ref.type_;
  PRINT_LOG("Cure COPY constructor called");
}

Cure::~Cure(){
  PRINT_LOG("Cure default destructor called");
}

Cure&  Cure::operator=(const Cure& ref)
{
  this->type_ = ref.type_;
  return (*this);
}

Cure*  Cure::clone() const
{
  Cure*  clone = new Cure;

  return clone;
}

void  Cure::use(ICharacter& target){
  PRINT("* heals " + target.getName() + "\'s wounds *");
}