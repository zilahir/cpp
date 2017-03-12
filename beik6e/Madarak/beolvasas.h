#ifndef BEOLVASAS_H_INCLUDED
#define BEOLVASAS_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>

/*
	A beolvasashoz szukseges (es a beolvasott adatok kiirasara szolgalo) fuggvenyek
*/

char modBeker();
int TermSzamBeker();
std::vector<std::vector<int> > billBeker();
std::vector<std::vector<int> > fajlBeker();
void fajltMegnyit(std::ifstream&);





#endif // BEOLVASAS_H_INCLUDED

