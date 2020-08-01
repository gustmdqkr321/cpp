#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <algorithm>
#include <functional>
#include "team.h"
using namespace std;
void swap(int *a){
  *a += 2;
}
int main(){
  int b = 2;
  cout << b;
  swap(&b);
  cout << endl;
  cout << b;
  return 0;
}
