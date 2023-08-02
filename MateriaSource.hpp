#ifndef _MATERIASOURCE_H_
#define _MATERIASOURCE_H_

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
  public:
    MateriaSource();
    MateriaSource(const MateriaSource& ref);
    virtual ~MateriaSource();
    MateriaSource&  operator=(const MateriaSource& ref);

    virtual void  learnMateria(AMateria* m);
    virtual AMateria* createMateria(std::string const & type);

  private:
    AMateria* memory_[4];
};

#endif