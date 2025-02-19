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
using std::fixed;

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
    int *paz;
    int paz_count;
    int egz;
    double *galutinis;
    int galutinis_count;
};

stud_struct temp;
vector<stud_struct> grupe;

double vidurkis(int i)
{
    double vid{};
    for (int j = 0; j < grupe[i].paz_count; j++)
    {
        vid += grupe[i].paz[j];
    }
    vid /= grupe[i].paz_count;
    return vid;
}

int mediana(int i)
{
    int med{};
    int j;

    int *sorted_paz = grupe[i].paz;
    sort(sorted_paz, sorted_paz + grupe[i].paz_count);

    j = grupe[i].paz_count / 2;

    if (grupe[i].paz_count % 2 == 0)
    {
        med = (sorted_paz[j] + sorted_paz[j + 1]) / 2;
    }
    else
    {
        med = sorted_paz[j];
    }
    return med;
}

void pushback(int*& arr, int& count, int value)
{
    int* temp = new int[count + 1];
    for(int i = 0; i < count; i++)
    {
        temp[i] = arr[i];
    }
    temp[count] = value;
    delete[] arr;
    arr = temp;
    count++;
}

void pushback(double*& arr, int& count, double value)
{
    double* temp = new double[count + 1];
    for(int i = 0; i < count; i++)
    {
        temp[i] = arr[i];
    }
    temp[count] = value;
    delete[] arr;
    arr = temp;
    count++;
}