#include "DNA.h"
#include "RNA.h"
#include <bits/stdc++.h>

using namespace std;

DNA::DNA()
{
    type = promoter;
    seq= new char[100]();
    startIndex =0;
    endIndex =100 ;
    complementary_strand = new DNA(0);

}

DNA::~DNA()
{
    delete[] seq;
}

DNA :: DNA(int n)
{
    complementary_strand = nullptr;
    type = promoter;
    seq = new char [100];
}

DNA :: DNA(DNA& rhs)
{
    if(100 < strlen(rhs.seq))
    {
        delete[] seq;
        seq = new char [strlen(rhs.seq)]();
    }
    complementary_strand = rhs.complementary_strand;
    type = rhs.type;
    for(int i=0; i < strlen(rhs.seq); i++)
    {
        this->seq[i] = rhs.seq[i] ;
        this-> seq[i+1] = '\0';
    }
}


DNA :: DNA(char * SEQ, DNA_Type atype)
{
    if(100 < strlen(SEQ))
    {
        delete[] seq;
        seq = new char [strlen(SEQ)]();
    }
    complementary_strand = new DNA(0);
    type = atype;
    for(int i=0; i < strlen(SEQ); i++)
    {
        this->seq[i] = SEQ[i] ;
        this-> seq[i+1] = '\0';
    }

}

void DNA :: setseq(char* seq1)
{
    if(100<strlen(seq1))
    {
        delete [] seq;
        seq = new char [strlen(seq1)]();
    }
    for(int i=0; i < strlen(seq1) ; i++)
    {
        this->seq[i] =seq1[i];
        this->seq[i+1] ='\0';
    }
}

char* DNA :: getseq()
{
    return seq;
}

int DNA :: getlen()
{
     int y;
     y=strlen(seq);
    return y;
}

void DNA :: setseq(char SEQ, int n)
{
    seq[n] = SEQ;
}

char DNA :: getseq (int n)
{
    return seq[n];
}

void DNA :: setstart(int start)
{
    startIndex = start;
}

void DNA :: setend(int End )
{
    endIndex = End;
}

int DNA :: getstart()
{
    return startIndex;
}

int DNA :: getend()
{
    return endIndex;
}

void DNA :: Print()
{
    cout << "The DNA Sequence :  " << seq << endl;
    cout << "The Complementary Strand  :  " << complementary_strand->seq << endl;
    switch(type)
    {
    case 0:
         {
        cout << "The Type : promoter" << endl;
        break;
         }
    case 1:
         {
               cout << "The Type : motif" << endl;
               break;

         }
    case 2:
         {
          cout << "The Type : tail" << endl;
          break;

         }
    case 3:
         {
          cout << "The Type : noncoding" << endl;
          break;

         }
    }
}

void DNA :: BuildComplementaryStrand()
{
    int y = strlen(seq) + 1;
    DNA ob;
    ob.complementary_strand->seq = new char[y];
    for (int i=0; i< y-1; i++)
    {
        if(seq[i] == 'A')
            ob.complementary_strand->seq[i] = 'T';
        else if(seq[i] == 'G')
            ob.complementary_strand->seq[i] = 'C';
        else if(seq[i] == 'T')
            ob.complementary_strand->seq[i] = 'A';
        else if(seq[i] == 'C')
            ob.complementary_strand->seq[i] = 'G';
    }
    int n=2;
    ob.complementary_strand->seq[y-1] = '\0';
    for(int i=0; i<y+1; i++)
    {
        complementary_strand->seq[i] = ob.complementary_strand->seq[y-n];
        n++;
    }
    complementary_strand->seq[y-1] = '\0';
    ///cout << complementary_strand->seq << endl;
}

void DNA :: settype(DNA_Type t)
{
    type = t;
}

DNA_Type DNA :: gettype()
{
    return type;
}


