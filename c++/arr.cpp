#include <iostream>
using namespace std;

int main(void) {
    int a[2][3] = {{10,-1,3},{2,5,6}};
    int i,j;

    for(i=0;i<2;i++){
      for(j=0;j<3;j++){
        cout << "arr[" << i << "][" << j << "j value: ";
        cout << a[i][j];
        cout << "address: " << &a[i][j] << endl;
      }
    }
    return 0;
}
