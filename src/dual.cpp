#include <cmath>
#include "dual.hpp"

namespace ad{

  template Dual<int>::Dual(int);
  template Dual<float>::Dual(float);
  template Dual<double>::Dual(double);
  template int Dual<int>::getReal() const;
  template float Dual<float>::getReal() const;
  template double Dual<double>::getReal() const;
  template int Dual<int>::getDerivative() const;
  template float Dual<float>::getDerivative() const;
  template double Dual<double>::getDerivative() const;
  template void Dual<int>::setReal(int);
  template void Dual<float>::setReal(float);
  template void Dual<double>::setReal(double);
  template void Dual<int>::setReal(int);
  template void Dual<float>::setReal(float);
  template void Dual<double>::setReal(double);
  
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
  T Dual<T>::getReal() const{
	return _real;
  }

  template <typename T>
  T Dual<T>::getDerivative() const{
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

  // x + c
  template <typename T1, typename T2>
  Dual<T2> operator +(const Dual<T2> & x, T1 const& c){
  	return Dual<T2>(x.getReal()+c, x.getDerivative());
  }
  template Dual<float> operator +(const Dual<float> &, int const&);
  template Dual<double> operator +(const Dual<double> &, int const&);
  template Dual<float> operator +(const Dual<float> &, float const&);
  template Dual<double> operator +(const Dual<double> &, float const&);
  template Dual<float> operator +(const Dual<float> &, double const&);
  template Dual<double> operator +(const Dual<double> &, double const&);

  // c + x
  template <typename T1, typename T2>
  Dual<T2> operator +(T1 const& c, const Dual<T2> & x){
  	return Dual<T2>(x.getReal()+c, x.getDerivative());
  }
  template Dual<float> operator +(int const&, const Dual<float> &);
  template Dual<double> operator +(int const&, const Dual<double> &);
  template Dual<float> operator +(float const&, const Dual<float> &);
  template Dual<double> operator +(float const&, const Dual<double> &);
  template Dual<float> operator +(double const&, const Dual<float> &);
  template Dual<double> operator +(double const&, const Dual<double> &);

  // x - c
  template <typename T1, typename T2>
  Dual<T2> operator -(const Dual<T2> & x, T1 const& c){
  	return Dual<T2>(x.getReal()-c, x.getDerivative());
  }
  template Dual<float> operator -(const Dual<float> &, int const&);
  template Dual<double> operator -(const Dual<double> &, int const&);
  template Dual<float> operator -(const Dual<float> &, float const&);
  template Dual<double> operator -(const Dual<double> &, float const&);
  template Dual<float> operator -(const Dual<float> &, double const&);
  template Dual<double> operator -(const Dual<double> &, double const&);

  // c - x
  template <typename T1, typename T2>
  Dual<T2> operator -(T1 const& c, const Dual<T2> & x){
  	return Dual<T2>(-x.getReal()+c, -x.getDerivative());
  }
  template Dual<float> operator -(int const&, const Dual<float> &);
  template Dual<double> operator -(int const&, const Dual<double> &);
  template Dual<float> operator -(float const&, const Dual<float> &);
  template Dual<double> operator -(float const&, const Dual<double> &);
  template Dual<float> operator -(double const&, const Dual<float> &);
  template Dual<double> operator -(double const&, const Dual<double> &);

  // x * c
  template <typename T1, typename T2>
  Dual<T2> operator *(const Dual<T2> & x, T1 const& c){
  	return Dual<T2>(x.getReal()*c, x.getDerivative()*c);
  }
  template Dual<float> operator *(const Dual<float> &, int const&);
  template Dual<double> operator *(const Dual<double> &, int const&);
  template Dual<float> operator *(const Dual<float> &, float const&);
  template Dual<double> operator *(const Dual<double> &, float const&);
  template Dual<float> operator *(const Dual<float> &, double const&);
  template Dual<double> operator *(const Dual<double> &, double const&);
  
  // c * x
  template <typename T1, typename T2>
  Dual<T2> operator *(T1 const& c, const Dual<T2> & x){
  	return Dual<T2>(x.getReal()*c, x.getDerivative()*c);
  }
  template Dual<float> operator *(int const&, const Dual<float> &);
  template Dual<double> operator *(int const&, const Dual<double> &);
  template Dual<float> operator *(float const&, const Dual<float> &);
  template Dual<double> operator *(float const&, const Dual<double> &);
  template Dual<float> operator *(double const&, const Dual<float> &);
  template Dual<double> operator *(double const&, const Dual<double> &);

  // x / c
  template <typename T1, typename T2>
  Dual<T2> operator /(const Dual<T2> & x, T1 const& c){
  	return Dual<T2>(x.getReal()/c, x.getDerivative()/c);
  }
  template Dual<float> operator /(const Dual<float> &, int const&);
  template Dual<double> operator /(const Dual<double> &, int const&);
  template Dual<float> operator /(const Dual<float> &, float const&);
  template Dual<double> operator /(const Dual<double> &, float const&);
  template Dual<float> operator /(const Dual<float> &, double const&);
  template Dual<double> operator /(const Dual<double> &, double const&);
  

  // c / x
  template <typename T1, typename T2>
  Dual<T2> operator /(T1 const& c, const Dual<T2> & x){
  	return Dual<T2>(c/x.getReal(),
					-c*x.getDerivative()/std::pow(x.getReal(), 2.0));
  }
  template Dual<float> operator /(int const&, const Dual<float> &);
  template Dual<doubl e> operator /(int const&, const Dual<double> &);
  template Dual<float> operator /(float const&, const Dual<float> &);
  template Dual<double> operator /(float const&, const Dual<double> &);
  template Dual<float> operator /(double const&, const Dual<float> &);
  template Dual<double> operator /(double const&, const Dual<double> &);

  // x + y
  template <typename T>
  Dual<T> operator +(const Dual<T> & x, const Dual<T> & y){
  	return Dual<T>(x.getReal()+y.getReal(), x.getDerivative()+y.getDerivative());
  }
  template Dual<float> operator +(const Dual<float> &, const Dual<float> &);
  template Dual<double> operator +(const Dual<double> &, const Dual<double> &);
  
  // x - y
  template <typename T>
  Dual<T> operator -(const Dual<T> & x, const Dual<T> & y){
  	return Dual<T>(x.getReal()-y.getReal(), x.getDerivative()-y.getDerivative());
  }
  template Dual<float> operator -(const Dual<float> &, const Dual<float> &);
  template Dual<double> operator -(const Dual<double> &, const Dual<double> &);
  
  // x * y
  template <typename T>
  Dual<T> operator *(const Dual<T> & x, const Dual<T> & y){
  	return Dual<T>(x.getReal()*y.getReal(),
  				   (x.getReal()*y.getDerivative()
  					+ x.getDerivative()*y.getReal()));
  }
  template Dual<float> operator *(const Dual<float> &, const Dual<float> &);
  template Dual<double> operator *(const Dual<double> &, const Dual<double> &);
  
  // x / y
  template <typename T>
  Dual<T> operator /(const Dual<T> & x, const Dual<T> & y){
  	return Dual<T>(x.getReal()/y.getReal(),
  				   (x.getDerivative()*y.getReal()
  					-x.getReal()*y.getDerivative())
  				   /std::pow(y.getReal(), 2.0));
  }
  template Dual<float> operator /(const Dual<float> &, const Dual<float> &);
  template Dual<double> operator /(const Dual<double> &, const Dual<double> &);
}
