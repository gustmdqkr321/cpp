#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

void reverse(int inumbers[], int size){
  int temp[size];
  for(int i = 0; i<size;i++){
    temp[i] = inumbers[size - (i + 1)];
  }
  for(int i = 0; i<size;i++){
    inumbers[i] = temp[i];
  }
}
int main(){
  int inumbers4[8] = {10,20,30,40,50,60,70,80};
  cout << "원" << endl;
  for(int i = 0; i<8;i++){
    cout << " " << inumbers4[i];
  }
  cout << endl;
  reverse(inumbers4,8);
  cout << "()" << endl;
  for(int i = 0; i<8;i++){
    cout << " " << inumbers4[i];
  }
  cout << endl;
}
