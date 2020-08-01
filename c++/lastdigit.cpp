#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;


 int main(void)
 {
   int numTestCases;
   cin >> numTestCases;
   int answer[2] = {0,0};
   int x1,y1,x2,y2,x3,y3;

   for(int i=0;i<numTestCases;i++){
     cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
     int a;
     a = ((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1))/2;
     if(a==0){
       answer[0] = 0;
       answer[1] = 0;
     }
     else if(a > 0){
       answer[0] = a*2;
       answer[1] = 1;
     }
     else{
       answer[0] = a*-2;
       answer[1] = -1;
     }
     cout << answer[0] << " " << answer[1] << endl;

   }




   return 0;
 }
