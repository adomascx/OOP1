#include "paz_lib.h"

int main()
{
    // Ivedimas
    while (true)
    {
        cout << "Iveskite mokinio varda: ";
        cin >> temp.var;
        cout << "Iveskite mokinio pavarde: ";
        cin >> temp.pav;
        while (true)
        {
            pazymys = 0;
            cout << "Iveskite mokinio pazymi (0, jei daugiau pazymiu nera): ";
            cin >> pazymys;
            if (pazymys)
                temp.paz.push_back(pazymys);
            else
                break;
        }
        cout << "Iveskite egzamino rezultata: ";
        cin >> temp.egz;
        grupe.push_back(temp);
        k++;

        cout << "Ar norite toliau ivesti mokinius?  y/n: ";
        cin >> choice;
        if (choice == 'n')
            break;
    }

    cout << "\nAr norite skaiciuoti mediana ar vidurki?\n(0 - Mediana, 1 - Vidurkis): ";
    cin >> bool_choice;

    // Galutinio rezultato apskaiciavimas
    for (int i = 0; i < k; i++)
    {
        if (bool_choice)
        {
            x = vidurkis(i);
        }
        else
        {
            cout << "3";
            x = mediana(i);
        }

        //double gal = (0.4 * x) + (0.6 * grupe[i].egz);
        double gal = x;
        grupe[i].galutinis = gal;
    }

    // Formatuotas Isvedimas
    cout << setw(15) << left << "Vardas" << setw(15) << "Pavarde";
    bool_choice? cout << setw(20) << "Galutinis (Vid.)\n" : cout << setw(20) << "Galutinis (Med.)\n";
    cout << "-------------------------------------------------------" << endl;
    for (int i = 0; i < grupe.size(); i++)
    {
        cout << setw(15) << left << grupe[i].var << setw(15) << grupe[i].pav << setw(20) << setprecision(3) << grupe[i].galutinis << endl;
    }

    return 0;
}