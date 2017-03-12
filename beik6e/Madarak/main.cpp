#include <iostream>
#include <fstream>
#include <vector>
#include "beolvasas.h"

/*
    Prog 1. beadandó 5. feladat
    Készítette: Szilágyi Erzsébet (BEIK6E)
    2015.05.16

    Feladat:
    Madarak életének kutatásával foglalkozó szakemberek
    n különböző településen m különböző madárfaj előfordulását tanulmányozzák.
    Egy adott időszakban megszámolták,
    hogy az egyes településen egy madárfajnak hány egyedével találkoztak.
    Hány településen fordult elő mindegyik madárfaj?

*/

using namespace std;
bool mindElofordult(const vector<int> &v);
int megszcica(const vector<vector<int> > &v);

int main()
{
     cout << "*********************************************" << endl;
     cout << "* Madarfaj gyakorisag nyilvantarto program  *" << endl;
     cout << "*********************************************" << endl;

     vector<vector<int> > adatok;
     char mod = modBeker();

    if(mod == 'f')
        adatok = fajlBeker();
    else
        adatok = billBeker();

    cout<<"Osszesen "<<megszcica(adatok)<<" db telepules van, ahol minden faj volt."<<endl;



    return 0;
}


int megszcica(const vector<vector<int> > &v)
{
    int db=0;

    for(int i=0; i<v.size();i++)
    {
        if(mindElofordult(v[i])) db++;
    }

    return db;
}

bool mindElofordult(const vector<int> &v)
{
    bool felcsut = true;

    for(int i=0;i<v.size() && felcsut;i++)
    {
        if(v[i]==0) felcsut=false;
    }
    return felcsut;

}

