#include "dual.hpp"

namespace ad{

  template Dual<int>::Dual(int);
  template Dual<float>::Dual(float);
  template Dual<double>::Dual(double); 
  
  template <typename T>
  Dual<T>::Dual(T real){
	_real = real;
	_derivative = 1;
  }
  
  template <typename T>
  Dual<T>::Dual(T real, T derivative){
	_real = real;
	_derivative = derivative;
  }
  
  template <typename T>
  T Dual<T>::getReal(){
	return _real;
  }

  template <typename T>
  T Dual<T>::getDerivative(){
	return _derivative;
  }

  template <typename T>
  void Dual<T>::setReal(T real){
	_real = real;
  }

  template <typename T>
  void Dual<T>::setDerivative(T derivative){
	_derivative = derivative;
  }

}
