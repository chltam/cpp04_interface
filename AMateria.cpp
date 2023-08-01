#include "AMateria.hpp"

AMateria::AMateria(){
  PRINT_LOG("AMateria default constructor called");
}

AMateria::AMateria(std::string const& type) : type_(type) {
  PRINT_LOG("AMateria TYPE constructor called");
}

AMateria::AMateria(const AMateria& ref) : type_(ref.type_) {
  PRINT_LOG("AMateria COPY constructor called");
}

AMateria::~AMateria(){
  PRINT_LOG("AMateria default destructor called");
}

AMateria&	AMateria::operator=(const AMateria& ref)
{
  this->type_ = ref.type_;
  return (*this);
}

std::string const&	AMateria::getType() const{
  return (type_);
}

void  AMateria::use(ICharacter& target)
{
  PRINT("undefined materia used on " + target.getName());
}