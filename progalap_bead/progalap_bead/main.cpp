/*
Készítette: Pais Bálint
Neptun: ILTCKB
E-mail: paisbalint@gmail.com
Feladat: Törzsek (D, S, EE, KK)
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int MAXN = 1000, MAXM = 1000, MINEV = 1600, MAXEV = 1899, EVEKSZ = 300;

struct Haboru
{
	string ki;
	string kivel;
	int mettol;
	int meddig;
};


int beolvC(Haboru[]);
int beolvF(Haboru[], int&);

int feladatD(int, Haboru[]);
int feladatS(int, Haboru[]);
int feladatEE(int, Haboru[], int[]);
int feladatKK(int, Haboru[], int);

void beolv_int(int&, int, int);
void beolv_felek(string&, string&, string[], int);
void beolv_evek(int&, int&, int);
int hossz(Haboru);
bool zuluH(Haboru);

int main()
{
	Haboru haboruk[MAXN];
	int n, m, k;

	int beval;
	cout<<"Hogyan szeretned megadni az adatokat? Konzolrol (0) vagy fajlbol (1)?"<<endl;
	beolv_int(beval, 0, 1);
	
	if(beval)
		n = beolvF(haboruk, k);
	else
		n = beolvC(haboruk);


	if(n>1)
	{
		// D) feladat
		cout<<"A haboruk atlagos hossza: "<< feladatD(n, haboruk) <<" ev."<<endl;

		// S) feladat
		int s = feladatS(n, haboruk);
		if(s == -1)
			cout<<"A zuluk nem haboruztak."<<endl;
		else
			cout<<"A zuluk leghosszabb haboruja "<<haboruk[s].ki<<" es "<<haboruk[s].kivel<<" torzsek kozott zajlott "<<haboruk[s].mettol<<" es "<<haboruk[s].meddig<<" kozott."<<endl;

		// EE) feladat
		int nemh[EVEKSZ];
		cout<<"Az elso haboru kezdete es az utolso vege kozt a kovetkezo evekben nem volt haboru:"<<endl;
		for(int i=0; i<feladatEE(n, haboruk, nemh); ++i)
			cout<<nemh[i]<<" ";
		cout<<nemh[0]<<endl;

		// KK) feladat
		if(!beval)
		{
			cout<<"Ez a feladat azon evek szamat adja meg, amikor legalabb k db haboru folyt. Mi legyen k erteke?"<<endl;
			beolv_int(k, 0, 100);
		}
		cout<<feladatKK(n, haboruk, k)<<" db olyan ev volt, amikor legalabb "<<k<<" haboru folyt."<<endl;
	}
	else
		cout<<"Nem volt haboru."<<endl;

	cin>>n;
	return 0;
}


int feladatD(int n, Haboru haboruk[MAXN])
{
	int osszev = 0;
	for(int i=0; i<n; ++i)
	{
		osszev += haboruk[i].meddig - haboruk[i].mettol;
	}
	return osszev/n;
}

int feladatS(int n, Haboru haboruk[MAXN])
{
	int legh = -1;
	int i = 0;
	while(i<n && !zuluH(haboruk[i]))
		++i;
	if(i<n)
	{
		legh = i;
		for(; i<n; ++i)
		{
			if(hossz(haboruk[legh]) < hossz(haboruk[i]) && zuluH(haboruk[i]))
				legh = i;
		}
		return legh;
	}
	else
		return legh;
}

int feladatEE(int n, Haboru haboruk[MAXN], int nemh[EVEKSZ])
{
	int db = 0;

	for(int i=0; i<EVEKSZ; ++i)
		if(haboruk[0].mettol <= i+1600 && i+1600 <= haboruk[n-1].mettol)
		{
			int j = 0;
			while(j<n && (haboruk[j].mettol > i+1600 || haboruk[j].meddig < i+1600))
				++j;
			if(j>=n)
			{
				nemh[db] = i+1600;
				++db;
			}
		}
	return db;
}

int feladatKK(int n, Haboru haboruk[MAXN], int k)
{
	int db = 0;
	for(int i=0; i<EVEKSZ; ++i)
	{
		int hdb = 0;
		int j = 0;
		while(j<n && (hdb < k || hdb < 1))
		{
			if(haboruk[j].mettol <= i+1600 && i+1600 <= haboruk[j].meddig)
				++hdb;
			++j;
		}
		if(hdb >= k)
			++db;
	}
	return db;
}

int beolvF(Haboru haboruk[MAXN], int& k)
{
	ifstream f;
	string fnev;
	bool hiba;
	int n;

	cout<<"Add meg a fajl nevet, amibol be szeretnel olvasni: "<<endl;
	do
	{
		cin>>fnev;
		f.open(fnev);
		hiba = f.fail();
		if(hiba)
		{
			f.clear();
			cout<<"Nem sikerult megnyitni a fajlt. Probald ujra."<<endl;
		}
	}
	while(hiba);
	
	f>>n;
	for(int i=0; i<n; ++i)
	{
		f>>haboruk[i].ki;
		f>>haboruk[i].kivel;
		f>>haboruk[i].mettol;
		f>>haboruk[i].meddig;
	}
	
	f>>k;

	f.close();
	return n;
}

int beolvC(Haboru haboruk[MAXN])
{
	string torzsek[MAXM];
	int n, m;
	bool hiba=true;

	cout<<"Add meg a torzsek szamat."<<endl;
	beolv_int(m, 0, MAXM);

	for(int i=0; i<m; ++i)
	{
		cout<<"Add meg a(z) "<<i+1<<". torzs nevet."<<endl;
		cin>>torzsek[i];
	}

	cout<<"Add meg a haboruk szamat."<<endl;
	beolv_int(n, 0, MAXN);

	for(int i=0; i<n; ++i)
	{
		cout<<"Add meg a(z) "<<i+1<<". haboru resztvevoit. (2 kulonbozo torzs, szokozzel elvalasztva)"<<endl;
		beolv_felek(haboruk[i].ki, haboruk[i].kivel, torzsek, m);
		do
		{
			beolv_evek(haboruk[i].mettol, haboruk[i].meddig, i);
			hiba = haboruk[i-1].mettol > haboruk[i].mettol;
			if(0<i && (hiba = haboruk[i-1].mettol > haboruk[i].mettol))
				cout<<"A haborukat idorendi sorrendben kell beolvasni. Kerlek, az elozonel kesobb kezdodo haborut adj meg."<<endl;
		}
		while(hiba);
	}

	return n;
}

void beolv_int(int &n, int min, int max)
{
	bool hiba;
	do
	{
		cin>>n;
		if(hiba = cin.fail() || n<min || n>max)
		{
			cin.clear();
			cout<<"Hiba. Kerlek, adj meg egy "<<min<<" es "<<max<<" kozotti (zart intervallum) egesz szamot."<<endl;
		}
		cin.ignore(1000, '\n');
	}
	while(hiba);
}

void beolv_felek(string& torzs1, string& torzs2, string torzsek[], int m)
{
	bool hiba;
	do
	{
		cin>>torzs1>>torzs2;
		int i=0, j=0;
		while(i<m && torzs1 != torzsek[i])
			++i;
		while(j<m && torzs2 != torzsek[j])
			++j;
		if(hiba = i>=m || j>=m || torzs1 == torzs2)
		{
			cout<<"Hiba. Kerlek, adj meg ket kulonbozo torzset, szokozzel elvalasztva."<<endl;
		}
		cin.ignore(1000, '\n');
	}
	while(hiba);
}

void beolv_evek(int &ev1, int &ev2, int i)
{
	bool hiba;
	do
	{
		cout<<"Add meg a(z) "<<i+1<<". haboru elso evet."<<endl;
		beolv_int(ev1, MINEV, MAXEV);
		cout<<"Add meg a(z) "<<i+1<<". haboru utolso evet."<<endl;
		beolv_int(ev2, MINEV, MAXEV);
		if(hiba = ev2 < ev1)
			cout<<"Hiba. A haboru utolso eve nem lehet kisebb az elsonel. Probald ujra."<<endl;
	}
	while(hiba);
}

int hossz(Haboru h)
{
	return h.meddig - h.mettol;
}

bool zuluH(Haboru h)
{
	return h.ki == "zulu" || h.kivel == "zulu";
}