#include<iostream>
#include "Avector.h"
using namespace std;

Avector::Avector(int sz, int v, const char *t): Kvector(sz, v){
  cout << this << " : Avector(" << "," << v << t << ")\n";
}
