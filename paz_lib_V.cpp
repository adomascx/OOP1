#include "paz_lib_V.h"

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
        med = (sorted_paz[j] + sorted_paz[j + 1]) / 2;
    }
    else
    {
        med = sorted_paz[j];
    }
    return med;
}