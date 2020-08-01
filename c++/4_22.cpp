#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(){
  //(4)
  cout << "(4)" << endl;
  for(int i=1;i<=5;i++){
    for(int j = 5;j>=1;j--){
      if(j>i){
        cout << " ";
      }
      else{
        cout << j;
      }
    }
    cout << endl;
  }
  //(5)
  cout << "(5)" << endl;
  for(int i=0;i<5;i++){
    int p = 1;
    for(int j=1;j<=5;j++){
      if(j>i){
        cout << p;
        p++;
      }
      else{
        cout << " ";
      }
    }
    cout << endl;
  }
  //(6)
  cout << "(6)" << endl;
  for(int i=0;i<5;i++){
    int k = 5-i;
    for(int j=1;j<=5;j++){
      if(j>i){
        cout << k;
        k--;
      }
      else{
        cout << " ";
      }
    }
    for(int q=2;q<=5;q++){
      if(q<5){
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
