/* 주어진 정수의 합 구하기
국민대학교 소프트웨어융합대학 소프트웨어학부 2학년
                                  20191595 박승현 */
#include <iostream>
using namespace std;

int main(void)
{
  int numTestCases;
  cin >> numTestCases;

  for (int i = 0; i < numTestCases; i++)  {
      int numData, data;
      int max, min;
      cin  >> numData;
      cin >> data;
      max = min = data;
      for (int j=0; j<numData-1; j++){
        cin >> data;

        if (min > data){
          min = data;
        }
        if ( max < data){
          max = data;
        }

      }
      cout << max << " " << min << endl;

      }
      return 0;
}
