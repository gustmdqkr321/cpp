/* 주어진 정수의 합 구하기
국민대학교 소프트웨어융합대학 소프트웨어학부 2학년
                                  20191595 박승현 */
#include <iostream>
using namespace std;

int main(void)
{
  int numTestCases;
  cin >> numTestCases;

  for (int i = 0; i <numTestCases; i++)  {
      int numData, data;
      int sum= 0;

      cin  >> numData;

      for (int j=0; j<numData; j++){
        cin >> data;
      sum += data;
      }
      cout << sum << endl;
      }
      return 0;
}
