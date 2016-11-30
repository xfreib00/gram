#ifndef GRAM_POPULATION_POPULATION
#define GRAM_POPULATION_POPULATION

#include <gram/individual/Individual.h>

namespace gram {
namespace population {
/**
 * Class.
 */
class Population {
 public:
  Population(std::vector<gram::individual::Individual> individuals);
  gram::individual::Individual &operator[](int index);
 private:
  std::vector<gram::individual::Individual> individuals;
};
}
}

#endif // GRAM_POPULATION_POPULATION
