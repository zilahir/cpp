#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <sstream>
#include "beolv.h"

using namespace std;

bool all(int k) {return true;}

int ReadInt(const string &msg, const string &errormsg, bool cond(int) )
{
    int n;
    bool hiba;
    do{
        cout << msg;
        string str;
        cin >> str;
        n = atoi(str.c_str());
        hiba = n==0 && str!="0" || !cond(n);
       if(hiba) cout<< errormsg<< endl;
    }while(hiba);
    return n;
}

vector<vector<int> > beolvfajl(string fnev)
{
    ifstream ifs(fnev.c_str());
    vector<vector<int> > matrix;
    vector<int> akt;
    if(ifs.fail())
    {
        cout<<"Nem sikerult megnyitni a fajlt!"<<endl;
        exit(1);
    }
    while(!ifs.eof())
    {
		string sor;
        while(getline(ifs,sor))
        {
            stringstream ss(sor);
            int szam;
            while(ss>>szam)
            {
                if(szam>=0 && szam<=10)
                {
                    akt.push_back(szam);
                }
            }
            matrix.push_back(akt);
            akt.clear();
        }
    }
    ifs.close();

    return matrix;
}

vector<vector<int> > beolv_matrix()
{
    int n,m;
    vector<vector<int> > matrix;

    do
    {
        cout<<"Add meg a kategóriák számát!: ";
        cin>>n;
    }while(n<1);
    cout<<endl;

    do
    {
        cout<<"Add meg a kutyák számát!: ";
        cin>>m;
    }while(m<1);
    cout<<endl;

    int szam;
    vector<int> akt;

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            do
            {
                cout<<"Adja meg a "<<i+1<<". kategóriában "<<j+1<<". kutyának a pontszámát (0 és 10 között) :";
                cin>>szam;
            }while(szam<0 || szam>10);
            akt.push_back(szam);
        }
        matrix.push_back(akt);
        akt.clear();
    }

    return matrix;
}
