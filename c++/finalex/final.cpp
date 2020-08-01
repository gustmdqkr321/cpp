#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int numtest;
  cin >> numtest;
  for(int i=0;i<numtest;i++){
    int n;
    int m;
    int st = 0;
    int ball = 0;
    int arrn[4];
    int arrm[4];
    cin >> n >> m;
    if(n == m){
      cout << 4 << " "<<4 << endl;
      continue;
    }
    arrn[0] = n/1000;
    n%=1000;
    arrn[1] = n/100;
    n%=100;
    arrn[2] = n/10;
    n%=10;
    arrn[3] = n;
    arrm[0] = m/1000;
    m%=1000;
    arrm[1] = m/100;
    m%=100;
    arrm[2] = m/10;
    m%=10;
    arrm[3] = m;

    if(arrn[0] == arrn[0]){
      st++;
    }
    if(arrm[0] == arrn[1]){
      ball++;
    }
    else if(arrm[0] == arrn[2]){
      ball++;
    }
    else if(arrm[0] == arrn[3]){
      ball++;
    }
    if(arrm[1] == arrn[1]){
      st++;
    }
    if(arrm[1] == arrn[0]){
      ball++;
    }
    else if(arrm[1] == arrn[2]){
      ball++;
    }
    else if(arrm[1] == arrn[3]){
      ball++;
    }
    if(arrm[2] == arrn[2]){
      st++;
    }
    if(arrm[2] == arrn[0]){
      ball++;
    }
    else if(arrm[2] == arrn[1]){
      ball++;
    }
    else if(arrm[2] == arrn[3]){
      ball++;
    }
    if(arrm[3] == arrn[3]){
      st++;
    }
    if(arrm[3] == arrn[0]){
      ball++;
    }
    else if(arrm[3] == arrn[1]){
      ball++;
    }
    else if(arrm[3] == arrn[2]){
      ball++;
    }

  cout << st << " " << ball << endl;
  }
  return 0;
}
