#pragma once

namespace ad{

  template <typename T = double>	
  class Dual {
	
  public:
	Dual(T);
	Dual(T, T);
	T getReal() const;
	T getDerivative() const;
	void setReal(T);
	void setDerivative(T);
	
  private:
	T _real;
	T _derivative;
  };

  // x + c
  template <typename T1, typename T2>
  Dual<T2> operator +(const Dual<T2> &, T1 const&);

  // c + x
  template <typename T1, typename T2>
  Dual<T2> operator +(T1 const&, const Dual<T2> &);

  // x - c
  template <typename T1, typename T2>
  Dual<T2> operator -(const Dual<T2> &, T1 const&);

  // c - x
  template <typename T1, typename T2>
  Dual<T2> operator -(T1 const&, const Dual<T2> &);

  // x * c
  template <typename T1, typename T2>
  Dual<T2> operator *(const Dual<T2> &, T1 const&);

  // c * x
  template <typename T1, typename T2>
  Dual<T2> operator *(T1 const&, const Dual<T2> &);

  // x / c
  template <typename T1, typename T2>
  Dual<T2> operator /(const Dual<T2> &, T1 const&);

  // c / x
  template <typename T1, typename T2>
  Dual<T2> operator /(T1 const&, const Dual<T2> &);

  // x + y
  template <typename T>
  Dual<T> operator +(const Dual<T> &, const Dual<T> &);

  // x - y
  template <typename T>
  Dual<T> operator -(const Dual<T> &, const Dual<T> &);

  // x * y
  template <typename T>
  Dual<T> operator *(const Dual<T> &, const Dual<T> &);

  // x / y
  template <typename T>
  Dual<T> operator /(const Dual<T> &, const Dual<T> &);
}




