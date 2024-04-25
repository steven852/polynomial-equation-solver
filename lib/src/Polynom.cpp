#include "Polynom.hpp"
#include "Solver.hpp"

#include <cmath>

namespace polynomial_equation_solver {

Polynom::Polynom(const POLYNOM_COEFFICIENTS &in_coefficients_vec) {
  coefficients_vec = in_coefficients_vec;
}

std::string Polynom::toString() {

  if (coefficients_vec.empty() == true) {
    return "";
  }

  else if (coefficients_vec.size() == 1) {
    return std::to_string(coefficients_vec[0]);
  }

  else {
    std::string polynomStr = "";

    for (int i = coefficients_vec.size() - 1; i >= 1; i--) {
      polynomStr += std::to_string(ceil(coefficients_vec[i])) + "x^" +
                    std::to_string(i) + " + ";
    }

    if (coefficients_vec[0] < 0) {
      polynomStr[polynomStr.length() - 2] = '-';
      polynomStr += std::to_string(-coefficients_vec[0]);
    }

    else {
      polynomStr += std::to_string(coefficients_vec[0]);
    }

    return polynomStr;
  }
}

int Polynom::getPolynomOrder(const Polynom &polynom) {
  if (polynom.coefficients_vec.empty() == true ||
      polynom.coefficients_vec.size() == 1) {
    return 0;
  }

  return polynom.coefficients_vec.size() - 1;
}

double Polynom::functionFromX(const Polynom &polynom, const double &x) {
  double result = 0;

  for (int i = 0; i < polynom.coefficients_vec.size(); i++) {
    result += polynom.coefficients_vec[i] * pow(x, i);
  }
  return result;
}

POLYNOM_COEFFICIENTS
Polynom::getPolynomDerivativeCoefficients(const Polynom &polynom) {
  POLYNOM_COEFFICIENTS derivativeCoefficients_vec;
  for (int i = 1; i < polynom.coefficients_vec.size(); i++) {
    derivativeCoefficients_vec.push_back(polynom.coefficients_vec[i] * i);
  }
  return derivativeCoefficients_vec;
}

bool Polynom::solvePolynom(const Polynom &polynom, double &out_solution) {
  bool result = false;

  switch (Polynom::getPolynomOrder(polynom)) {
  case 0:
    result = false;
    break;
  case 1:
    result = sovleFirstDegree(polynom, out_solution);
    break;
  case 2:
    result = sovleSecondDegree(polynom, out_solution);
    break;
  default:
    result = newtonsMethodSolve(polynom, out_solution);
  }

  return result;
}

} // namespace polynomial_equation_solver