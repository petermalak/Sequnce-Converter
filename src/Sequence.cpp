#include "Sequence.h"
#include "DNA.h"
#include <bits/stdc++.h>

using namespace std;
Sequence::Sequence()
{
            seq = new char[100];
}

 Sequence::~Sequence()
{
    ///delete []seq;
}

Sequence:: Sequence(int length){
    seq  = new char[length];
}

Sequence:: Sequence(Sequence& rhs){
    if(100 < strlen(rhs.seq)){
            delete [ ] seq;
            seq = new char [strlen(rhs.seq)]();
    }
    for(int i=0; i < strlen(rhs.seq) ; i++){
            seq[i] = rhs.seq[i];
            rhs.seq[i+1] = '/0';
    }
}


/**
char* Align(Sequence * s1 , Sequence * s2){
      Sequence * temp = new DNA;
      int x = strlen(s1->seq);
      int y = strlen(s2->seq);
      if( x>=y){
            for(int i =0 ; i < y ; i++){
                    if(s1->seq[i] == s2->seq[i]){
                         ((DNA*)temp) -> setseq(s2->seq[i] , i);
                    }
            }
      }
      else{
          for(int i=0; i < x; i++){
                    if(s1->seq[i] == s2->seq[i]){
                         ((DNA*)temp) -> setseq(s1->seq[i] , i);
                    }
          }
      }
      cout << "The Align Sequence :  " << temp->seq << endl;
      return temp->seq;
}
**/


std :: ostream&operator << (ostream& out, Sequence&rhs)
{
    cout << "The Sequence : " ;
    out << rhs.seq;
    cout << endl;
    return out;
}


std ::istream&operator >> (istream&in, Sequence &rhs)
{
    cout << "Enter The Sequence :  " << endl;
    in>> rhs.seq;
    cout << endl;
    return in;
}

