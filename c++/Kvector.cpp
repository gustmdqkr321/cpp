// #include<iostream>
// #include"Kvector.h"

using namespace std;

template<class T>
Kvector<T>::Kvector(int sz, T value): len(sz){
  cout << this << "Kvector(int) \n";
  m = new T[len];
  for(int i = 0;i<len;i++){
    m[i] = value;
  }
}
template<class T>
Kvector<T>::Kvector(const Kvector& v){
  cout << this << " : Kvector(Kvector&) \n";
  len = v.size();
  m = new T[len];
  for(int i = 0; i < len; i++) m[i] = v.m[i];
}
template<class T>
Kvector<T>::~Kvector(){
  cout << this << " : ~Kvector() \n";
  delete m;
}
template<class T>
Kvector<T>& Kvector<T>::operator=(const Kvector& v){
  delete[] m;
  len = v.len;
  m = new T[len];
  for(int i = 0; i < len; i++)    m[i] = v.m[i];
  return *this;
}
template<class T>
bool Kvector<T>::operator==(const Kvector& v1, const Kvector& v2){
  if(v1.len != v2.len)
      return false;
  for(int i = 0; i < v1.len; i++)
      if(v1.m[i] != v2.m[i])  return false;
  return true;
}
template<class T>
bool Kvector<T>::operator!=(const Kvector& v1, const Kvector& v2){
  return !(v1==v2);
}
int main(){
  Kvector<int> v1(3, 0);  v1.print();
  cout << "v1 : " << v1 << endl;
}
