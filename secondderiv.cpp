#include <iostream>
#include <cmath>
#include <cstdlib>
extern double f1(double);

double f(double x)
{
  return(x*x*x+3*x*x-2);
}

int main(int argc,char *argv[])
{
   double h,x;
   double deriv;
   if (argc !=2)
     {
        std::cout << "Your input was stank!  Please try again." << std::endl;
        exit(0);
     }
   h=atof(argv[1]);
   for (x=0;x<4;x+=.1)
    { 
       deriv=(f1(x+2*h)-2*f1(x+h)+f1(x))/h/h;
       std::cout << x << " " << f1(x) << " " << deriv << std::endl;
    }
   return(0);
}
