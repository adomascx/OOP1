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

void failo_generavimas()
{
    string gen_file;
    int dydis;
    cout << "Iveskite mokiniu kieki: " << endl;
    cin >> dydis;
    if (!cin)
        throw runtime_error("Netinkamas mokiniu kiekis. Pasirinkite skaiciu nuo 1 iki 2147483647");

    // failo pavadinimas formatu "studentai[N].txt"
    gen_file = "studentai" + to_string(dydis) + ".txt";

    ofstream fr(gen_file);

    // antraste
    fr << setw(15) << left << "Vardas" << setw(15) << "Pavarde";
    for (int i = 0; i < 5; i++)
    {
        fr << left << setw(5) << "ND" + to_string(i + 1);
    }
    fr << setw(5) << left << "EGZ" << endl;

    // studentu generavimas
    for (int i = 0; i < dydis; i++)
    {
        fr << setw(15) << left << "Vardas" + to_string(i + 1)
           << setw(15) << "Pavarde" + to_string(i + 1);
        for (int j = 0; j < 5 + 1; j++)
        {
            fr << left << setw(5) << rand() % 10;
        }
        fr << endl;
    }
}