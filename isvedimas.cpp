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
    
}