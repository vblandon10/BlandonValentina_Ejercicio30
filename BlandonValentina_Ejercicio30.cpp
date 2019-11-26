#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void solucion_diffusion(int Nx, string filename);

int main(void){
    solucion_diffusion(10, "dat10.dat");
    solucion_diffusion(30, "dat30.dat");
    solucion_diffusion(100, "dat100.dat");
}

void solucion_diffusion(int Nx, string filename){
    
    double x1 = -1;
    double x2 = 1;
    double dx = (x2-x1)/Nx;
    double D = 1;
    double s = -1;
    double dt = dx*dx/(2*D);
    double psi_new[Nx+2],psi[Nx+2];
    double normalized_psi_change,max_change,max_psi;
    normalized_psi_change=1;
    
    //Initial conditions
    for(int j = 0; j < Nx+2; j++){
            psi[j]=0;
    }
    //Iterative solution
    while (normalized_psi_change>10e-5){
        max_change=0;
        max_psi=0;
        
        for (int j = 1; j < Nx+1; j++){
            psi_new[j]=(1.0/2)*psi[j+1]+(1.0/2)*psi[j-1]+s*dx*dx/(2*D);
            if ( abs(psi_new[j]-psi[j])>max_change ){
                max_change=abs(psi_new[j]-psi[j]);
            }
            if ( abs(psi_new[j])>max_psi ){
                max_psi=abs(psi_new[j]);
            }
            
        }
        normalized_psi_change=max_change/max_psi;
        for(int j  = 1; j < Nx+1; j++){
            psi[j]=psi_new[j];
            
        }
        
    }
    
    //Print solution
    ofstream outfile;
    outfile.open(filename);
    for(int j  = 0; j < Nx+2; j++){
        outfile << (j-1)*dx + x1 << ' ' <<  psi[j] << endl;
    }
    
}
    