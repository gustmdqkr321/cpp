#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(void)
{
  int numTestCases;
  cin >> numTestCases;
  int x1,y1,x2,y2,x3,y3;
  for(int i=0;i<numTestCases;i++){
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int t1,t2,t3;
    float l1,l2,l3;
    t1 = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
    t2 = (x3-x1)*(x3-x1) + (y3-y1)*(y3-y1);
    t3 = (x3-x2)*(x3-x2) + (y3-y2)*(y3-y2);
    int length[3] = {t1,t2,t3};
    sort(length,length+3);
    l1 = sqrt(length[0]);
    l2 = sqrt(length[1]);
    l3 = sqrt(length[2]);
    if(l1+l2 <= l3){
      cout << 0 << endl;
      continue;
    }
    if(length[0] + length[1] == length[2]){
      cout << 1 << endl;
    }
    if(length[0] + length[1] < length[2]) {
      cout << 2 << endl;
    }
    if(length[0] + length[1] > length[2]) {
      cout << 3 << endl;
    }
  }
  return 0;
}
