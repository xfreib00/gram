#ifndef GRAM_POPULATION
#define GRAM_POPULATION

#include <memory>
#include <vector>

#include <gram/individual/Individual.h>
#include <gram/population/reproducer/Reproducer.h>
#include <gram/population/Individuals.h>

namespace gram {
/**
 * Class.
 */
class Population {
 public:
  Population(Individuals individuals, std::shared_ptr<Reproducer> reproducer, unsigned long number);
  double bestFitness();
  Individual& bestIndividual();
  Individual& operator[](unsigned long index);
  unsigned long size() const;
  unsigned long number() const;
  void evaluate(Evaluator& evaluator);
  Population reproduce();
  virtual ~Population() = default;
 private:
  Individuals individuals;
  std::shared_ptr<Reproducer> reproducer;
  unsigned long _number;
};
}

#endif // GRAM_POPULATION
