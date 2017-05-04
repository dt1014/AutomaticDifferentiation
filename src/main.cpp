#include <iostream>
#include "dual.hpp"

using namespace ad;
typedef double MyType;

template <typename T>
T f(T x){
  // return 3.0 + x*x - 2.0*x + x*0.2*x*x; // case1
  // return (x*x + 2) / (1 + x); // case2
  // return 1.0 / (x*x*x + 1); // case3
  //return (4*x*x - 1.0) / (x*2 + 1) / (x - 1); // case4
  return x*x*3.0 + 2*x + 1 - 3.0*x / (x*x + 1.0); // case5
  
}

template <typename T>
T f_derivative(T x){
  // return x*2 - 2.0 + x*0.6*x; // case1
  // return (x*2.0 + x*x - 2.0) / (x*x + 2*x + 1.0); // case2
  // return - x*3.0*x / ((x*x*x + 1)*(1.0 + x*x*x)); // case3
  // return - 1 / (x - 1) / (x - 1.0); // case4
  return 6*x + 2 + 3*(x*x - 1) / (x*x + 1.0) / (x*x + 1); // case5
}

int main(int argc, char *argv[]){
  
  int n = 10;
  MyType k = 0.2;
  
  for(int i = 0; i < n; i++){

	MyType x = i * k;
	Dual<MyType> dualX(x);
	Dual<MyType> f_dualX = f(dualX);
	std::cout << "x: " << x << std::endl;
	std::cout << f(x) << ' ' << f_derivative(x) << std::endl;
	std::cout << f_dualX.getReal() << ' ' << f_dualX.getDerivative() << std::endl;
  } 
}
