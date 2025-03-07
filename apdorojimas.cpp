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

double vidurkis_gal(int i)
{
    return (0.4 * vidurkis(i)) + (0.6 * grupe[i].egz);
}

double mediana_gal(int i)
{
    return (0.4 * mediana(i)) + (0.6 * grupe[i].egz);
}

void timer_prad()
{
    if (ar_skaiciuoti_laika)
    {
        start_time = high_resolution_clock::now();
    }
}

void timer_pab()
{
    if (ar_skaiciuoti_laika)
    {
        auto end_time = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end_time - start_time);
        cout << "[Operacija užtruko: " << duration.count() << " ms]" << endl;
    }
}