#ifndef _ICE_H_
#define _ICE_H_

#include <iostream>

#include "AMateria.hpp"

class Ice : public AMateria{
  public:
    Ice();
    Ice(const std::string& type);
    Ice(const Ice& ref);
    virtual ~Ice();
    Ice&  operator=(const Ice& ref);

    virtual Ice*  clone() const;
    virtual void  use(ICharacter& target);
};

#endif