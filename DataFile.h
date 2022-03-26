#ifndef DATAFILE_H
#define DATAFILE_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Caro.h"

using namespace std;

class DataFile : public Caro
{
private:
    Infor Database[100];
    vector<Infor> Basedata;
    vector<Infor> sortResult;
    char searchName[50];
    vector<double> winRate;
public:
    void WriteFile(string name, int win, int lose, int draw);
    void ReadFile(ifstream&, Infor[], int&);
    void SortInfo();
    void LoadRank();
    double FindClosest(double);

};
#endif // DATAFILE_H
