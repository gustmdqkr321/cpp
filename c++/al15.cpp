#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

int* sol(){
  static int answer[2] = {0,0};
  int x1,y1,x2,y2,x,y;
  cin >> x1 >> y1 >> x2 >> y2;
  cin >> x >> y;

  if(((x1 <= x) && (x <= x2)) && ((y1 <= y) && (y <= y2))) {
    answer[0] = 0;
    answer[1] = 0;
  }
  else if((x < x1) && (y > y2)){
    answer[0] = ((x1 -x)*(x1-x)+(y-y2)*(y-y2));
    answer[1] = (x1-x)+(y-y2);
  }
  else if((x1<=x)&&(x<=x2)&&(y2<y)){
    answer[0] = (y-y2)*(y-y2);
    answer[1] = y-y2;
  }
  else if((x2<x)&&(y2<y)){
    answer[0] = ((y-y2)*(y-y2) + (x-x2)*(x-x2));
    answer[1] = (x-x2)+(y-y2);
  }
  else if((x2<x)&&(y1<=y)&&(y<=y2)){
    answer[0] = (x-x2)*(x-x2);
    answer[1] = (x-x2);
  }
  else if((x2<x)&&(y<y1)){
    answer[0] = ((x-x2)*(x-x2) + (y1-y)*(y1-y));
    answer[1] = (x-x2)+(y1-y);
  }
  else if((x1<=x)&&(x<=x2)&&(y<y1)){
    answer[0] = (y1-y)*(y1-y);
    answer[1] = (y1-y);
  }
  else if((x<x1)&&(y<y1)){
    answer[0] = ((x1-x)*(x1-x) + (y1-y)*(y1-y));
    answer[1] = (x1-x)+(y1-y);
  }
  else{
    answer[0] = (x1-x)*(x1-x);
    answer[1] = (x1-x);
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
