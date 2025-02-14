#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iomanip>
using std::left;
using std::setprecision;
using std::setw;

#include <algorithm>
using std::sort;

#include <string>
using std::string;

int k{};          // mokinių skaičius
int x;            // mediana arba vidurkis
char choice;      // vartotojo pasirinkimas (y/n)
bool bool_choice; // vartotojo pasirinkimas (1/0)
int pazymys; // 

struct stud_struct
{
    string var, pav;
    vector<int> paz;
    int egz;
    double galutinis;
};

stud_struct temp;
vector<stud_struct> grupe;

double vidurkis(int i)
{
    double vid{};
    for (int j = 0; j < grupe[i].paz.size(); j++)
    {
        vid += grupe[i].paz[j];
    }
    vid /= grupe[i].paz.size();
    return vid;
}

int mediana(int i)
{
    int med{};
    int j;

    vector<int> sorted_paz = grupe[i].paz;
    sort(sorted_paz.begin(), sorted_paz.end());

    j = grupe[i].paz.size() / 2;

    if (grupe[i].paz.size() % 2 == 0)
    {
        cout << "\n%2 == 0";
        med = (sorted_paz[j] + sorted_paz[j + 1]) / 2;
    }
    else
    {
        cout << "\n%2 == 1";
        med = sorted_paz[j];
    }
    return med;
}