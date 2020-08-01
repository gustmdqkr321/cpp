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
  int numTestCases;
  cin >> numTestCases;
  int numa,numb;
  for(int i=0;i<numTestCases;i++){
    int a,b;
    int bita[132];
    int bitb[132];
    int sumbit[132];
    int andbit[132];
    int subbit[132];
    int andn = 0;
    int sumn = 0;
    int subn = 0;
    for(int k=0;k<132;k++){
      bita[k] = 0;
      bitb[k] = 0;
      sumbit[k] = 0;
      andbit[k] = 0;
      subbit[k] = 0;
    }
    cin >> a;
    for(int i=0;i<a;i++){
      cin >> numa;
      bita[numa] = 1;
    }
    cin >> b;
    for(int j=0;j<b;j++){
      cin >> numb;
      bitb[numb] = 1;
    }
    for(int z=0;z<132;z++){
      if((bita[z] ==1) && (bitb[z] == 1)){
        andbit[z] = 1;
        andn += 1;
      }
    }
    for(int z=0;z<132;z++){
      if((bita[z] == 1) || (bitb[z] == 1)) {
        sumbit[z] = 1;
        sumn += 1;
      }
    }
    for(int z=0;z<132;z++){
      if((bita[z] == 1) && bitb[z] == 0){
        subbit[z] = 1;
        subn += 1;
      }
    }
    cout << andn << " ";
    for(int f=0;f<132;f++){
      if(andbit[f] == 1){
        cout << f << " ";
      }
    }
    cout << endl;
    cout << sumn << " ";
    for(int f=0;f<132;f++){
      if(sumbit[f] == 1){
        cout << f << " ";
      }
    }
    cout << endl;
    cout << subn << " ";
    for(int f=0;f<132;f++){
      if(subbit[f] == 1){
        cout << f << " ";
      }
    }
    cout << endl;
  }
  return 0;

}
