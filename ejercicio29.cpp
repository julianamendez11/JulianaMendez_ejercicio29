#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(){
  double c=0.5; 
  double t_max = 6.0;
  double delta_t = 0.01;
  double delta_x = 0.01;
  double c_prima = delta_x/delta_t; 
  int L = 1.0;
  int n_side=100;
  double t;
  double onda_old[n_side];
  double onda_interm[n_side];  
  double onda_new[n_side];
  int i, j;
    
  ofstream outfile;

  for(i=0;i<n_side;i++){
    onda_old[i] = sin(M_PI*i/n_side);    
  }
  
  onda_old[1]=0.0;
  onda_old[n_side-1]=0.0;
  onda_interm[1]=0.0;
  onda_interm[n_side-1]=0.0;
    
  for(i=0;i<n_side;i++){
    onda_interm[i] = onda_old[i]  + ((c*c)/(2*c_prima*c_prima)) * (onda_old[i+1] + onda_old[i-1]-2*onda_old[i]);    
  }


  outfile.open("onda.dat");
  while(t < t_max){
    for(i=1;i<n_side-1;i++){
      onda_new[i] = 2*onda_interm[i] - onda_old[i]  + ((c*c)/(c_prima*c_prima)) * (onda_interm[i+1] + onda_interm[i-1]-2*onda_interm[i]);
    }
    for(i=0;i<n_side;i++){
      outfile << onda_new[i] << " ";
    }
    outfile << "\n";

    for(i=1;i<n_side-1;i++){
      onda_old[i] = onda_interm[i];
      onda_interm[i]=onda_new[i];
    }
    t = t + delta_t;
  }
  outfile.close();
  return 0;
}
