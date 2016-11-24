#include "Genotype.h"

using namespace gram::population::individual;

Genotype::Genotype(std::vector<int> values) : values(values) {
  //
}

int Genotype::geneAt(int index) {
  return values[index];
}