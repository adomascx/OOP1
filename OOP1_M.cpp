#include "paz_lib_M.h"

int main()
{
    // Ivedimas
    while (true)
    {
        cout << "Iveskite mokinio varda: ";
        cin >> temp.var;
        cout << "Iveskite mokinio pavarde: ";
        cin >> temp.pav;

        // Initialize dynamic arrays for this student
        temp.paz = nullptr;
        temp.paz_count = 0;
        temp.galutinis = nullptr;
        temp.galutinis_count = 0;

        while (true)
        {
            pazymys = 0;
            cout << "Iveskite mokinio pazymi (0, jei daugiau pazymiu nera): ";
            cin >> pazymys;
            if (pazymys)
                push_back(temp.paz, temp.paz_count, pazymys);
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

    cout << "\nAr norite taip pat skaiciuoti mediana?   y/n: ";
    cin >> choice;

    // Galutinio rezultato apskaiciavimas
    for (int i = 0; i < k; i++)
    {
        // Vidurkio apskaiciavimas
        double galutinisVid = (0.4 * vidurkis(i)) + (0.6 * grupe[i].egz);
        push_back(grupe[i].galutinis, grupe[i].galutinis_count, galutinisVid);

        // Medianos apskaiciavimas
        if (choice == 'y')
        {
            double galutinisMed = (0.4 * mediana(i)) + (0.6 * grupe[i].egz);
            push_back(grupe[i].galutinis, grupe[i].galutinis_count, galutinisMed);
        }
    }

    // Formatuotas Isvedimas
    cout << setw(15) << left << "Vardas" << setw(15) << "Pavarde" << setw(18) << "Galutinis (Vid.)";
    if (choice == 'y')
        cout << "/ " << setw(20) << "Galutinis (Med.)";
    cout << endl << string(75, '-') << endl;
    for (auto &i : grupe)
    {
        cout << setw(15) << left << i.var << setw(15) << i.pav << fixed << setprecision(3) << setw(20);
        for (auto j : i.galutinis)
            cout << j;
        cout << endl;
    }

    return 0;
}