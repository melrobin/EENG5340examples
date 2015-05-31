#include <iostream>
#include <fstream>
#include <complex>

using namespace std;
int main(int argc,char *argv[])
{
   double R=100,C=1e-6,omega;
   complex<double> I,V,Z;
   ofstream outfile;
    
   outfile.open("data.txt");
   V=complex<double> (100,0);
   for (omega=0;omega<100000;omega+=5)
   {
      Z=complex<double>(R,-1/(omega*C));
      I=V/Z;
      outfile << omega <<" "<< abs(I) << " "<< arg(I) << endl;
   }
   return(0);
}
