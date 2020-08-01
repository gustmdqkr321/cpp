#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;




unsigned int sol(){
  unsigned int num;
  cin >> num;
  unsigned int n = num;
  unsigned int temp = num;
  unsigned int result = 0;
  string str1;
  string s;
  unsigned int lastsum = 0;
  unsigned int answer = 0;
  while(n>1){
    if(n%2==1){
      str1+='1';
    }
    else
      str1+='0';
    n/=2;
  }
  str1+='1';
  reverse(str1.begin(),str1.end());
  s = str1;
  str1.clear();
  int ones = 0;
  for(int j=0; j<s.length();j++){
    if (s[j] == '1'){
      ones += 1;
    }
  }
  if((ones % 2) == 0){
    lastsum = 0;
  }
  else{
    lastsum = 2147483648;
  }

  answer = lastsum+temp;
  if (temp ==0){
    answer = 0;
  }
  return answer;
}






int main(void)
{
  int numTestCases;
  cin >> numTestCases;
  for(int i=0;i<numTestCases;i++){
    cout << sol() << endl;

  }




  return 0;
}
