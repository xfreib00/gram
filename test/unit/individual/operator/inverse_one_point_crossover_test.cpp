#include <gtest/gtest.h>
#include <gtest/fakeit.hpp>

#include <gram/individual/operator/InverseOnePointCrossover.h>

using namespace fakeit;
using namespace gram;
using namespace std;

TEST(inverse_one_point_crossover_operator_test, test_it_combines_genotypes_of_the_same_length) {
  Mock<NumberGenerator> mock;
  Fake(Dtor(mock));
  When(Method(mock, generate)).Return(2);
  auto numberGenerator = unique_ptr<NumberGenerator>(&mock.get());

  InverseOnePointCrossover crossover(move(numberGenerator));

  Genotype genotype1({0, 1, 2, 3, 4});
  Genotype genotype2({5, 6, 7, 8, 9});

  ASSERT_EQ(Genotype({0, 1, 5, 6}), crossover.apply(genotype1, genotype2));
}

TEST(inverse_one_point_crossover_operator_test, test_it_combines_short_and_long_genotypes) {
  Mock<NumberGenerator> mock;
  Fake(Dtor(mock));
  When(Method(mock, generate)).Return(4);
  auto numberGenerator = unique_ptr<NumberGenerator>(&mock.get());

  InverseOnePointCrossover crossover(move(numberGenerator));

  Genotype genotype1({0, 1, 2});
  Genotype genotype2({5, 6, 7, 8, 9});

  ASSERT_EQ(Genotype({0, 1, 2, 5, 6, 7, 8}), crossover.apply(genotype1, genotype2));
}

TEST(inverse_one_point_crossover_operator_test, test_it_combines_long_and_short_genotypes) {
  Mock<NumberGenerator> mock;
  Fake(Dtor(mock));
  When(Method(mock, generate)).Return(3);
  auto numberGenerator = unique_ptr<NumberGenerator>(&mock.get());

  InverseOnePointCrossover crossover(move(numberGenerator));

  Genotype genotype1({0, 1, 2, 3, 4});
  Genotype genotype2({5, 6});

  ASSERT_EQ(Genotype({0, 1, 2, 5, 6}), crossover.apply(genotype1, genotype2));
}
