#pragma once

#include <vector>
using std::vector;

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <iomanip>
using std::fixed;
using std::left;
using std::setprecision;
using std::setw;

#include <algorithm>
using std::sort;

#include <string>
using std::string;

int k{};     // mokinių skaičius
char choice; // vartotojo pasirinkimas (y/n)
int pazymys; // įvestas pažymys

struct stud_struct
{
    string var, pav;
    vector<int> paz;
    int egz;
    vector<double> galutinis;
};

stud_struct temp;
vector<stud_struct> grupe;