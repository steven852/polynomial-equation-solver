#include "Polynom.hpp"

#include <cmath>

namespace polynomial_equation_solver {

bool sovleFirstDegree(const Polynom &polynom, double &out_solution) {
  POLYNOM_COEFFICIENTS coeffs = polynom.coefficients_vec;
  out_solution = -coeffs[0] / coeffs[1];

  return true;
}

bool sovleSecondDegree(const Polynom &polynom, double &out_solution) {
  double delta = pow(polynom.coefficients_vec[1], 2) -
               4 * polynom.coefficients_vec[2] * polynom.coefficients_vec[0];

  if (delta < 0) {
    return false;
  }

  out_solution = (-polynom.coefficients_vec[1] + sqrt(delta)) /
                 (2 * polynom.coefficients_vec[2]);

  return true;
}

bool sovleThirdDegree(const Polynom &polynom, double &out_solution) {
  // TO-DO implement Cardano's formula for a solution.
  return false;
}

} // namespace polynomial_equation_solver