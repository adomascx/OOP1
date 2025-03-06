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
using std::nth_element;
using std::sort;

#include <string>
using std::string;

#include <sstream>
using std::istringstream;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include <conio.h>

static const int N = 32; // sugeneruotų pažymių skaičius
// static const char input_file[] = "kursiokai.txt"; // failo, iš kurio įvedami duomenys, pavadinimas
static const char output_file[] = "rezultatai.txt"; // failo, į kurį išvedami rezultatų duomenys, pavadinimas

struct stud_struct
{
    string var, pav;
    vector<int> paz;
    int egz;
    double galutinisVid;
    double galutinisMed;
};

extern vector<stud_struct> grupe;

extern string vardas[];
extern string pavarde[];