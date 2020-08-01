/* 주어진 정수의 합 구하기
국민대학교 소프트웨어융합대학 소프트웨어학부 2학년
                                  20191595 박승현 */
#include <iostream>
using namespace std;

int main(void)
{
  int numTestCases;
  cin >> numTestCases;
  int start, final;
  int sum;

  for (int i = 0; i < numTestCases; i++)  {
      start = final = 0;
      sum = 0;
      cin >> start >> final;

      for (int j = start; j< final+1; j++){
        sum += j;




      }
      cout << sum << endl;
    }
    return 0;
}
