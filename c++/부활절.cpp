#include <iostream>
using namespace std;

int main(void)
{
  int numTestCases;
  cin >> numTestCases;

  for(int z = 0; z<numTestCases; z++){
    int y = 0;
    int c, n, t, i, j, k, l,p, q, month, day, five,six,nine,ten,ele,tle,ft;
    cin >> y;
    c = y/100;
    n = y - (y/19 * 19);
    t = (c-17)/25;
    five = c - (c/4) - (c-t)/3;
    six = n*19+15;
    i = five + six;
    j = i - (i/30*30);
    nine = j/28;
    ten = 1-(j/28);
    ele = 29/(j+1);
    tle = (21-n)/11;
    k = j - nine*ten*ele*tle;
    ft = y + (y/4) + j + 2;
    l = ft - c + (c/4);
    p = l - (l/7*7);
    q = k - p;
    month = ((q + 40)/44) + 3;
    day = (q+28) - (month/4*31);

    cout << month << " " << day << endl;
  }
  return 0;
}
