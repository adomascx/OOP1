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

int k = 1; // mokinių skaičius
int n = 5; // pazymiu skaičius

struct stud_struct{
    string var, pav;
    vector<int> paz;
    int egz;
    double galutinis;
};