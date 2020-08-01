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
    int r,s,t;
    cin >> r >> s >> t;
    int a[r][s];
    int b[s][t];
    int mul[r][t];
    for(int i=0;i<r;i++){
      for(int j=0;j<s;j++){
        cin >>  a[i][j];
      }
    }
    for(int i=0;i<s;i++){
      for(int j=0;j<t;j++){
        cin >>  b[i][j];
      }
    }
    for(int i=0;i<r;i++){
      for(int j=0;j<t;j++){
        int sum = 0;
        for(int x=0;x<s;x++){
          sum += a[i][x] * b[x][j];
        }
        mul[i][j] = sum;
      }
    }
        for(int i=0;i<r;i++){
          for(int j=0;j<t;j++){
            cout << mul[i][j] << " ";
          }
          cout << endl;
        }


  }
  return 0;
}
