
#pragma once

namespace polynomial_equation_solver {

class Polynom;

bool sovleFirstDegree(const Polynom &polynom, double &out_solution);
bool sovleSecondDegree(const Polynom &polynom, double &out_solution);
bool sovleThirdDegree(const Polynom &polynom, double &out_solution);

bool newtonsMethodSolve(Polynom polynom, double &out_solution, double x0 = 0);

} // namespace polynomial_equation_solver
