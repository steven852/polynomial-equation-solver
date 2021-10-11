#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Polynom {

private:
  vector<double> coefficients;
  vector<double> derivativeCoefficients;

  void setCoefficients(){
    cout << "To stop giving coefficients, type a NaN value\n";
    int power = 1;
    string coefficient = "0";

    cout << "constant" << " :";
    cin >> coefficient;
    cout << endl;

    try {
     this->coefficients.push_back(stod(coefficient));
    }
    catch (const std::invalid_argument& ia) {
      cout << "invalid input\n";
      exit(0);
    }

    while(true) {
      cout << "X^" << power << " :";
      cin >> coefficient;
      cout << endl;

       try {
        this->coefficients.push_back(stod(coefficient));
        power += 1;
      }
      catch (const std::invalid_argument& ia) {
        break;
      }
    }
  }

  void calculateDerivativeCoefficients(){
    vector<double> coeffs = this->coefficients;

    for(int i = 1; i < coeffs.size(); i++){
      this->derivativeCoefficients.push_back(coeffs[i]*i);
    }
  }

public:
  Polynom(){
    this->setCoefficients();
    this->calculateDerivativeCoefficients();
  }

  Polynom(vector<double> coefficients){
    this->coefficients = coefficients;
    this->calculateDerivativeCoefficients();
  }

  void reSetCoefficients(){
    this->coefficients = {};
    this->derivativeCoefficients = {};
    cout << "Polynom was reseted input a new polynom\n" << endl;
    setCoefficients();
    calculateDerivativeCoefficients();
  }

  void static printPolynom(Polynom poly){
    string polynom = "";

    for(int i = poly.coefficients.size()-1; i >= 1; i--){
      polynom += to_string(ceil(poly.coefficients[i]))+"x^"+to_string(i)+" + ";
    }
    polynom += to_string(poly.coefficients[0]);

    cout << polynom << endl;
  }

  void static printDerivativeCoefficients(Polynom poly){
    for(int i = 1; i < poly.derivativeCoefficients.size(); i++){
      cout << poly.derivativeCoefficients[i] << endl;
    }
  }

  double static functionOfX(Polynom poly, double x){
    double result = 0;

    for(int i = 0; i < poly.coefficients.size(); i++){
      result += poly.coefficients[i]*pow(x, i);
    }
    return result;
  }

  int static getPolynomOrder(Polynom poly){
    return poly.coefficients.size() - 1;
  }

  double static sovleFirstDegree(Polynom poly){
    vector<double> coeffs = poly.coefficients;
    return -coeffs[0]/coeffs[1];
  }

  double static sovleSecondDegree(Polynom poly){
    vector<double> coeffs = poly.coefficients;
    double delta = pow(coeffs[1], 2) - 4*coeffs[2]*coeffs[0];

    if (delta < 0) {
      cout << "No solution for this equation\n";
      return 0;
    }

    return (-coeffs[1] + sqrt(delta)) / (2*coeffs[2]);
  }

  double static sovleThirdDegree(Polynom poly){
    // TO-DO implement Cardano's formula for a solution.
    return 0;
  }

  double static newtonsMethodSolve(Polynom poly, double x0 = 0){
    double functionX0 = Polynom::functionOfX(poly, x0);
    Polynom derivativePoly = Polynom(poly.derivativeCoefficients);
    double derivativeX0 = Polynom::functionOfX(derivativePoly, x0);
    double x1 = 0;
    static int count = 1;

    if (count > 10000){
      cout << "To many interations happend the polynom porbably does not have a solution" << endl;
      cout << "Final result f(x) = " << functionX0 << " with x = " << x0 << endl;
      return 0;
    }


    if (functionX0 > -0.0000000001f && functionX0 < 0.0000000001f){

      cout << "Number of interations: " << count << endl;
      return x0;
    }

    else {
      count += 1;
      x1 = x0 - (functionX0/derivativeX0);
      return newtonsMethodSolve(poly, x1);
    }

  }
};
