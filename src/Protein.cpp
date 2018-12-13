#include "Protein.h"
#include "DNA.h"
#include <fstream>
#include <bits/stdc++.h>

Protein::Protein()
{
     type = Hormon;
     seq = new char [100];
}

Protein :: Protein(char *p)
{
         if(100 < strlen(p))
    {
        delete[] seq;
        seq = new char [strlen(p)];
    }
    type = Hormon;
    for(int i=0; i < strlen(p) ; i++)
    {
        this->seq[i] = p[i];
        this->seq[i+1] = '\0';
    }
}

Protein::~Protein()
{
    //dtor
}


void Protein ::Print()
{
    cout << "The Protein Sequence :  " << seq << endl;
    switch(type)
    {
    case 0:
        cout << "The Type : Hormon" << endl;
    case 1:
        cout << "The Type : Enzyme" << endl;
    case 2:
        cout << "The Type : TF" << endl;
    case 3:
        cout << "The Type : Cellular_Function" << endl;
    default:
        cout << "The Type : notype" << endl;
    }
}

void Protein :: setseq(int n){
     seq = new char [n];
}

char* Protein :: getseq(){
     return seq;
}

void Protein :: setseq(char * SEQ){
              if(100 < strlen(SEQ))
    {
        delete[] seq;
        seq = new char [strlen(SEQ)];
    }
    type = Hormon;
    for(int i=0; i < strlen(SEQ) ; i++)
    {
        this->seq[i] = SEQ[i];
        this->seq[i+1] = '\0';
    }
}

void Protein :: setseq(char SEQ , int x){
     seq[x] = SEQ;
}

Protein& Protein ::  operator = (const Protein& rhs)
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
    }
    type = rhs.type;

    return *this;
}


void Protein :: LoadSequenceFromFile(string filename)
{
    int i=0;
    ifstream FromFile;
    FromFile.open("protineloadingfile.txt");
    while(!FromFile.eof())
    {
        FromFile >> seq[i];
        i++;
    }
}

void Protein :: SaveSequenceToFile(string filename)
{
    ofstream outfile;
    outfile.open("protinesaveingfile.txt", ios::app);
    outfile << endl << "The Protine Sequence :  " << seq << endl;
    switch(type)
    {
    case 0:
        cout << "The Type : Hormon" << endl;
    case 1:
        cout << "The Type : Enzyme" << endl;
    case 2:
        cout << "The Type : TF" << endl;
    case 3:
        cout << "The Type : Cellular_Function" << endl;
    default:
        cout << "The Type : notype" << endl;
    }
    outfile.close();
}

DNA * Protein :: GetDNAStrandsEncodingMe(DNA bigDNA){
     int num =0;
     int counter =0;
     int DNA_lenght = bigDNA.getlen();
     int Protein_length = strlen(seq);
     int Temp_length = (Protein_length * 3)+1;
     int Temp_num = (DNA_lenght  / Temp_length ) + (DNA_lenght - Temp_length) +1;
     CodonsTable m;
     bigDNA.BuildComplementaryStrand();
     DNA * result = new DNA[100];
     DNA Temp;
     DNA DNA_seq;
     DNA Comp_seq;
     RNA DNA_seq1;
     RNA Comp_seq1;
     Protein DNA_seq2;
     Protein Comp_seq2;
     for(int i=0; i < Temp_num ; i++){
          int n=0;
          int n1 = 0;
          for(int h =1; h < Temp_length-1+i ; h++){
               Temp.setseq(bigDNA.getseq(h) , n);
               Temp.setseq('\0' , n+1);
               n++;
          }
          if((Temp.getlen()) != (Temp_length -1)){
               return result;
          }
          Temp.BuildComplementaryStrand();
          for(int h =1; h < Temp_length-1+i ; h++ ){
               Comp_seq.setseq(Temp.getseq(n1) , n1);
               Comp_seq.setseq('\0' , n1+1);
               n1++;
          }
          if((Comp_seq.getlen()) != (Temp_length -1)){
               return result;
          }
          Temp.BuildComplementaryStrand();
          DNA_seq1 = Temp.ConvertToRNA();
          DNA_seq2 = DNA_seq1.ConvertToProtein(m);
          Comp_seq.BuildComplementaryStrand();
          Comp_seq1 = Comp_seq.ConvertToRNA();
          Comp_seq2 = Comp_seq1.ConvertToProtein(m);
          if(*this == DNA_seq2){
               cout << "h :   " << (Temp_length -1 +i) <<endl;
               Temp.Print();
               result[num].setseq(DNA_seq2.getseq());
               num++;
          }
          if(*this == Comp_seq2){
               counter++;
               cout << "h :   " << (Temp_length -1 +i) <<endl;
               Comp_seq.Print();
               result[num].setseq(Comp_seq2.getseq());
               num++;

          }
     }
     return result;
}

std :: istream&operator >> (istream&in , Protein& rhs){
     cout << "Enter the Sequence :  " ;
     in >> rhs.seq;
     return in;
}

std :: ostream&operator <<(std::ostream&out ,const Protein&rhs){
     cout << "The Sequence  : ";
     out << rhs.seq;
     cout << endl;
     cout << "The Type :  ";
     out << rhs.type;
     cout << endl;
     return out ;
}

void Protein :: settype (Protein_Type t){
     type =t;
}
Protein_Type Protein :: gettype(){
     return type;
}

Protein Protein :: operator +(const Protein&rhs){
     Protein s;
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
     s.Print();
     cout << endl << endl;
     return s;
}

bool Protein :: operator ==(const Protein&rhs){
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

bool Protein :: operator !=(const Protein& rhs){
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

