#include "SimpleGen.h"

SimpleGen::SimpleGen(int initial):_initial(initial) {
}

int SimpleGen::operator()() {
  _initial++;
  return _initial;
}
