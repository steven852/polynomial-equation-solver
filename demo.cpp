#include "Polynom.hpp"

#include <iostream>

int main() {

  using namespace polynomial_equation_solver;

  Polynom polynom = Polynom({-5, 1, 4, 1});

  polynom.toString();

  printf("%s\n", polynom.toString().c_str());

  double solution = 0;
  if (Polynom::solvePolynom(polynom, solution) == true) {
    printf("A solution is = %lf\n", solution);
  }

  else {
    printf("No solution found!\n");
  }

  return 0;
}