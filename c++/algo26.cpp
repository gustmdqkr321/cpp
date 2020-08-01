#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <bitset>
using namespace std;

int main(void)
{
  int numTestCases;
  cin >> numTestCases;
  for(int i=0;i<numTestCases;i++){
    unsigned int a,b;
    cin >> a >> b;
    string bina;
    string binb;
    string reala;
    string realb;
    while(a>1){
      if(a%2==1){
        bina+='1';
      }
      else
        bina+='0';
      a/=2;
    }
    bina+='1';
    reverse(bina.begin(),bina.end());
    reala = bina;
    bina.clear();
    while(b>1){
      if(b%2==1){
        binb+='1';
      }
      else
        binb+='0';
      b/=2;
    }
    binb+='1';
    reverse(binb.begin(),binb.end());
    realb = binb;
    binb.clear();
    int lena = reala.length();
    int lenb = realb.length();
    for(int i=0;i<30-lena;i++){
      reala = '0' + reala;
    }
    for(int i=0;i<30-lenb;i++){
      realb = '0' + realb;
    }
    int answer = 0;
    int haminga = 0;
    int hamingb = 0;
    for(int i=0;i<30;i++){
      if(reala[i] != realb[i]){
        answer += 1;
      }
    }
    for(int i=0;i<30;i++){
      if(reala[i] == '1'){
        haminga += 1;
      }
    }
    for(int i=0;i<30;i++){
      if(realb[i] == '1'){
        hamingb += 1;
      }
    }
    cout << haminga << " " << hamingb << " " << answer << endl;
  }
  return 0;
}
