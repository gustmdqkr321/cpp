#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

int* sol(){
  int n;
  cin >> n;
  static int answer[2] = {0,0};
  int x[n];
  int y[n];
  int xx,yy;
  int sum = 0;
  for(int i=0;i<n;i++){
    cin >> xx;
    cin >> yy;
    x[i] = xx;
    y[i] = yy;
  }
  for(int j=0;j<n-1;j++){
    sum += ((x[j]+x[j+1])*(y[j+1]-y[j]));
  }
  sum += ((x[n-1]+x[0])*(y[0]-y[n-1]));
  if(sum > 0){
    answer[0] = sum;
    answer[1] = 1;
  }
  else{
    answer[0] = -1*sum;
    answer[1] = -1;
  }
  return answer;
}



int main(void){
  int numTestCases;
  int *p;
  cin >> numTestCases;
  for(int i=0;i<numTestCases;i++){
    p = sol();
    cout << p[0] << " "<< p[1] << endl;
  }


  return 0;
}
