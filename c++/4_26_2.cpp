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
    for(int i=0;i<4;i++){
      int k = 4-i;
      cout << " ";
      for(int j=1;j<=4;j++){
        if(j>i){
          cout << k;
          k--;
        }
        else{
          cout << " ";
        }
      }
      for(int q=2;q<=5;q++){
        if(q<5-i){
          cout << q;
        }
        else{
          cout << " ";
        }
      }
      cout << endl;
  }
  return 0;
}
