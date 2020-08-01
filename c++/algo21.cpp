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
    int n,ever;
    cin >> n;
    int arr[n];
    for(int j=0;j<n;j++){
      cin >> arr[j];
    }
    cin >> ever;
    int k = n-ever+1;
    int arr2[k];
    int temp = ever;
    for(int z=0;z<k;z++){
      int sum = 0;
      for(int b=z;b<temp+z;b++){
        sum += arr[b];
        arr2[z] = sum;
    }
  }

    for(int a = 0;a<k;a++){
      arr2[a] = arr2[a]/ever;
    }
    cout << k << " ";
    for(int c = 0;c<k;c++){
      cout << arr2[c] << " ";
    }
    cout << endl;
}
  return 0;
}
