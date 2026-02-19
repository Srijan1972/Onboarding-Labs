#include <bits/stdc++.h>
#include <VExercise2.h>

#define GET_BIT(x, b) (x >> b) & 1 

uint16_t func(uint16_t input) {
  return (input << 1) | (GET_BIT(input, 10) ^ GET_BIT(input ,8) ^ GET_BIT(input, 3) ^ GET_BIT(input , 1));
}

void step(VExercise2& model) {
  model.clk = 1;
  model.eval();
  model.clk = 0;
  model.eval();
}

int test(VExercise2 &model, uint16_t init) {
  model.init = init;
  model.reset = 1;
  step(model);
  model.reset = 0;
  uint16_t curr = ~(init);
  for (uint8_t cycle = 0; cycle < 100; cycle++) {
    if (model.out != curr) {
      std::cout << "Issue at cycle " << (int)cycle << " for initial value " << init << std::endl;
      return 1;
    }
    step(model);
    curr = func(curr);
  }
  return 0;
}

int main() {
  VExercise2 model;
  srand(time(0));
  int ret = 0;
  for (int i = 0; i < 16; i++) {
    ret |= test(model, rand() & 0xFFFF);
  }
  return ret;
}