RNA DNA :: ConvertToRNA()
{
    RNA rhs;
    int y=strlen(seq) +1;
    for(int i=0; i < y; i++)
    {
        if(complementary_strand->seq[i] =='T')
        {
            rhs.setseq('U', i);
            rhs.setseq('\0', i+1);
        }
        else
        {
            rhs.setseq(complementary_strand->seq[i], i);
        }
    }
    return rhs;
}

DNA& DNA :: operator = (const DNA& rhs)
{
    if(100<strlen(rhs.seq))
    {
        delete[] seq;
        seq= new char [strlen(rhs.seq)] ();
    }
    for(int i=0; i < strlen(rhs.seq); i++)
    {
        seq[i] = rhs.seq[i];
        seq[i+1] = '\0';
        complementary_strand->seq[i] = rhs.complementary_strand->seq[i];
        complementary_strand->seq[i+1] = '\0';
    }
    type = rhs.type;
    startIndex =rhs.startIndex;
    endIndex =rhs.endIndex ;
    return *this;
}

void DNA :: LoadSequenceFromFile(string filename)
{
    int i=0;
    ifstream FromFile;
    FromFile.open("DNAloadingfile.txt");
    while(!FromFile.eof())
    {
        FromFile >> seq[i];
        i++;
    }
}

void DNA :: SaveSequenceToFile(string filename)
{
    ofstream outfile;
    outfile.open("DNAsavingfile.txt" , ios::app);
    outfile << endl << "The DNA Sequence :  " << seq << endl;
    outfile << "The Complementary Sequence :   " << complementary_strand->seq << endl;
    switch(type)
    {
    case 0:{
        outfile << "The Type : promoter" << endl;
        break;
    }
    case 1:{
        outfile << "The Type : motif" << endl;
        break;
    }
    case 2:{
        outfile << "The Type : tail" << endl;
                break;

    }
    case 3:{
        outfile << "The Type : noncoding" << endl;
                break;

    }

    }
    outfile.close();
}

std :: ostream&operator << (std::ostream& out,const DNA&rhs)
{
    cout << "The Sequence : " ;
    out << rhs.seq;
    cout << endl;
    cout << "The Complementary Sequence :  ";
///    rhs.BuildComplementaryStrand();
    out << (rhs.complementary_strand->seq);
    cout << endl;
    cout << "The Type :  ";
    out << rhs.type;
    cout << endl;
    return out;
}


std ::istream&operator >> (istream&in, DNA &rhs)
{
    cout << "Enter The Sequence :  " << endl;
    in>> rhs.seq;
    cout << endl;
    return in;
}

DNA DNA :: operator +(const DNA&rhs){
     DNA s;
     s.type = type;
     int length = strlen(seq) + strlen(rhs.seq) +1;
     s.seq = new char [length] ();
     for(int i=0; i < strlen(seq) ; i++){
          s.seq[i] = seq[i];
     }
     int n=0;
     for (int i=strlen(seq); i < length; i++ ){
          s.seq[i] = rhs.seq[n];
          s.seq[i+1] = '\0';
          n++;
     }
     s.BuildComplementaryStrand();
     s.Print();
     cout << endl << endl;
     return s;
}

bool DNA :: operator ==(const DNA&rhs){
     if(strlen(seq) != strlen(rhs.seq)){
          return 0;
     }
     else {
          int length = strlen(seq);
          int Count = 0;
          int i=0;
          while (seq[i] == rhs.seq[i] && i <length){
               Count++;
               i++;
          }
          if(Count == length){
               return 1;
          }
          else{
               return 0;
          }
     }
}

bool DNA :: operator !=(const DNA& rhs){
          if(strlen(seq) != strlen(rhs.seq)){
          return 1;
     }
     else {
          int length = strlen(seq);
          int Count = 0;
          int i=0;
          while (seq[i] == rhs.seq[i] && i <length){
               Count++;
               i++;
          }
          if(Count == length){
               return 0;
          }
          else{
               return 1;
          }
     }
}
