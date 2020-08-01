#include <iostream>
using namespace std;

int main(void)
{
  int numTestCases;
  int k = 0;
  cin >> numTestCases;
  for (int i = 0; i < numTestCases; i++)  {
    cin >> k;
    for(int j =1; j <=k;j++){
      int n = k-1;
      int num = j;
      for(int z = 1;z<=j;z++){

        cout << num << " ";
        num = num + n;
        n= n-1;
        if(z==j){
          cout << endl;
        }

    }
  }

}return 0;
}
