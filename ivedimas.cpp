#include "ivedimas.h"

void gen_paz(stud_struct &temp)
{
    for (int i = 0; i < N; i++)
    {
        temp.paz.push_back(rand() % 10);
    }
    temp.egz = rand() % 10;
}

void failo_ivedimas()
{
    stud_struct temp;
    int pazymys;

    string line, word, input_file;

    // Įvedimo failo atidarymas
    cout << "Iveskite failo pavadinima: " << endl;
    cin >> input_file;
    ifstream fd(input_file);

        if (!fd)
    {
        throw runtime_error("Nepavyko atidaryti ivedimo failo");
    }

    // ND kiekio radimas pagal antraštę
    getline(fd, line);
    istringstream antraste(line);

    int nd_count{};
    while (antraste >> word)
    {
        nd_count++;
    }

    // Galutinis ND numeris (atemus varda, pavarder ir egz. bala)
    nd_count -= 3;

    cout << "Ivedami duomenys..." << endl;

    // Duomenų įvedimas iš failo
    while (getline(fd, line))
    {
        istringstream iss(line);

        iss >> temp.var >> temp.pav;

        for (int i = 0; i < nd_count; i++)
        {
            iss >> pazymys;
            temp.paz.push_back(pazymys);
        }

        iss >> temp.egz;

        grupe.push_back(temp);
        temp.paz.clear();
    }

    fd.close();
}