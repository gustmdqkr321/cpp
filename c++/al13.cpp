#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

int sol(){
  int a,b,c;
  cin >> a >> b >> c;
  int length[3] = {a,b,c};
  sort(length,length+3);
  a = length[0];
  b = length[1];
  c = length[2];
  if (a+b <= c){
    return 0;
  }
  else if ((a==b)&&(b==c)){
    return 1;

  }
  else if ((a*a)+(b*b)==(c*c)){
    return 2;
  }
  else if (a==b || b==c){
    return 3;
  }
  else {
    return 4;
  }
}



int main(void)
{
  int numTestCases;
  cin >> numTestCases;
  for(int i=0;i<numTestCases;i++){
    cout << sol() << endl;

  }




  return 0;
}
