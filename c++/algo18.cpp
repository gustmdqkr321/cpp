#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(void)
{
  int numTestCases;
  cin >> numTestCases;
  for(int i=0;i<numTestCases;i++){
    int row,col;
    cin >> row >> col;
    int a[row][col];
    int b[row][col];
    int sum[row][col];
    for(int r=0;r<row;r++){
      for(int c=0;c<col;c++){
        cin >> a[r][c];
      }
    }
    for(int r2=0;r2<row;r2++){
      for(int c2=0; c2<col;c2++){
        cin >> b[r2][c2];
      }
    }
    for(int sr=0;sr<row;sr++){
      for(int sc=0;sc<col;sc++){
        sum[sr][sc] = a[sr][sc] + b[sr][sc];
      }
    }
    for(int rr=0;rr<row;rr++){
      for(int rc=0;rc<col;rc++){
        cout << sum[rr][rc] << " ";
      }
      cout << endl;
    }
}
  return 0;

}
