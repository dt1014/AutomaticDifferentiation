#include <iostream>
#include "dual.hpp"

using namespace ad;

template <typename T>
T f(T x){
  return -3*x*x + 2*x + 6;
}

template <typename T>
T f_derivative(T x){
  return -6*x + 2;
}

int main(int argc, char *argv[]){
  
  int n = 100;
  double k = 0.2;
  
  for(int i = 0; i < n; i++){

	double x = i * k;
	Dual<double> dual(x);
	std::cout << x  << ' ' << f(x) << ' ' << f_derivative(x) << std::endl;
  }
  
}
