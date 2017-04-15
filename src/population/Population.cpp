#include <gram/population/Population.h>

using namespace gram;
using namespace std;

Population::Population(Individuals individuals, shared_ptr<Reproducer> reproducer, unsigned long generationNumber)
    : individuals(individuals), reproducer(reproducer), number(generationNumber) {
  //
}

unsigned long Population::generationNumber() const {
  return number;
}

double Population::bestFitness() {
  return bestIndividual().getFitness();
}

Individual& Population::bestIndividual() {
  return individuals.bestIndividual();
}

Individual& Population::operator[](unsigned long index) {
  return individuals[index];
}

vector<Individual>::iterator Population::begin() {
  return individuals.begin();
}

vector<Individual>::iterator Population::end() {
  return individuals.end();
}

unsigned long Population::size() const {
  return individuals.size();
}

Population Population::reproduce() {
  Individuals successors = reproducer->reproduce(individuals);

  unsigned long newNumber = number + 1;

  return Population(successors, reproducer, newNumber);
}
