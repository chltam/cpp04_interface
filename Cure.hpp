#ifndef _CURE_H_
#define _CURE_H_

#include <iostream>

#include "AMateria.hpp"

class Cure : public AMateria{
  public:
    Cure();
    // Cure(const std::string& type);
    Cure(const Cure& ref);
    virtual ~Cure();
    Cure&  operator=(const Cure& ref);

    virtual Cure*  clone() const;
    virtual void  use(ICharacter& target);
};

#endif