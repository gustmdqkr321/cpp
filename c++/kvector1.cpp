#include<iostream>
#include<cassert>

using namespace std;

class Kvector{
  int len;
  int *m;
  public :
    Kvector(int sz = 0, int value = 0);
    Kvector(Kvector& v);
    ~Kvector(){
      cout << this << " : ~Kvector() \n";
      delete[] m;
    }
    void print(){
      for(int i=0;i<len;i++){
        cout << m[i] << " ";
      }
      cout << endl;
    }
    void clear(){
      delete[] m;
      m = NULL;
      len = 0;
    }
    int size(){
      return len;
    }
};
Kvector::Kvector(int sz,int value){
  cout << this << "Kvector(int) \n";
  len = sz;
  m = new int[len];
  for(int i = 0;i<len;i++){
    m[i] = value;
  }
}
Kvector::Kvector(Kvector &v){
  cout << this << " : Kvector(Kvector&) \n";
  len = v.len;
  m = new int[v.len];
  for(int i=0;i<len;i++){
    m[i] = v.m[i];
  }
}
int main(){
    Kvector v1(3); v1.print();
    Kvector v2(2,9); v2.print();
    Kvector v3(v2); v3.print();
    v2.clear();
    v2.print();
    v3.print();
    return 0;
}
