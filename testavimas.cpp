#include "Bibliotekos/main_lib.h"
#include "Bibliotekos/apdorojimas.h"
#include "Bibliotekos/ivedimas.h"
#include "Bibliotekos/isvedimas.h"

int main()
{
    srand(69420);
    ar_skaiciuoti_laika = true;
    int time_total;

    bool choice;
    int dydis;
    int paz_sk = 10;
    string gen_file;

    cout << "Iveskite failo dydi: ";
    cin >> dydis;
    cout << endl;
    /*if (dydis)
    {
        gen_file = "Teksto_failai/studentai" + to_string(dydis) + ".txt";
        failo_generavimas(gen_file, paz_sk, dydis);
    }

    cout << "Nuskaityti ta pati faila? 1/0: ";
    cin >> choice;

    if (!choice)
    {
        cout << "Failo pavadinimas: " << endl;
        cin >> gen_file;
    }
    */

    gen_file = "Teksto_failai/studentai" + to_string(dydis) + ".txt";

    ifstream fd(gen_file);
    failo_ivedimas(fd);
    fd.close();

    char choice_mediana = true;

    for (int i = 0; i < grupe.size(); i++)
    {
        grupe[i].galutinisVid = vidurkis_gal(i);

        if (choice_mediana == 'y')
        {
            grupe[i].galutinisMed = mediana_gal(i);
        }
    }

    cout << "Studentai skirstomi pagal pazymius..." << endl;
    stud_isskirstymas(grupe);
}
