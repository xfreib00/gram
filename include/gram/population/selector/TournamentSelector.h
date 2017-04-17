#ifndef GRAM_EVOLUTION_TOURNAMENT_SELECTOR
#define GRAM_EVOLUTION_TOURNAMENT_SELECTOR

#include <memory>

#include "gram/individual/Individual.h"
#include "gram/individual/comparer/IndividualComparer.h"
#include "gram/population/selector/IndividualSelector.h"
#include "gram/random/number_generator/NumberGenerator.h"

namespace gram {
class Individual;
class Individuals;
/**
 * Class.
 */
class TournamentSelector : public IndividualSelector {
 public:
  TournamentSelector(unsigned long tournamentSize,
                     std::unique_ptr<NumberGenerator> numberGenerator,
                     std::unique_ptr<IndividualComparer> comparer);
  Individual& select(Individuals& individuals);
 private:
  unsigned long tournamentSize;
  std::unique_ptr<NumberGenerator> numberGenerator;
  std::unique_ptr<IndividualComparer> comparer;
};
}

#endif // GRAM_EVOLUTION_TOURNAMENT_SELECTOR
