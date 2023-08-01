#include "Ice.hpp"

Ice::Ice() : AMateria("ice"){
  PRINT_LOG("Ice default constructor called");
}

Ice::Ice(const Ice& ref){
  type_ = ref.type_;
  PRINT_LOG("Ice COPY constructor called");
}

Ice::Ice(const std::string& type) : AMateria(type){

}

Ice::~Ice(){
  PRINT_LOG("Ice default destructor called");
}

Ice&  Ice::operator=(const Ice& ref)
{
  this->type_ = ref.type_;
  return (*this);
}

Ice*  Ice::clone() const
{
  Ice*  clone = new Ice;

  return clone;
}

void  Ice::use(ICharacter& target)
{
  
  PRINT("* shoots an ice bolt at " + target.getName() + " *");
}