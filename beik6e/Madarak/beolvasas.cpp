#include"beolvasas.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

char modBeker()
{
    char mod;
    cout << "Kerlek add meg a beolvasas modjat!(f/b)";
    do{
    cin >> mod;
    cin.ignore();
    }while(mod!='f' && mod!='b');
    return mod;
}

int TermSzamBeker()
{
    bool hiba;
    int szam;
    do{
    cin >> szam;
    hiba = szam<0 || cin.fail();
    if(hiba)
        cin.clear();
    cin.ignore();
    }while(hiba);
    return szam;
}

vector<vector<int> > billBeker()
{
    vector<vector<int> > v;

    cout << "Add meg a telepulesek szamat: ";
    int n = TermSzamBeker();
    cout << "Add meg a madarfajok szamat: ";
    int m = TermSzamBeker();

    v.resize(n);
    for(int i=0; i<n;i++)
    {
        v[i].resize(m);
        for(int j=0; j<m; j++)
        {
            cout << "Add meg a(z) " <<i+1 << ". telepules " <<j+1<<". madarfajat: ";
            v[i][j] = TermSzamBeker();
        }
    }

    return v;
}

vector<vector<int> > fajlBeker()
{
    vector<vector<int> > v;

    ifstream ifs;
    fajltMegnyit(ifs);
    int n;
    ifs>>n;
    int m;
    ifs>>m;

    v.resize(n);
    for(int i=0; i<n;i++)
    {
        v[i].resize(m);
        for(int j=0; j<m; j++)
            ifs>>v[i][j];
    }

    ifs.close();

    return v;
}

void fajltMegnyit(ifstream& ifs)
{
    string fnev;

    cout<<"Adj meg egy fajlnevet: ";
    do
    {
        cin>>fnev;
        ifs.open(fnev.c_str());
    }
    while(ifs.fail());
}
