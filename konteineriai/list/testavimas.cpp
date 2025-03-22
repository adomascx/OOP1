#include "bibliotekos/main_lib.h"
#include "bibliotekos/apdorojimas.h"
#include "bibliotekos/ivedimas.h"
#include "bibliotekos/isvedimas.h"

int main(int argc, char *argv[])
{
    srand(69420);
    ar_skaiciuoti_laika = true;

    int dydis;
    string gen_file;

    if (argc == 1)
    {
    cout << "Iveskite failo dydi: ";
    cin >> dydis;
    cout << endl;
    }
    else
    {
        dydis = atoi(argv[1]);
    }
    /*if (dydis)
    {
        int paz_sk = 10;
        gen_file = "teksto_failai/studentai" + to_string(dydis) + ".txt";
        failo_generavimas(gen_file, paz_sk, dydis);
    }

    cout << "Nuskaityti ta pati faila? 1/0: ";
        bool choice;
    cin >> choice;

    if (!choice)
    {
        cout << "Failo pavadinimas: " << endl;
        cin >> gen_file;
    }
    */

    gen_file = "teksto_failai/studentai" + to_string(dydis) + ".txt";

    ifstream fd(gen_file);
    failo_ivedimas(fd);
    fd.close();

    char choice_mediana = 'y';

    for (auto &studentas : grupe)
    {
        studentas.galutinisVid = vidurkis_gal(studentas);
        if (choice_mediana == 'y')
            studentas.galutinisMed = mediana_gal(studentas);
    }

    cout << "Studentai skirstomi pagal pazymius..." << endl;
    stud_isskirstymas(grupe);
}
