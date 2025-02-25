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

#define N 32 // sugeneruotų pažymių skaičius

int k{};     // mokinių skaičius
char choice; // vartotojo pasirinkimas (y/n)
int pazymys; // įvestas pažymys

struct stud_struct
{
    string var, pav;
    int *paz;
    int paz_count;
    int egz;
    double galutinisVid;
    double galutinisMed;
};

stud_struct temp;
vector<stud_struct> grupe;

string vardas[] = {"Adomas", "Julius", "Mantas", "Lukas", "Dominykas", "Tomas", "Jonas", "Paulius", "Dovydas", "Karolis", "Rokas", "Simonas", "Martynas", "Arnas", "Justas", "Vilius"};
string pavarde[] = {"Kazlauskas", "Petrauskas", "Jankauskas", "Stankevicius", "Butkus", "Paulauskas", "Urbonas", "Vasiliauskas", "Lukosevicius", "Simkus", "Brazaitis", "Kavaliauskas", "Mikalauskas", "Navickas", "Rimkus", "Zukauskas"};