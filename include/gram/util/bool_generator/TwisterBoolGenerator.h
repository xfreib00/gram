#ifndef GRAM_UTIL_BOOL_GENERATOR_TWISTER
#define GRAM_UTIL_BOOL_GENERATOR_TWISTER

#include <memory>

#include <gram/util/bool_generator/BoolGenerator.h>
#include <gram/util/number_generator/NumberGenerator.h>

namespace gram {
/**
 * Class.
 */
class TwisterBoolGenerator : public BoolGenerator {
 public:
  TwisterBoolGenerator(double probability);
  bool generate() const;
  std::vector<bool> generateMany(unsigned long count) const;
 private:
  std::unique_ptr<NumberGenerator> generator;
  double probability;
  unsigned long max;
};
}

#endif // GRAM_UTIL_BOOL_GENERATOR_TWISTER
