#include "apdorojimas.h"

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
    int j = grupe[i].paz.size() / 2;

    vector<int> sorted_paz = grupe[i].paz;

    if (grupe[i].paz.size() % 2 == 0)
    {
        nth_element(sorted_paz.begin(), sorted_paz.begin() + j, sorted_paz.end());
        int mid1 = sorted_paz[j];

        nth_element(sorted_paz.begin(), sorted_paz.begin() + j - 1, sorted_paz.end());
        int mid2 = sorted_paz[j - 1];

        med = (mid1 + mid2) / 2;
    }
    else
    {
        nth_element(sorted_paz.begin(), sorted_paz.begin() + j, sorted_paz.end());
        med = sorted_paz[j];
    }

    return med;
}