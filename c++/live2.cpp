/* 주어진 정수의 합 구하기
국민대학교 소프트웨어융합대학 소프트웨어학부 2학년
                                  20191595 박승현 */
#include <iostream>
using namespace std;

int main(void)
{
  int numTestCases;
  cin >> numTestCases;
  int number;
  for (int i = 0; i < numTestCases; i++)  {
      cin >> number;
      for (int j = 0; j<number; j++){
        for(int k = 0;k<number; k++){
          if(j == number/2 && k == number/2){
            cout << "O";
          }
          else if(j == number/2){
            cout << "+";
          }
          else if(k == number/2){
            cout << "I";
          }
          else if(j+k == number-1) {
            cout << "*";
          }
          else{
            cout << ".";
          }
          if(k==number-1){
            cout << endl;
          }
        }
      }
}
  return 0;
}
