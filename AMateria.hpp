#ifndef _AMATERIA_H_
#define _AMATERIA_H_

#include <iostream>
#include <string>

#include "ICharacter.hpp"

class AMateria {

  protected:
    std::string	type_;

  public:
    AMateria(){};
    AMateria(std::string const & type);
    AMateria(const AMateria& ref);
    ~AMateria(){};
    AMateria&	operator=(const AMateria& ref);

    std::string const & getType() const; //Returns the materia type

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif