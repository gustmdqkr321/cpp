#include <iostream>
using namespace std;

int main(void)
{
  int numTestCases;
  cin >> numTestCases;

  for(int i=0; i<numTestCases; i++) {
    int numData, data;
    int lastDigit = 1;

    cin >> numData;

    for(int j=0; j<numData; j++) {
      cin >> data;
      lastDigit *= data;
      lastDigit %= 10;
      }

      cout << lastDigit << endl;
  }
  return 0;
}
