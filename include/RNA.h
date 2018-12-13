#ifndef RNA_H
#define RNA_H
#include "DNA.h"
#include "Protein.h"
#include "CodonsTable.h"
#include "Sequence.h"
#include <bits/stdc++.h>

class DNA;
class CodonsTable;
class Protein;
enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};

class RNA : public Sequence
{
  	private:
        RNA_Type type;
  	public:
 	 	// constructors and destructor
        RNA();
        RNA(char * SEQ, RNA_Type atype);
        RNA(RNA& rhs);
        ~RNA();
 	 	// function to be overridden to print all the RNA information
        void Print();
 	 	// function to convert the RNA sequence into protein sequence
        // using the codonsTable object
        Protein& ConvertToProtein( CodonsTable & table);
 	 	// function to convert the RNA sequence back to DNA
        DNA ConvertToDNA();

        /// Setters and Getters for Sequence
        void setseq(char* s);
        void setseq(char , int);
        char* getseq();
        int getlen();

        /// Set an Get for Type
        void settype(RNA_Type t);
        RNA_Type gettype();

        /// Load and Save Functions
        void LoadSequenceFromFile(string);
        void SaveSequenceToFile(string);

        ///Operator overloading Functios
        friend ostream&operator << (std::ostream&out , const RNA& rhs);
        friend istream&operator >> (istream&in , RNA& rhs);
         RNA& operator = (const RNA &);
         RNA operator + (const RNA &);
         bool operator == (const RNA &);
         bool operator != (const RNA &);

};

#endif // RNA_H
