#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : IMateriaSource() {
  for (int i = 0; i < 4; i++){
    memory_[i] = NULL;
  }
  PRINT_LOG("MateriaSource default constructor called");
}

MateriaSource::MateriaSource(const MateriaSource& ref)
{
  *this = ref;
  PRINT_LOG("MateriaSource COPY constructor called");
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < 4; i++) {
    if (memory_[i] != NULL)
      delete memory_[i];
  }
  PRINT_LOG("MateriaSource default destructor called");
}

MateriaSource&  MateriaSource::operator=(const MateriaSource& ref)
{
  for (int i = 0; i < 4; i++) {
    if (this->memory_[i] != NULL) {
      delete this->memory_[i];
      this->memory_[i] = NULL;
    }
  }
  for (int i = 0; i < 4; i++) {
    if (ref.memory_[i] != NULL)
      this->memory_[i] = ref.memory_[i]->clone();
    else
      this->memory_[i] = NULL;
  }
  return (*this);
}

void  MateriaSource::learnMateria(AMateria* m)
{
  PRINT_LOG("Learning materia " + m->getType());
  for (int i = 0; i < 4; i++) {
    if (memory_[i] == NULL) {
      memory_[i] = m->clone();
      delete m;
      return ;
    }
  }
  delete m;
  PRINT_ERROR("memory is full");
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
  for (int i = 0; i < 4; i++) {
    if (memory_[i] != NULL) {
      if (memory_[i]->getType() == type)
        return (memory_[i]->clone());
    }
  }
  PRINT_ERROR("Unknown type");
  return (0);
}