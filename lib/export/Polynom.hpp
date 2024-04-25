
#pragma once

#include <vector>

#include <string>

namespace polynomial_equation_solver {

typedef double POLYNOM_NUM_TYPE;
typedef std::vector<POLYNOM_NUM_TYPE> POLYNOM_COEFFICIENTS;

class Polynom {
public:
  POLYNOM_COEFFICIENTS coefficients_vec;

  Polynom() = delete;
  Polynom(const POLYNOM_COEFFICIENTS &in_coefficients_vec);

  std::string toString();

  int static getPolynomOrder(const Polynom &polynom);

  double static functionFromX(const Polynom &polynom, const double &x);

  POLYNOM_COEFFICIENTS static getPolynomDerivativeCoefficients(
      const Polynom &polynom);

  bool static solvePolynom(const Polynom &polynom, double &out_solution);
};

} // namespace polynomial_equation_solver