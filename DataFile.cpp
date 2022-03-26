
#include "DataFile.h"
#include <string.h>
#include <vector>
#include <fstream>
#include <regex>
#include <cmath>
#include <unordered_set>
using namespace std;

void DataFile::WriteFile(string name, int win, int lose, int draw)
{
    ofstream input;
    input.open("C:\\Users\\Admin\\Desktop\\cpp\\Caro_Qt2\\CaroQt\\Data.ini", ios::app);
    if (input.fail())
    {
        cout << "Can not open file." << endl;
    }
    else
    {
        input << name << " ";
        input << win << " ";
        input << lose << " ";
        input << draw << " ";
        input << endl;
        input.close();
    }
}
void DataFile::ReadFile(ifstream& read, Infor gameInfo[], int& count)
{
        count = 0;
        while (!read.eof())
        {
            read >> gameInfo[count].name >> gameInfo[count].win >> gameInfo[count].lose >> gameInfo[count].draw;
            count++;
        }
}
void DataFile::SortInfo()
{
    int count;
    ifstream readFile("C:\\Users\\Admin\\Desktop\\cpp\\Caro_Qt2\\CaroQt\\Data.ini");
    ReadFile(readFile, Database, count);
    for (int i = 0; i < count - 1; i++)
    {
        Basedata.push_back(Database[i]);
    }
    unordered_map<string, Infor> mapInfo;
    for (const auto& t : Basedata)
    {
        if(mapInfo.count(t.name) == 0)
        {
            mapInfo[t.name] = t;
        }
        else
        {
           mapInfo[t.name].win += t.win;
           mapInfo[t.name].lose += t.lose;
           mapInfo[t.name].draw += t.draw;
        }
    }
    for (const auto&[key, val] : mapInfo)
    {
        sortResult.push_back(val);
    }
    for (int i = 0; i < sortResult.size(); i++)
    {
        cout << "Name: " << sortResult[i].name << endl;
        cout << "Win : " << sortResult[i].win << endl;
        cout << "Lose: " << sortResult[i].lose << endl;
        cout << "Draw: " << sortResult[i].draw << endl;
    }
    for (int i = 0; i < sortResult.size(); i++)
    {
        double check = WinRate(sortResult[i].win, sortResult[i].lose, sortResult[i].draw);
        winRate.push_back(check);
    }
    sort(winRate.begin(), winRate.end());
    readFile.close();
}
void DataFile::LoadRank()
{
    double target;
    cin >> searchName;
    for (int i = 0; i < sortResult.size(); i++)
    {
        if(strcmp(searchName, sortResult[i].name) == 0)
        {
         cout << "Name: " << sortResult[i].name << endl;
         target = WinRate(sortResult[i].win, sortResult[i].lose, sortResult[i].draw);
         cout << "Win rate : " << target << "%" << endl;
        }
    }
    cout << "----" << endl;
   double opponent = FindClosest(target);
   for (int i = 0; i < sortResult.size(); i++)
   {
       if (opponent == WinRate(sortResult[i].win, sortResult[i].lose, sortResult[i].draw))
       {
           cout << "Suitable opponent: " << sortResult[i].name << endl;
           cout << "Win rate: " << opponent <<  "%" << endl;
       }
   }
}
double DataFile::FindClosest(double target)
{
    if (target == winRate[0]) return winRate[1];
    else if(target == winRate[winRate.size() - 1]) return winRate[winRate.size() - 2];
    else
    {
        for (int i = 0; i < winRate.size(); i++)
        {
            double previous = winRate[i - 1];
            double after = winRate[i + 1];
            return getClosest(previous, after, target);
        }
    }
}


