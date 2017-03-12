#ifndef _READ_
#define _READ_

#include <string>
#include <vector>

bool all(int k);
int ReadInt(const std::string &msg, const std::string &errormsg, bool cond(int) =  all);
std::vector<std::vector<int> > beolv_matrix();
std::vector<std::vector<int> > beolvfajl(std::string fnev);

#endif
