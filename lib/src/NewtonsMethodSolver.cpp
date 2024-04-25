#include "Polynom.hpp"

#define EPSILON 0.0000000001f
#define MAX_ITERATIONS 10000

namespace polynomial_equation_solver {

bool newtonsMethodSolve(Polynom polynom, double &out_solution, double x0 = 0) {
  static int iterations = 1;

  double y0 = Polynom::functionFromX(polynom, x0);

  Polynom derivativePolynom =
      Polynom(Polynom::getPolynomDerivativeCoefficients(polynom));
  double dy0 = Polynom::functionFromX(derivativePolynom, x0);

  if (iterations > MAX_ITERATIONS) {
    return false;
  }

  if (y0 > -EPSILON && y0 < EPSILON) {
    out_solution = x0;
    return true;
  }

  else {
    iterations += 1;
    double x1 = x0 - (y0 / dy0);
    return newtonsMethodSolve(polynom, out_solution, x1);
  }
}

} // namespace polynomial_equation_solver