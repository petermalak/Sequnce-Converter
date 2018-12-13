#ifndef SEQUENCE_H
#define SEQUENCE_H
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Sequence
{
  	protected:
        char * seq;
    public:
 	 	// constructors and destructor
        Sequence();
        Sequence(int length);
        Sequence(Sequence& rhs);
        virtual ~Sequence();
 	 	// pure virtual function that should be overridden because every
        // type of sequence has its own details to be printed
        virtual void Print()= 0;
        virtual void setseq(char *) =0;
        virtual void setseq(char , int) =0 ;
        virtual char* getseq() =0 ;
        virtual void LoadSequenceFromFile(string s) = 0 ;
        virtual void SaveSequenceToFile(string s) = 0;
 	 	// friend function that will find the LCS (longest common
        // subsequence) between 2 sequences of any type, according to
        // polymorphism
        friend char* Align(Sequence * s1, Sequence * s2);

        friend ostream&operator<< (ostream& out , Sequence & rhs);
        friend istream&operator>> (istream& in , Sequence& rhs);
};

#endif // SEQUENCE_H
