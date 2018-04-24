#include <iostream>
#include <cmath>
using namespace std;

void ingauss(double *u, double xmin, double deltax, int n, double sigma, double media);
void im(double *u, double xmin, double deltax, int n, double t);
void der(double *u, double *uv, int n, double deltax, double deltat, double D);
void cop(double *u, double *uv, int n);

void ingauss(double *u, double xmin, double deltax, int n, double sigma, double media){
  double x;
  int i;
  for(i=0; i<n; ++i){
    x = xmin +i*deltax;
    u[i] = exp(-pow((x-media)/sigma,2)*0.5);
   }
}

void im(double *u, double xmin, double deltax, int n, double t){
  double x;
  int i;
  for(i=0;i<n;i++){
    x = xmin +  i * deltax;
    cout << t << " " << x << " " << u[i] << endl;
  }
}

void der(double *u, double *uv, int n, double deltax, double deltat, double D){
  int j;
  for(j=1; j<n-1; ++j){
    u[j] = deltat*D*((uv[j+1]-2*uv[j]+ uv[j-1])/(deltax*deltax))+uv[j];
  }
}
void cop(double *u, double *uv, int n){
  int i;
  for(i=0;i<n;i++){
    u[i] = uv[i];
  }
}

int main(){
  //double C = 1.0;
  double T = 0.5;
  double t = 0.0;
  double x = 3.0;
  double deltax = 0.01;
  double deltat = 0.00001;
  double *u;
  double *uv;
  double *ui;
  double xmin = 0.0;
  double xmax = 2.0;
  int numerox = (xmax-xmin)/(deltax+1);
  double sigma = 0.1;
  int media = 1.0;
  double D = 1.0;
  uv = new double[numerox];
  u = new double[numerox];
  ingauss(uv, xmin, deltax, numerox, sigma, media);
  im(uv, xmin, deltax, numerox, t);
  while(T>t){
    der(u, uv, numerox, deltax, deltat, D);
    cop(uv, u, numerox);
    t += deltat;
  }
  im(uv, xmin, deltax, numerox, t);

  return 0;
}
    


  
