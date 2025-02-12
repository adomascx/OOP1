#include <vector>
#include <iostream>
#include <iomanip>
using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::left;
using std::setw;
using std::setprecision;

int k = 1; // mokinių skaičius

struct stud_struct{
    string var, pav;
    vector<int> paz;
    int egz;
    double galutinis;
};

vector<stud_struct> grupe;