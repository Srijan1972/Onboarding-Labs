#include <bits/stdc++.h>
#include <VExercise1.h>

int main() {
  VExercise1 model;
  for (uint8_t i = 0; i < 4; i++) {
    model.op = i;
    model.a = 0;
    model.b = 0;
    do {
      do {
        model.eval();
        uint8_t result;
        switch (i) {
        case 0:
          result = model.a ^ model.b;
          break;
        case 1:
          if (model.b >= 8) result = 0;
          else result = model.a << model.b;
          break;
        case 2:
          if (model.b == 0) result = 0;
          else result = model.a % model.b;
          break;
        case 3:
          result = ~(model.a & model.b);
          break;
        default:
          std::cout << "Invalid operation" << std::endl;
          return 1;
          break;
        }
        if (result != model.out) {
          std::cout << (int)model.op << ' ' << (int)model.a << ' ' << (int)model.b << ' ' << (int)result << ' ' << (int)model.out << std::endl;
          return 1;
        }
      } while (++model.b);
    } while (++model.a);
  }
  return 0;
}
