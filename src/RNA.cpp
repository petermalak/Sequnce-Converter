#include "RNA.h"
#include "DNA.h"
#include "Protein.h"
#include "CodonsTable.h"
#include <fstream>
#include <bits/stdc++.h>

RNA::RNA()
{
    type = mRNA;
    seq = new char [100];
}

RNA::~RNA()
{
    delete [ ] seq;
}

RNA :: RNA(char * SEQ, RNA_Type atype)
{
    if(100 < strlen(SEQ))
    {
        delete[] seq;
        seq = new char [strlen(SEQ)];
    }
    type = atype;
    for(int i=0; i < strlen(SEQ) ; i++)
    {
        this->seq[i] = SEQ[i];
        this->seq[i+1] = '\0';
    }
}

RNA :: RNA(RNA& rhs)
{
    if(100 < strlen(rhs.seq))
    {
        delete[] seq;
        seq = new char [strlen(rhs.seq)];
    }
    type = rhs.type;
    for(int i=0 ; i < strlen(rhs.seq) ; i++)
    {
        this->seq[i] = rhs.seq[i];
        this->seq[i+1] = '\0';
    }
}

void RNA ::Print()
{
    cout << "The RNA Sequence :  " << seq << endl;
    switch(type)
    {
    case 0:
        cout << "The Type : mRNA" << endl;
    case 1:
        cout << "The Type : pre_mRNA" << endl;
    case 2:
        cout << "The Type : mRNA_exon" << endl;
    case 3:
        cout << "The Type : mRNA_intron" << endl;
    default:
        cout << "The Type : notype" << endl;
    }
}

DNA RNA ::ConvertToDNA()
{
    DNA *rhs = new DNA;
    int y= strlen(seq) +1;
    char seq1 [y];
    char seq2 [y];
    strcpy(seq1, seq);
    for(int i=0; i < y ; i++)
    {
        if(seq[i] == 'U')
        {
            seq1[i] = 'T';
            seq1[i+1] = '\0';
        }
        else
        {
            seq1[i] = seq[i];
            seq1[i+1] = '\0';
        }
        strcpy(seq2,seq);
        for(int i=0; i<y ; i++)
        {
            if(seq1[i] == 'A')
            {
                seq2[i] = 'T';
            }
            if(seq1[i] == 'T')
            {
                seq2[i] = 'A';
            }
            if(seq1[i] == 'G')
            {
                seq2[i] = 'C';
            }
            if(seq1[i] == 'C')
            {
                seq2[i] = 'G';
            }

        }
        int n=2;
        for(int i=0; i < y+1 ; i++)
        {
            seq1[i] = seq2[y-n];
            n++;
        }
        rhs->setseq(seq1);
        rhs->BuildComplementaryStrand();
        cout << endl;
        rhs->Print();
        cout << endl;
        return *rhs;
    }

}


Protein& RNA :: ConvertToProtein( CodonsTable & table)
{
    Protein rhs;
    string filename = "RNA_codon_table.txt";
    table.LoadCodonsFromFile(filename);
    rhs.setseq(seq);
    rhs.setseq(table.getaa(seq));
    return rhs;
}

void RNA :: setseq(char*SEQ)
{
    if(100<strlen(SEQ))
    {
        delete [] seq;
        seq = new char [strlen(SEQ)];
    }
    for(int i=0 ; i < strlen(SEQ) ; i++)
    {
        seq[i] = SEQ[i];
        seq[i+1] = '\0';
    }
}
char* RNA:: getseq()
{
    return seq;
}

void RNA :: setseq(char SEQ, int length)
{
    seq[length] = SEQ;
}

int RNA::getlen()
{
    int x;
    x = strlen(seq);
    return x;
}

RNA& RNA ::  operator = (const RNA& rhs)
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

void RNA :: LoadSequenceFromFile(string filename)
{
    int i=0;
    ifstream FromFile;
    FromFile.open("RNAloadingfile.txt");
    while(!FromFile.eof())
    {
        FromFile >> seq[i];
        i++;
    }
}

void RNA :: SaveSequenceToFile(string filename)
{
    ofstream outfile;
    outfile.open("RNAsavingfile.txt", ios::app);
    outfile << endl << "The RNA Sequence :  " << seq << endl;
    switch(type)
    {
    case 0:
        cout << "The Type : mRNA" << endl;
    case 1:
        cout << "The Type : pre_mRNA" << endl;
    case 2:
        cout << "The Type : mRNA_exon" << endl;
    case 3:
        cout << "The Type : mRNA_intron" << endl;
    default:
        cout << "The Type : notype" << endl;
    }
    outfile.close();
}

std:: istream&operator>> (istream&in , RNA&rhs){
     cout << "Enter the Sequence  :   "  ;
     in >> rhs.seq;
     return in ;
}

std:: ostream&operator<< (std::ostream&out , const RNA&rhs){
     cout << "The Sequence  :   "  ;
     out << rhs.seq;
     cout << endl;
     out << rhs.type;
     cout << endl;
     return out ;
}

void RNA :: settype (RNA_Type TYPE){
     type = TYPE;

}

RNA_Type RNA:: gettype(){
     return type;
}
RNA RNA :: operator +(const RNA&rhs){
     RNA s;
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

bool RNA :: operator ==(const RNA&rhs){
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

bool RNA :: operator !=(const RNA& rhs){
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
