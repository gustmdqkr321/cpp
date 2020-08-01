#include<iostream>
#include "Bitset.h"
using namespace std;

BitSet::BitSet(int nbits):Bvector(nbits){

}

void BitSet::insert(int v){
    set(v);
}

BitSet operator+(const BitSet&v1, const BitSet& v2){

    BitSet temp(131);
    for(int i = 0; i < v1.size(); i++){
        if(v1.bit(i) || v2.bit(i)) cout << i << " ";
      }
    return temp;

}


ostream& operator<<(std::ostream& os, const BitSet& s){
    for(int i = 0; i < s.size(); i++){
        if(s.bit(i))   cout << i << " ";
    }
    return os;
}

int main(int argc,char* argv[]){
    try {
      int v1,v2;
    BitSet b1(132),b2(131);
    b1.insert(3); b1.insert(5); b1.insert(8);
    b2.insert(4); b2.insert(5); b2.insert(8); b2.insert(130);
    b1.print(); b2.print();
    cout << "b1= " << b1 << endl;
    cout << "b2= " << b2 << endl;
    cout << "b1+b2= " << b1+b2 << endl;
    v1 = b1.size();
    v2 = b2.size();
    if(v1 != v2) throw IncompatibleException(v1,v2);
    }
    catch (IncompatibleException& e){
      cout << "In + operation, the operands are not compatible."<< endl;
      cout << "The size of the first Bitset is " << e.v1 << endl;
      cout << "The size of the second Bitset is " << e.v2 << endl;
    }
}
