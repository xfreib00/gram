#include <gram/evolution/operator/Mutation.h>

using namespace gram::evolution;
using namespace gram::individual;
using namespace gram::util;

Mutation::Mutation(NumberGenerator &generator) : generator(generator) {
  //
}

Genotype Mutation::apply(Genotype genotype) {
  int index = generator.generate();
  int value = generator.generate();

  genotype[index] = value;

  return genotype;
}