#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
double f(double x)
{
  return(x*x*x);
}

int main(int argc, char* argv[])
{
  double h,x=5;
  h=atof(argv[1]);
  std::cout << f(x)<< " " << (f(x+2*h)-2*f(x+h)+f(x))/h/h << std::endl; 
  return(0);
}

