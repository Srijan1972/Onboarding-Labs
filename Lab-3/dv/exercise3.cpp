#include <bits/stdc++.h>
#include <VExercise3.h>

uint8_t mystery1(uint8_t a, uint8_t b, uint8_t c) {
  switch(a) {
    case 0:
      return 0 | ((b & 7) << 3) | (c & 7);
    case 1:
      return 64 | ((c & 7) << 3) | (b & 7);
    case 2:
      return b;
    default:
      return c;
  }
}

struct Mystery2 {
  uint8_t count {0};
  uint16_t out;

  uint16_t reset(uint8_t a, uint8_t b) {
    out = (b << 8) | a;
    count = 0;
    return out;
  }

  uint16_t step(uint8_t a, uint8_t b) {
    count %= 5;
    switch(count++) {
      case 0:
        return out = (a << 8) | (out & 0x00FF);
      case 1:
        return out = (out & 0xFF00) | b;
      case 2:
        return out = ((out & 0xFF) << 8) | (out >> 8);
      case 3:
        return out = ((out & 0x000F) << 12) | ((out & 0x00F0) << 4) | ((out & 0x0F00) >> 4) | ((out & 0xF000) >> 12);
      default:
        return out = std::popcount(out) & 1;
    }
  }
};

struct Excercise3Sim {
  Mystery2 state;

  uint16_t reset(uint8_t a, uint16_t b, uint16_t c) {
    uint8_t a_in {mystery1(a & 0x3, b & 0xFF, c & 0xFF)};
    uint8_t b_in {mystery1(a >> 2, b >> 8, c >> 8)};
    return state.reset(a_in, b_in);
  }

  uint16_t step(uint8_t a, uint16_t b, uint16_t c) {
    uint8_t a_in {mystery1(a & 0x3, b & 0xFF, c & 0xFF)};
    uint8_t b_in {mystery1(a >> 2, b >> 8, c >> 8)};
    return state.step(a_in, b_in);
  }
};

void step(VExercise3& model) {
  model.clk = 1;
  model.eval();
  model.clk = 0;
  model.eval();
};

int main() {
  VExercise3 model;
  Excercise3Sim sim;
  srand(time(0));
  model.a = rand() & 0xF;
  model.b = rand() & 0xFFFF;
  model.c = rand() & 0xFFFF;
  model.reset = 1;
  step(model);
  if (model.out != sim.reset(model.a, model.b, model.c)) {
    return 1;
  }
  model.reset = 0;
  for (uint8_t cycle = 0; cycle < 100; cycle++) {
    model.a = rand() & 0xF;
    model.b = rand() & 0xFFFF;
    model.c = rand() & 0xFFFF;
    step(model);
    if (model.out != sim.step(model.a, model.b, model.c)) {
      return 1;
    }
  }
  return 0;
}
