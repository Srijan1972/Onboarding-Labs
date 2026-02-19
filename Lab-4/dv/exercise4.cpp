#include <cstdint>

#include <catch2/catch_test_macros.hpp>
#include <VExercise4.h>

uint8_t func(uint8_t cs, uint8_t sel, uint8_t alpha, uint8_t beta, uint8_t gamma) {
  if (!cs) return 0;
  else {
    switch (sel)
    {
    case 0:
      return alpha;
      break;
    case 1:
      return beta;
    case 2:
      return gamma;
    default:
      return alpha & (beta | gamma);
    }
  }
}

TEST_CASE("Decoder") {
  VExercise4 model;
  model.alpha = 5;
  model.beta = 10;
  model.gamma = 15;
  for (uint8_t i = 0; i < 2; i++) {
    model.cs = i;
    for (uint8_t j = 0; j < 4; j++) {
      model.sel = j;
      model.eval();
      REQUIRE(model.out == func(i, j, 5, 10, 15));
    }
  }
}