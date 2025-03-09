#include "main_lib.h"

vector<stud_struct> grupe;

bool ar_skaiciuoti_laika = false;
time_point<high_resolution_clock> start_time;

string vardas[] = {"Adomas", "Julius", "Mantas", "Lukas", "Dominykas", "Tomas", "Jonas", "Paulius", "Dovydas", "Karolis", "Rokas", "Simonas", "Martynas", "Arnas", "Justas", "Vilius"};
string pavarde[] = {"Kazlauskas", "Petrauskas", "Jankauskas", "Stankevicius", "Butkus", "Paulauskas", "Urbonas", "Vasiliauskas", "Lukosevicius", "Simkus", "Brazaitis", "Kavaliauskas", "Mikalauskas", "Navickas", "Rimkus", "Zukauskas"};

void timer_prad()
{
    if (ar_skaiciuoti_laika)
    {
        start_time = high_resolution_clock::now();
    }
}

void timer_pab(string operacija)
{
    if (ar_skaiciuoti_laika)
    {
        auto end_time = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end_time - start_time);
        cout << "[" << operacija <<" užtruko: " << duration.count() << " ms]" << endl;
    }
}