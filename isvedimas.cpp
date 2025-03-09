#include "isvedimas.h"

void rez_isvedimas(ostream &out, char choice_mediana, const vector<stud_struct> &grupe)
{
    out << setw(15) << left << "Vardas"
        << setw(15) << "Pavarde"
        << setw(18) << "Galutinis (Vid.)";
    if (choice_mediana == 'y')
        out << "/ " << setw(20) << "Galutinis (Med.)";
    out << endl
        << string(75, '-') << endl;

    for (const auto &i : grupe)
    {
        out << setw(15) << left << i.var
            << setw(15) << i.pav
            << fixed << setprecision(3) << setw(20)
            << i.galutinisVid << " ";
        if (choice_mediana == 'y')
            out << i.galutinisMed << " ";
        out << endl;
    }
}

void failo_generavimas(string gen_file, int paz_sk, int dydis)
{
    timer_prad();
    ofstream fr(gen_file);

    // antraste
    fr << setw(15) << left << "Vardas" << setw(15) << "Pavarde";
    for (int i = 0; i < paz_sk; i++)
    {
        fr << left << setw(5) << "ND" + to_string(i + 1);
    }
    fr << setw(5) << left << "EGZ" << endl;

    // studentu generavimas
    for (int i = 0; i < dydis; i++)
    {
        fr << setw(15) << left << "Vardas" + to_string(i + 1)
           << setw(15) << "Pavarde" + to_string(i + 1);
        for (int j = 0; j < paz_sk + 1; j++)
        {
            fr << left << setw(5) << (rand() % 10) + 1;
        }
        fr << endl;
    }
    fr.close();

    timer_pab();
}

void diskriminacija(const vector<stud_struct> &grupe)
{
    vector<stud_struct> islaikytojai;
    vector<stud_struct> kartotojai;

    sort(grupe.begin(), grupe.end(), [](const auto &a, const auto &b)
         { return a.galutinisVid > b.galutinisVid; });

    for (int i = 0; grupe[i].galutinisVid >= 5; i++)
        islaikytojai.push_back(grupe[i]);

    for (int i = islaikytojai.size(); i < grupe.size(); i++)
        kartotojai.push_back(grupe[i]);

    ofstream fr_k("kartotojai.txt");
    if (!fr_k)
        throw runtime_error("Nepavyko atidaryti kartotoju failo");

    rez_isvedimas(fr_k, false, kartotojai);
    fr_k.close();

    ofstream fr_i("islaikytojai.txt");
    if (!fr_i)
        throw runtime_error("Nepavyko atidaryti islaikytoju failo");

    rez_isvedimas(fr_i, false, islaikytojai);
    fr_i.close();
}