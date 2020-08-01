#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;



int main(void)
{
  const unsigned int umax = 0xffffffff;
  int numTestCases;
  cin >> numTestCases;
  for(int i=0;i<numTestCases;i++){
    int num;
    cin >> num;
    vector<unsigned int> v;
    for(unsigned int k = 1;;k*=2){
      for(unsigned int l = k;;l*=3){
        for(unsigned int m =l;;m*=5){
          v.push_back(m);
          if(m>umax/5){
            break;
          }
        }
        if(l>umax/3){
          break;
      }
    }
    if(k>umax/2){
      break;
      }
    }
    sort(v.begin(),v.end());

  cout << v[num-1] << endl;
  }
  return 0;
}
