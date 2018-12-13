#ifndef DNA_H
#define DNA_H
#include "Sequence.h"
#include "RNA.h"
#include <bits/stdc++.h>


class RNA;

    enum DNA_Type{promoter, motif, tail, noncoding};

class DNA : public Sequence
{
  	private:
        DNA_Type type;
        DNA * complementary_strand;
        int startIndex;
        int endIndex;
    public:
 	 	// constructors and destructor
        DNA();
        DNA(char * seq, DNA_Type atype);
        DNA(DNA& rhs);
        ~DNA();
        DNA(int n);

        ///Setters and Getters overridden from the parent class Sequence
        void setseq(char* seq1);
        void setseq(char , int) ;
        char* getseq();
        char getseq(int);
        int getlen();
        char* getcomp(){ return complementary_strand->seq;}
        char getcomp(int x){return complementary_strand->seq[x];}

        ///Setters and Getters for start and end
        void setstart(int start);
        void setend(int End);
        int getstart();
        int getend();

 	 	// function printing DNA sequence information to user
        void Print();
        // function to convert the DNA sequence to RNA sequence
        // It starts by building the complementary_strand of the current
        // DNA sequence (starting from the startIndex to the endIndex), then,
        // it builds the RNA corresponding to that complementary_strand.
        RNA ConvertToRNA();
 	 	// function to build the second strand/pair of DNA sequence
	    // To build a complementary_strand (starting from the startIndex to
        // the endIndex), convert each A to T, each T to A, each C to G, and
        // each G to C. Then reverse the resulting sequence.
        void BuildComplementaryStrand();

        ///Set and Get for DNA type
        void settype(DNA_Type t);
        DNA_Type gettype();

        ///Save and Load functions
        void LoadSequenceFromFile(string);
        void SaveSequenceToFile(string);

        ///Operator overloading for DNA
        friend ostream&operator<< (std::ostream& out ,const DNA& rhs);
        friend istream&operator>> (istream& in , DNA& rhs);
        DNA&operator = (const DNA&);
        DNA operator + (const DNA&);
          bool operator == (const DNA&);
          bool operator != (const DNA&);

  };

#endif // DNA_H
