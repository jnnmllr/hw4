#include <fstream>
#include <string>
#include <iostream>

using namespace std;

void filter(double* const p, const int N);
double* const reading(const int, const string);
void print(const double* const p, const string fileoutput, const int N);

int main(){
  const int N = 237;
  const string filename = "noisy.txt";
  const string fileoutput = "filtered.txt";
  double* const p = reading(N, filename);
  
 // for(int i=0; i<N; i++)
 //  cout << "p[" << i << "] = " << p[i] << endl;
  
  filter(p,N);
  
 //   for(int i=0; i<N; i++)
 //   cout << "p[" << i << "] = " << p[i] << endl;
    
   print(p,fileoutput,N);
  
  delete[] p;
  
  return 0;
}

void filter(double* const p, const int N){
  double a,b,c;
  a = p[0];
  c = p[0];
  p[0] = (p[N-1]+p[0]+p[1])/3;
  for(int i=1; i<N-1; i++){
    b   = p[i];
    p[i]= (a+p[i]+p[i+1])/3;
    a   = b;
  }
  p[N-1]= (a+p[N-1]+c)/3;
}

double* const reading(const int N, const string fname){
  ifstream in(fname.c_str());
  double* const p = new double[N];
  for(int i=0; i<N; i++){
    in >> p[i];
  }
  in.close();
  return p;
}
  
void print(const double* const p, const string fileoutput, const int N){
  ofstream out(fileoutput.c_str());
  for(int i=0; i<N; i++){
  out << p[i] << endl;
  }
  out.close();
}
