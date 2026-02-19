#include <bits/stdc++.h>

#include <catch2/catch_test_macros.hpp>
#include <VExercise2.h>

struct LFSR {
  uint16_t value;
  static constexpr uint16_t mask {1290};

  void step() {
    uint16_t bits = value & mask;
    value = (value << 1) | (std::popcount(bits) & 1);
  }
};

void step(VExercise2& model) {
  model.clk = 1;
  model.eval();
  model.clk = 0;
  model.eval();
}

void test_initial_value(uint16_t init) {
  VExercise2 model;
  model.init = init;
  model.reset = 1;
  step(model);
  model.reset = 0;

  LFSR lfsr;
  lfsr.value = ~init;

  for(uint8_t cycles {0}; cycles < 100; ++cycles) {
    REQUIRE(model.out == lfsr.value);
    step(model);
    lfsr.step();
  }

  model.reset = 1;
  step(model);
  REQUIRE(model.out == static_cast<uint16_t>(~init));
}

TEST_CASE("Initial value 0x00") {
  test_initial_value(0x00);
}

TEST_CASE("Initial value 0xFF") {
  test_initial_value(0xFF);
}

TEST_CASE("Initial value 0x55") {
  test_initial_value(0x55);
}

TEST_CASE("Initial value 0xAA") {
  test_initial_value(0xAA);
}