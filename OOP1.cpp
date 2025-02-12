#include "paz_lib.h"

int main()
{
    // Ivedimas
    stud_struct temp;
    for (int i = 0; i < k; i++)
    {
        cout << "Iveskite mokinio varda: ";
        cin >> temp.var;
        cout << "Iveskite mokinio pavarde: ";
        cin >> temp.pav;
        while (true)
        {
            int pazymys;
            cout << "Iveskite mokinio pazymi (0 jei daugiau pazymiu nera): ";
            cin >> pazymys;
            if (pazymys != 0)
                temp.paz.push_back(pazymys);
            else
                break;
        }
        cout << "Iveskite egzamino rezultata: ";
        cin >> temp.egz;
        grupe.push_back(temp);
    }

    // Galutinio rezultato apskaiciavimas
    for (int i = 0; i < k; i++)
    {
        // Vidurkis
        double vid{};
        for (int j = 0; j < grupe[i].paz.size(); j++)
        {
            vid += grupe[i].paz[j];
        }
        vid /= grupe[i].paz.size();
        // Galutinio pazymio skaiciavimas
        double gal = (0.4 * vid) + (0.6 * grupe[i].egz);
        cout << i << ". vid = " << setprecision(3) << vid << endl;
        cout << i << ". egz = " << grupe[i].egz << endl;
        grupe[i].galutinis = gal;
    }

    cout << setw(15) << left << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << endl;
    cout << "-------------------------------------------------------" << endl;
    for (int i = 0; i < grupe.size(); i++)
    {
        cout << setw(15) << left << grupe[i].var << setw(15) << grupe[i].pav << setw(20) << setprecision(3) <<grupe[i].galutinis << endl; // Print galutinis
    }

    return 0;
}