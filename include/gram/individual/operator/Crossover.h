#ifndef GRAM_INDIVIDUAL_CROSSOVER_OPERATOR
#define GRAM_INDIVIDUAL_CROSSOVER_OPERATOR

#include <memory>

#include <gram/individual/Genotype.h>
#include <gram/util/number_generator/NumberGenerator.h>

namespace gram {
/**
 * Class.
 */
class Crossover {
 public:
  Crossover(std::unique_ptr<NumberGenerator> numberGenerator);
  virtual Genotype apply(const Genotype& first, const Genotype& second) const;
 private:
  std::unique_ptr<NumberGenerator> numberGenerator;
};
}

#endif // GRAM_INDIVIDUAL_CROSSOVER_OPERATOR
