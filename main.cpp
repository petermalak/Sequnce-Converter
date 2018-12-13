// Course:  CS213 - Programming II  - 2018
// Title:   Assignment 4 - Task 2
// Program: Histrogram for student grades
// Author:  Peter Malak Mikaeal
// ID :     20170079
// Date:    12 November 2018
// Version: 1.0

#include <iostream>
#include <cstring>
#include "Sequence.h"
#include "DNA.h"
#include "RNA.h"
#include "CodonsTable.h"
#include "Protein.h"
#include "windows.h"
#include <iomanip>

using namespace std;

int MAX(int n1, int n2)
{
    int maximum = 0;
    if(n1 > n2){
        maximum = n1;
    }
    else if(n2 > n1){
        maximum = n2;
    }
    else{
        maximum = n1;
    }
    return maximum;
}

char* Align(Sequence* s1, Sequence* s2)
{
    int temp[strlen(s1->seq) + 1][strlen(s2->seq) + 1];
    for(int i = 0; i <= strlen(s1->seq); i++){
        for(int j = 0; j <= strlen(s2->seq); j++){
            if(i == 0 || j == 0){
                temp[i][j] = 0;
            }
            else{
                if(s1->seq[i-1] == s2->seq[j-1]){
                    temp[i][j] = temp[i-1][j-1] + 1;
                }
                else{
                    temp[i][j] = MAX(temp[i][j-1], temp[i-1][j]);
                }
            }
        }
    }
    int length = temp[strlen(s1->seq)][strlen(s2->seq)];
    char* LCS = new char[length];
    int k = 0;
    for(int i = 1; i <= strlen(s1->seq); i++){
        for(int j = 1; j <= strlen(s2->seq); j++){
            if(temp[i][j] == temp[i-1][j-1] + 1 && temp[i][j] != temp[i-1][j] && temp[i][j-1]){
                LCS[k] = s1->seq[i];
                LCS[k+1] = '\0';
                k++;
            }
        }
    }
    char* A = new char[length];
    int j = 0;
    for(int i = 0; i < strlen(LCS); i++){
        if(LCS[i] != LCS[i+1]){
            A[j] = LCS[i];
            A[j+1] = '\0';
            j++;
        }
    }
    return A;
}

int main()
{
    cout << " Enter the type of the sequence you want to deal with: \n 1- DNA\n 2- RNA\n 3- Protein\n Your choice: ";
    int choice;
    cin >> choice;
    if(choice == 1){
        cout << " 1- Enter the DNA sequence\n 2- Load the DNA sequence from a file\n Your choice: ";
        int c;
        cin >> c;
        if(c == 1){
            DNA d;
            cin >> d;
            cout << " Enter what do you want to do: \n 1- Print the sequence\n 2- Convert to RNA\n 3- Save the sequence to a file\n 4- Assign it to another DNA\n 5- Merge it with another sequence\n 6- Compare it with another sequence\n Your choice: ";
            int c1;
            cin >> c1;
            if(c1 == 1){
                cout << d << endl;
            }
            else if(c1 == 2){
              cout  <<  d.ConvertToRNA();
            }
            else if(c1 == 3){
                cout << " Enter the name of the file that you want to save the sequence in it: ";
                char Name[100];
                cin >> Name;
                d.SaveSequenceToFile(Name);
            }
            else if(c1 == 4){
                DNA d1;
                d1 = d;
                cout << d1 << endl;
            }
            else if(c1 == 5){
                cout << " now enter the DNA sequence that you want to merge it with the first one.." << endl;
                DNA d1;
                cin >> d1;
                cout << (d + d1) << endl;
            }
            else if(c1 == 6){
                cout << " now enter the DNA sequence that you want to compare it with the first one.." << endl;
                DNA d1;
                cin >> d1;
                cout << (d == d1) << endl;
            }
        }
        else if(c == 2){
            DNA d;
            cout << " Enter the name of the file that you want to load the sequence from it: ";
            char Name[100];
            cin >> Name;
            d.LoadSequenceFromFile(Name);
        }
    }
    else if(choice == 2){
        cout << " 1- Enter the RNA sequence\n 2- Load the RNA sequence from a file\n Your choice: ";
        int c;
        cin >> c;
        if(c == 1){
            RNA r;
            cin >> r;
            cout << " Enter what do you want to do: \n 1- Print the sequence\ 2- Convert to Protein\ 3- Save the sequence to a file\n 4- Assign it to another DNA\n 5- Merge it with another sequence\n 6- Compare it with another sequence\n 7- Convert to DNA\n Your choice: ";
            int c1;
            cin >> c1;
            if(c1 == 1){
                cout << r << endl;
            }
            else if(c1 == 2){
                ///r.ConvertToProtein(CodonsTable& table);
            }
            else if(c1 == 3){
                cout << " Enter the name of the file that you want to save the sequence in it: ";
                char Name[100];
                cin >> Name;
                r.SaveSequenceToFile(Name);
            }
            else if(c1 == 4){
                RNA r1;
                r1 = r;
                cout << r1 << endl;
            }
            else if(c1 == 5){
                cout << " now enter the RNA sequence that you want to merge it with the first one.." << endl;
                RNA r1;
                cin >> r1;
                cout << (r + r1) << endl;
            }
            else if(c1 == 6){
                cout << " now enter the RNA sequence that you want to compare it with the first one.." << endl;
                RNA r1;
                cin >> r1;
                cout << (r == r1) << endl;
            }
            else if(c1 == 7){
                r.ConvertToDNA();
            }
        }
        else if(c == 2){
            RNA r;
            cout << " Enter the name of the file that you want to load the sequence from it: ";
            char Name[100];
            cin >> Name;
            r.LoadSequenceFromFile(Name);
        }
    }
    else if(choice == 3){
        cout << " 1- Enter the Protein sequence\n 2- Load the Protein sequence from a file\n Your choice: ";
        int c;
        cin >> c;
        if(c == 1){
            Protein p;
            cin >> p;
            cout << " Enter what do you want to do: \n 1- Print the sequence\ 2- Save the sequence to a file\n 3- Assign it to another DNA\n 4- Merge it with another sequence\n 5- Compare it with another sequence\n Your choice: ";
            int c1;
            cin >> c1;
            if(c1 == 1){
                cout << p << endl;
            }
            else if(c1 == 2){
                cout << " Enter the name of the file that you want to save the sequence in it: ";
                char Name[100];
                cin >> Name;
                p.SaveSequenceToFile(Name);
            }
            else if(c1 == 3){
                Protein p1;
                p1 = p;
                cout << p1 << endl;
            }
            else if(c1 == 4){
                cout << " now enter the RNA sequence that you want to merge it with the first one.." << endl;
                Protein p1;
                cin >> p1;
                cout << (p + p1) << endl;
            }
            else if(c1 == 5){
                cout << " now enter the RNA sequence that you want to compare it with the first one.." << endl;
                Protein p1;
                cin >> p1;
                cout << (p == p1) << endl;
            }
        }
        else if(c == 2){
            Protein p;
            cout << " Enter the name of the file that you want to load the sequence from it: ";
            char Name[100];
            cin >> Name;
            p.LoadSequenceFromFile(Name);
        }
    }
    return 0;
}
