#include "AMateria.hpp"

AMateria::AMateria(std::string const& type) : type_(type) {}

AMateria::AMateria(const AMateria& ref) : type_(ref.type_) {}

AMateria&	AMateria::operator=(const AMateria& ref)
{

}

std::string const&	AMateria::getType() const{
  return (type_);
}
