#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;


int sol(){
  int number;
  cin >> number;
  if(number<= 1){
    return 0;
  }
  for(int i=2;i<=sqrt(number); i++){
    if(number%i == 0){
      return 0;
    }
  }
  return 1;
}

int main(void){
  int numTestCases;
  cin >> numTestCases;
  for(int i=0;i<numTestCases;i++){
    cout << sol() << endl;
  }
  return 0;
}
