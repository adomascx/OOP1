#include "paz_lib_M.cpp"
#include "paz_lib_M.h"

int main()
{
    srand(time(NULL));

    // Ivedimas
    cout << "Kaip norite ivesti pazymius/studentu vardus?:" << endl
         << "1 - Ranka" << endl
         << "2 - generuoti TIK pazymius" << endl
         << "3 - generuoti studentu vardus IR pazymius" << endl
         << "4 - baigti darba" << endl;
    cin >> choice;

    switch (choice)
    {
    case '1':
        while (true)
        {
            temp.paz = nullptr;
            temp.paz_count = 0;

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
                    pushback(temp.paz, temp.paz_count, pazymys);
                else
                    break;
            }

            // Patikrinti, ar naudotojas ivede pazymiu
            // Jei ne, baigti programa
            if (temp.paz_count == 0)
            {
                cout << "Nera ivestu pazymiu. Prasome ivesti bent viena pazymi." << endl;
                return 1;
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
        break;

    case '2':
        while (true)
        {
            temp.paz = nullptr;
            temp.paz_count = 0;

            cout << "Iveskite mokinio varda: ";
            cin >> temp.var;
            cout << "Iveskite mokinio pavarde: ";
            cin >> temp.pav;

            for (int i = 0; i < N; i++)
            {
                pushback(temp.paz, temp.paz_count, (rand() % 10));
            }
            temp.egz = rand() % 10;

            grupe.push_back(temp);

            k++;

            cout << "Ar norite toliau ivesti mokinius?  y/n: ";
            cin >> choice;
            if (choice == 'n')
                break;
        }
        break;

    case '3':

        cout << "Kiek mokiniu norite sugeneruoti?: ";
        int i;
        cin >> i;
        k = i;
        for (; i; i--)
        {
            temp.paz = nullptr;
            temp.paz_count = 0;

            for (int j = 0; j < N; j++)
            {
                pushback(temp.paz, temp.paz_count, (rand() % 10));
            }

            temp.var = vardas[rand() % 16];
            temp.pav = pavarde[rand() % 16];
            temp.egz = rand() % 10;

            grupe.push_back(temp);
        }
        break;

    case '4':
        return 0;

    default:
        cout << "Netinkamas pasirinkimas. Pasirinkite skaiciu nuo 1 iki 4" << endl;
        return 1;
    }

    cout << "\nAr norite taip pat skaiciuoti mediana?   y/n: ";
    cin >> choice;

    // Galutinio rezultato apskaiciavimas
    for (int i = 0; i < k; i++)
    {
        // Vidurkio apskaiciavimas
        grupe[i].galutinisVid = (0.4 * vidurkis(i)) + (0.6 * grupe[i].egz);

        // Medianos apskaiciavimas
        if (choice == 'y')
        {
            grupe[i].galutinisMed = (0.4 * mediana(i)) + (0.6 * grupe[i].egz);
        }
    }

    // Formatuotas Isvedimas
    cout << setw(15) << left << "Vardas" << setw(15) << "Pavarde" << setw(18) << "Galutinis (Vid.)";
    if (choice == 'y')
        cout << "/ " << setw(20) << "Galutinis (Med.)";
    cout << endl
         << string(75, '-') << endl;

    for (int i = 0; i < k; i++)
    {
        cout << setw(15) << left << grupe[i].var << setw(15) << grupe[i].pav << fixed << setprecision(3) << setw(20);
        cout << grupe[i].galutinisVid << " ";
        if (choice == 'y')
            cout << grupe[i].galutinisMed << " ";
        cout << endl;
    }

    return 0;
}