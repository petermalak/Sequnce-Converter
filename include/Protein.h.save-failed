#ifndef PROTEIN_H
#define PROTEIN_H
#include "Sequence.h"
#include "DNA.h"
#include <bits/stdc++.h>

class DNA;
enum Protein_Type {Hormon, Enzyme, TF, Cellular_Function};

class Protein : public Sequence{
  	private:
        Protein_Type type;
      public:
 	 	// constructors and destructor
 	 	Protein();
 	 	Protein(char * p);
 	 	~Protein();

 	 	/// Setters and Getters
        void setseq(char* );
        void setseq(char , int);
        void setseq(int n);
        char* getseq();
        void settype (Protein_Type TYPE);
        Protein_Type gettype();

        /// Save and Load functions
        void LoadSequenceFromFile(string);
        void SaveSequenceToFile(string);
 	 	// return an array of DNA sequences that can possibly
        // generate that protein sequence
        DNA* GetDNAStrandsEncodingMe(const DNA  bigDNA);

        ///Operator overloading Functions
        friend ostream&operator << (std::ostream&out , const Protein& rhs);
        friend istream&operator >> (istream&in , Protein& rhs);
         Protein& operator = (const Protein &);
         Protein operator + (const Protein &);
         bool operator == (const Protein &);
         bool operator != (const Protein &);

          void Print();

};



#endif // PROTEIN_H
