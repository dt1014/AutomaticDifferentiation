#pragma once

namespace ad{

  template <typename T = double>	
  class Dual {
	
  public:
	Dual(T);
	Dual(T, T);
	T getReal();
	T getDerivative();
	void setReal(T);
	void setDerivative(T);
	
  private:
	T _real;
	T _derivative;
  };
  
}

