#include <iostream>
using namespace std;

int main(void)
{
  int numTestCases;
  cin >> numTestCases;
  for (int i = 0; i < numTestCases; i++)  {
    int size;
    cin >> size;
    for(int j=0; j< size;j++){
      if(j< size/2 +1){
        for(int k = 0;k<size;k++){
          if(k < j || size-j <= k){
            cout << "-";
          }
          else if((k-j)%2==0){
            cout << "*";
          }
          else{
            cout << "+";
          }
          if(k==size-1){
            cout << endl;
          }
        }
      }
        else{
          for(int a = 0;a<size;a++){
            if(size -1 -j > a || j < a){
              cout << "-";
            }
            else if((a-j)%2==0){
              cout << "*";
            }
            else {
              cout << "+";
            }
            if(a==size-1){
              cout << endl;
            }
          }
          

        }

    }
  }
  return 0;
}
