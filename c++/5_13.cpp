#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;

int main(void)
{
  int size = 5;
  int a[size] = {1,2,3,4,5};
  int b[size];
  for(int i=0;i<size;i++){
    b[i] = a[i];
  }
  for(int i=0;i<size;i++){
    cout << b[i] << endl;
  }
  return 0;
}
