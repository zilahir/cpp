#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include "beolv.h"

using namespace std;

bool dontetlen(vector<vector<int> > &mx);
bool egykettoharom(int s);
void kiiras (vector<vector<int> > &mx);

int main()
{
    int s = 0;
    vector<vector<int> > matrix;

    cout << "Válassza ki az adatbevitel módját!\n";
    cout << "1 - adatok beolvasása billentyûzetrõl\n";
    cout << "2 - adatok beolvasása fájlból\n";
    cout << "3 - kilépés\n";
    s = ReadInt("Adatbevitel módja: ","1, 2 vagy 3 lehet", egykettoharom);

    string fnev;
    switch (s) {
        case 1:
            matrix=beolv_matrix();
            break;

        case 2:
            cout<<"Add meg a mátrixot tartalmazó fájl nevét!"<<endl;
            cin>>fnev;

            matrix=beolvfajl(fnev);
            break;

        case 3:
            return 1;
    }

    kiiras(matrix);

    return 0;
}

bool dontetlen(vector<vector<int> > &matrix)
{
    bool dont = false;
    int i = 0;
    while(!dont && i<matrix.size())
    {
        bool azonos = false;
        int max = matrix[i][0];
        for(int j = 1; j < matrix[i].size(); ++j)
        {
            if(max < matrix[i][j])
            {
                max = matrix[i][j];
                azonos = false;
            }
            else if(max == matrix[i][j])
            {
                azonos = true;
            }
        }
        if (azonos)
        {
            dont = true;
            cout << i+1<<". kategóriában döntetlen az eredmény."<<endl;
        }

        i++;
    }
    for(int i = 0; i<matrix.size(); i++)
    {
        for(int j = 0; j<matrix[i].size(); j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return dont;
}

void kiiras (vector<vector<int> > &matrix)
{
    if(matrix.size()==0)
    {
        cout<<"Üres fájl"<<endl;;
    }
    else if(!dontetlen(matrix))
   {
       cout << "Nincs olyan kategória, ahol döntetlen lenne az eredmény."<<endl;

   }
}

bool egykettoharom(int s)
{
    return s>=1 && s<=3;
}

