#include <iostream>
#include <typeinfo>
#include "Polynom.h"
#include <vector>

using namespace std;

int main() {

   Polynom poly;

   Polynom::printPolynom(poly);

   switch (Polynom::getPolynomOrder(poly)){

      case 0 :
        cout << "Error\n";
        break;
      case 1 :
        cout << Polynom::sovleFirstDegree(poly) << endl;
        break;
      case 2 :
          cout << Polynom::sovleSecondDegree(poly) << endl;
          break;
      default :
        cout << Polynom::newtonsMethodSolve(poly) << endl;
   }

  return 0;
}
