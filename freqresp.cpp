#include <iostream>
#include <fstream>
#include <complex>
#include <cstdlib>

using namespace std;
int main(int argc,char *argv[])
{
   double R=100,C=1e-6,omega;
   complex<double> I,V,Z;
   ofstream outfile;
   if (argc !=2)
   {
      printf("Not enough arguments...try again!\n");
      exit(0);
   } 
   outfile.open(argv[1]);
   V=complex<double> (100,0);
   for (omega=0;omega<10000;omega+=5)
   {
      Z=complex<double>(R,-1/(omega*C));
      I=V/Z;
      outfile << omega <<" "<< abs(I) << " "<< arg(I) << " " << abs(Z) << " " << arg(Z) << endl;
   }
   return(0);
}
