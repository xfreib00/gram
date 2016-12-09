#include <gtest/gtest.h>

#include <gram/evolution/fitness_calculator/ParabolaFitnessCalculator.h>

using namespace gram::evolution;

TEST(parabola_fitness_calculator_test, test_exact_match_has_best_possible_fitness) {
  ParabolaFitnessCalculator calculator(10);

  ASSERT_NEAR(0.0, calculator.calculate(0, 0), 0.0001);
}

TEST(parabola_fitness_calculator_test, test_opposite_values_have_the_same_fitness) {
  ParabolaFitnessCalculator calculator(10);

  ASSERT_NEAR(calculator.calculate(0, -5), calculator.calculate(0, 5), 0.0001);
}

TEST(parabola_fitness_calculator_test, test_bad_result_has_bad_fitness) {
  ParabolaFitnessCalculator calculator(10);

  ASSERT_GT(calculator.calculate(0, 40), 10.0);
}