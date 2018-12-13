#ifndef CODONSTABLE_H
#define CODONSTABLE_H
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <bits/stdc++.h>


using namespace std;
class Protein;

// struct representing a codon of 3 DNA/RNA characters and ‘\0’
struct Codon
{
  	char value[4];    	    // 4th location for null character
    char AminoAcid;  	    // corresponding AminoAcid according to Table
};

// need to create one object of that class to load the AminoAcids table
// into memory
class CodonsTable
{
  	private:
        Codon codons[64];
        string codonsfilename;
   	public:
 	 	// constructors and destructor
        CodonsTable();
        ~CodonsTable();
        void  setfilename(string s);
        char* getaa(char* p);
 	 	// function to load all codons from the given text file
        void LoadCodonsFromFile(string codonsFileName);
        Codon getAminoAcid(char * value);
        void setCodon(char * value, char AminoAcid, int index);
};

#endif // CODONSTABLE_H
