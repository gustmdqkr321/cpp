#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

int* sol(){
  static int answer[2] = {0,0};
  int x1,y1,x2,y2,x3,y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  int a;
  a = ((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1));
  if(a==0){
    answer[0] = 0;
    answer[1] = 0;
  }
  else if(a > 0){
    answer[0] = a;
    answer[1] = 1;
  }
  else{
    answer[0] = a*-1;
    answer[1] = -1;
  }
  return answer;


}






  int main(void)
  {
    int numTestCases;
    cin >> numTestCases;
    int *p;

    for(int i=0;i<numTestCases;i++){
      p = sol();
      cout << p[0] << " " << p[1] << endl;

    }

    return 0;
  }
