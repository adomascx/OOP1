#include "paz_lib.h"

int main()
{
    cout << "Iveskite namu darbu pazymiu skaiciu: ";
    cin >> n;

    vector<stud_struct> grupe;

    // Ivedimas
    for (int i = 0; i < k; i++)
    {
        stud_struct temp;
        cout << "Iveskite mokinio varda: ";
        cin >> temp.var;
        cout << "Iveskite mokinio pavarde: ";
        cin >> temp.pav;
        for (int i = 0; i < n; i++)
        {
            int pazymys;
            cout << "Iveskite mokinio pazymi " << i + 1 << ": ";
            cin >> pazymys;
            temp.paz.push_back(pazymys);
        }
        cout << "Iveskite egzamino rezultata: ";
        cin >> temp.egz;
        grupe.push_back(temp);
    }

    

    cout << setw(15) << left << "Vardas" << setw(15) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << endl;
    cout << "-------------------------------------------------------" << endl;
    for (stud_struct &nd : grupe)
    {
        cout << setw(15) << left << nd.var << setw(15) << nd.pav << setw(20) << endl;
    }

    return 0;
}