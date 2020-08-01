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
  for(int i=0;i<numTestCases;i++){
    string s;
    cin >> s;
    int r1 = 0;
    int l1 = 0;
    int r2 = 0;
    int l2 = 0;
    int r3 = 0;
    int l3 = 0;
    for(int i=0;i<s.size();i++){
      if (s[i] == '('){
        l1+=1;
      }
      else if (s[i] == ')'){
        r1+=1;
      }
      else if (s[i] == '{'){
        l2+=1;
      }
      else if (s[i] == '}'){
        r2+=1;
      }
      else if (s[i] == '['){
        l3+=1;
      }
      else if (s[i] == ']'){
        r3+=1;
      }
      if(r1 > l1){
        break;
      }
      if(r2 > l2){
        break;
      }
      if(r3 > l3){
        break;
      }
    }
    if(r1 > l1){
      cout << 0 << endl;
      continue;
    }
    if(r2 > l2){
      cout << 0 << endl;
      continue;
    }
    if(r3 > l3){
      cout << 0 << endl;
      continue;
    }
    if((l1 == r1)&&(l2==r2)&&(l3==r3)){
      cout << 1 << endl;
    }
    else{
      cout << 0 << endl;
    }
  }

  return 0;
}
