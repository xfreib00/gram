#ifndef GRAM_LANGUAGE_CONTEXT_FREE_MAPPER
#define GRAM_LANGUAGE_CONTEXT_FREE_MAPPER

#include <memory>
#include <stack>
#include <vector>

#include "gram/individual/Genotype.h"
#include "gram/individual/Individual.h"
#include "gram/individual/Phenotype.h"
#include "gram/language/grammar/ContextFreeGrammar.h"
#include "gram/language/mapper/Mapper.h"

namespace gram {
class ContextFreeGrammar;
class Option;
class Symbol;
/**
 * Class.
 */
class ContextFreeMapper : public Mapper {
 public:
  ContextFreeMapper(std::shared_ptr<ContextFreeGrammar> grammar, unsigned long wrappingLimit);
  Phenotype map(const Genotype& genotype);
 private:
  std::shared_ptr<ContextFreeGrammar> grammar;
  unsigned long wrappingLimit;
  std::vector<Symbol*> symbols; // does not hold any state
  void pushOption(Option& option);
};
}

#endif // GRAM_LANGUAGE_CONTEXT_FREE_MAPPER
