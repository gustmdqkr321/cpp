#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
  int numTestCases;
  cin >> numTestCases;

  int x1,x2,y1,y2 ,x3,x4,y3,y4;
  for(int i=0;i<numTestCases;i++){
    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

  if (y1 == y2) {
    int temp = x1;
    x1 = min(x1,x2);
    x2 = max(temp,x2);
    temp = y3;
    y3 = min(y3,y4);
    y4 = max(temp,y4);
    if((x1 <= x3) && (x2 >= x3))
    {
      if((y3 <= y1) && (y1 <= y4)){
        if((y1 == y3) || (y1 == y4))
        {
          cout << 2 << endl;
        }
        else if((x1 == x3) || (x2 == x3))
        {
          cout << 2 << endl;
        }
        else
        {
          cout << 1 << endl;
        }
    }
      else{
        cout << 0 << endl;
      }
  }
    else{
      cout << 0 << endl;
      }

  }
  else {
    int temp = x3;
    x3 = min(x3, x4);
    x4 = max(temp,x4);
    temp = y1;
    y1 = min(y1,y2);
    y2 = max(temp,y2);
    if((x3<=x1 && x4>=x1)){
      if((y1 <= y3) && (y2>=y3)){
        if((y1 == y3) || (y2 == y3)){
          cout << 2 << endl;
        }
        else if((x1 == x3) || (x1 == x4)){
          cout << 2 << endl;
        }
        else{
          cout << 1 << endl;
        }
      }
      else {
        cout << 0 << endl;
      }
    }
    else {
      cout << 0 << endl;
    }
}
}
return 0;
}
