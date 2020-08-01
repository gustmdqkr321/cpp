#include <iostream>
using namespace std;

int main(void)
{
  int numTestCases;
  cin >> numTestCases;

  for(int i =0; i<numTestCases; i++)
  {
      int numData, data;
      int last1Digit = 1;

      cin >> numData;

      for (int j = 0; j<numData; j++)
      {
          cin >> data;
          data %= 10;
          last1Digit *= data;
          last1Digit %= 10;
      }

      cout << last1Digit << endl;
  }

  return 0;
}
