#ifndef GRAM_POPULATION_INITIALIZER
#define GRAM_POPULATION_INITIALIZER

#include <population/Population.h>

namespace gram {
namespace population {
/**
 * Class.
 */
class Initializer {
 public:
  virtual Population initialize();
};
}
}

#endif // GRAM_POPULATION_INITIALIZER
