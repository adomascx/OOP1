#include "main_lib.h"

bool ar_skaiciuoti_laika = false;                  // testavimo rezimas
time_point<high_resolution_clock> pradzios_laikas; // laiko matavimo funkcijos pradzios laikas

string vardas[] = {"Adomas", "Julius", "Mantas", "Lukas", "Dominykas", "Tomas", "Jonas", "Paulius", "Dovydas", "Karolis", "Rokas", "Simonas", "Martynas", "Arnas", "Justas", "Vilius"};
string pavarde[] = {"Kazlauskas", "Petrauskas", "Jankauskas", "Stankevicius", "Butkus", "Paulauskas", "Urbonas", "Vasiliauskas", "Lukosevicius", "Simkus", "Brazaitis", "Kavaliauskas", "Mikalauskas", "Navickas", "Rimkus", "Zukauskas"};

// laiko skaiciavimo pradzios funkcija
void timer_prad()
{
    if (ar_skaiciuoti_laika)
    {
        pradzios_laikas = high_resolution_clock::now();
    }
}

void konteinerio_pasirinkimas(char choice)
{
    if (choice == 'l' || choice == 'L')
    {
        list<stud_struct> grupe;
    }
    else if (choice == 'd' || choice == 'D')
    {
        deque<stud_struct> grupe;
    }
    else if (choice == 'v' || choice == 'V')
    {
        vector<stud_struct> grupe; // pagrindinis studentu konteineris
    }
    else
        throw runtime_error("Netinkamas pasirinkimas. Bandykite vel");
}

// laiko skaiciavimo pabaigos funkcija. argumentas 'operacija' yra vykdomos operacijos pavadinimas
void timer_pab(string operacija)
{
    if (ar_skaiciuoti_laika)
    {
        auto pabaigos_laikas = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(pabaigos_laikas - pradzios_laikas);
        cout << "[" << operacija << " uztruko: " << duration.count() << " ms]" << endl;
    }
}