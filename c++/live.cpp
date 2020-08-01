#include <iostream>
using namespace std;

int main(void){
  double d = 10.5;
  char *cp;
  int *ip;
  float *fp;
  double *dp;
  cp = (char *)&d;
  ip = (int *)&d;
  fp = (float *)&d;
  dp = (double *)&d;
  cout << "&d:" << &d << endl;
return 0;
}
