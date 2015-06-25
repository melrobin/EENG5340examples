#include <iostream>
#include <random>
#include <cstdlib>
using namespace std;

double g(double x)
{
  return (x*x*x*cos(x));
}
int main(int argc, char * argv[])
{
  if (argc !=4)
  {
     cout << "Usage monte_carlo N a b"<< endl;
     exit(0);
  }
  int N=atoi(argv[1]);
  double b=atof(argv[3]),sum=0;
  double a=atof(argv[2]);
  std::default_random_engine generator;
  std::uniform_real_distribution<double> distribution(a,b);
  for (int i=0; i<N; ++i) 
{
   double x= distribution(generator);
//  cout << number << endl;  
   sum += g(x);
}
  cout <<"Integral: " << (b-a)*sum/N << endl;
  
  return 0;
}
