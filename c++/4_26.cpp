#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;



int main(void){
  for(int i=1;i<6;i++){
    for(int j=5;j>0;j--){
      if(j<=i){
        cout << j;
      }
      else{
        cout << " ";
      }
    }
    for(int k=2;k<6;k++){
      if(k>i){
        cout << " ";
      }
      else{
        cout << k;
      }
    }
    cout << endl;
  }




  return 0;
}
