#ifndef _MATERIASOURCE_H_
#define _MATERIASOURCE_H_

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
  public:
    MateriaSource();
    MateriaSource(const MateriaSource& ref);
    ~MateriaSource();
    MateriaSource&  operator=(const MateriaSource& ref);

  private:
    AMateria* memory_[4];
};

#endif