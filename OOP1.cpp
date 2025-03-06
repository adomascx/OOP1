#include "main_lib.h"
#include "apdorojimas.h"
#include "ivedimas.h"

int main()
{
    srand(time(NULL));

    // Ivedimas
    cout << "Kaip norite ivesti pazymius/studentu vardus?:" << endl
         << "1 - ranka" << endl
         << "2 - generuoti TIK pazymius" << endl
         << "3 - generuoti studentu vardus IR pazymius" << endl
         << "4 - ivesti duomenis is failo" << endl
         << "5 - baigti darba" << endl;
    char choice; // vartotojo pasirinkimas
    cin >> choice;

    // TODO: palikti *tik* funkcijose
    stud_struct temp; // laikinas įvedimo masyvas
    int pazymys;      // įvestas temp pažymys

    try
    {
        switch (choice)
        {

        // ranka
        case '1':
        {
            while (true)
            {

                cout << "Iveskite mokinio varda: ";
                cin >> temp.var;
                if (!cin)
                    throw runtime_error("Netinkamai ivestas vardas. Bandykite vel");

                cout << "Iveskite mokinio pavarde: ";
                cin >> temp.pav;
                if (!cin)
                    throw runtime_error("Netinkamai ivesta pavarde. Bandykite vel");

                while (true)
                {
                    pazymys = 0;
                    cout << "Iveskite mokinio pazymi (0, jei daugiau pazymiu nera): ";
                    cin >> pazymys;
                    if (!cin || pazymys > 10)
                        throw runtime_error("Netinkamas pazymys. Pasirinkite skaiciu nuo 1 iki 10");

                    if (pazymys)
                        temp.paz.push_back(pazymys);
                    else
                        break;
                }

                // Patikrinti, ar naudotojas ivede pazymiu
                // Jei ne, baigti programa
                if (temp.paz.empty())
                {
                    throw runtime_error("Nera ivestu pazymiu. Prasome ivesti bent viena pazymi.");
                }

                cout << "Iveskite egzamino rezultata: ";
                cin >> temp.egz;
                if (!cin || temp.egz > 10)
                    throw runtime_error("Netinkamas egzamino balas. Pasirinkite skaiciu nuo 1 iki 10");
                grupe.push_back(temp);

                cout << "Ar norite toliau ivesti mokinius?  y/n: ";
                cin >> choice;
                if (choice == 'n')
                    break;
                else if (!cin || choice != 'y')
                    throw runtime_error("Netinkamas pasirinkimas. Galimi pasirinkimai: 'y' arba 'n'");
            }
            break;
        }

        // generuoti TIK pazymius
        case '2':
        {
            while (true)
            {
                // vardo/pavardes ivedimas
                cout << "Iveskite mokinio varda: ";
                cin >> temp.var;
                if (!cin)
                    throw runtime_error("Netinkamai ivestas vardas. Bandykite vel");

                cout << "Iveskite mokinio pavarde: ";
                cin >> temp.pav;
                if (!cin)
                    throw runtime_error("Netinkamai ivesta pavarde. Bandykite vel");

                // pazymiu generavimas
                gen_paz(temp);

                grupe.push_back(temp);
                temp.paz.clear();

                // testi boolean
                cout << "Ar norite toliau ivesti mokinius?  y/n: ";
                cin >> choice;
                if (choice == 'n')
                    break;
                else if (choice != 'y' && choice != 'n')
                    throw runtime_error("Netinkamas pasirinkimas. Galimi pasirinkimai: 'y' arba 'n'");
            }
            break;
        }

        // generuoti studentu vardus IR pazymius
        case '3':
        {
            cout << "Kiek mokiniu norite sugeneruoti?: ";
            int i;
            cin >> i;
            if (!cin || i == 0)
                throw runtime_error("Netinkamas pasirinkimas. Pasirinkite skaiciu nuo 1 iki 2147483647");
            for (; i > 0; i--)
            {
                // vardu/pavardziu generavimas
                temp.var = vardas[rand() % 16];
                temp.pav = pavarde[rand() % 16];

                // pazymiu generavimas
                gen_paz(temp);

                grupe.push_back(temp);
                temp.paz.clear();
            }
            break;
        }

        // ivesti duomenis is failo
        case '4':
        {
            failo_ivedimas();

            if (grupe.empty())
            {
                throw runtime_error("Failas tuscias arba netinkamo formato!");
            }
            else
                cout << "Failas ivestas sekmingai.";
            break;
        }

        // baigti darba
        case '5':
            return 0;

        default:
            throw runtime_error("Netinkamas pasirinkimas. Pasirinkite skaiciu nuo 1 iki 5");
        }
    }

    catch (runtime_error &e)
    {
        cout << "Klaida: " << e.what() << endl;
        return 1;
    }

    char choice_mediana;
    try
    {
        cout << "\nAr norite taip pat skaiciuoti mediana?   y/n: ";
        cin >> choice_mediana;
        if (choice_mediana != 'y' && choice_mediana != 'n')
        {
            throw runtime_error("Netinkamas pasirinkimas. Galimi pasirinkimai: 'y' arba 'n'");
        }
    }

    catch (runtime_error &e)
    {
        cout << "Klaida: " << e.what() << endl;
        return 1;
    }

    cout << "Skaiciuojami balai..." << endl;

    // Galutinio rezultato apskaiciavimas
    for (int i = 0; i < grupe.size(); i++)
    {
        // Vidurkio apskaiciavimas
        grupe[i].galutinisVid = vidurkis_gal(i);

        // Medianos apskaiciavimas
        if (choice_mediana == 'y')
        {
            grupe[i].galutinisMed = mediana_gal(i);
        }
    }

    cout << endl
         << "Kaip norite rusiuoti studentu rezultatus?: " << endl
         << "1 - Pagal varda" << endl
         << "2 - Pagal pavarde" << endl
         << "3 - Pagal galutini rezultata (vidurkis)" << endl
         << "4 - Pagal galutini rezultata (mediana)" << endl
         << "5 - Nerusiuoti rezultatu" << endl;
    cin >> choice;

    // Duomenų rūšiavimo algoritmai
    try
    {
        switch (choice)
        {
        case '1':
            sort(grupe.begin(), grupe.end(), [](const auto &a, const auto &b)
                 { return a.var < b.var; });
            break;

        case '2':
            sort(grupe.begin(), grupe.end(), [](const auto &a, const auto &b)
                 { return a.pav < b.pav; });
            break;

        case '3':
            sort(grupe.begin(), grupe.end(), [](const auto &a, const auto &b)
                 { return a.galutinisVid > b.galutinisVid; });
            break;

        case '4':
            sort(grupe.begin(), grupe.end(), [](const auto &a, const auto &b)
                 { return a.galutinisMed > b.galutinisMed; });
            break;

        case '5':
            break;

        default:
            throw runtime_error("Netinkamas pasirinkimas. Pasirinkite skaiciu nuo 1 iki 5");
        }
    }
    catch (runtime_error &e)
    {
        cout << "Klaida: " << e.what() << endl;
        return 1;
    }

    cout << endl
         << "Ar norite duomenis isvesti i faila, ar i ekrana?: " << endl
         << "1 - I faila" << endl
         << "2 - I ekrana" << endl;
    cin >> choice;

    try
    {
        switch (choice)
        {
        // I faila
        case '1':
        {
            ofstream fr(output_file);
            if (!fr)
                throw runtime_error("Nepavyko atidaryti isvedimo failo");

            // Formatuotas Išvedimas
            fr << setw(15) << left << "Vardas" << setw(15) << "Pavarde" << setw(18) << "Galutinis (Vid.)";
            if (choice_mediana == 'y')
                fr << "/ " << setw(20) << "Galutinis (Med.)";
            fr << endl
               << string(75, '-') << endl;

            for (auto &i : grupe)
            {
                fr << setw(15) << left << i.var << setw(15) << i.pav << fixed << setprecision(3) << setw(20);
                fr << i.galutinisVid << " ";
                if (choice_mediana == 'y')
                    fr << i.galutinisMed << " ";
                fr << endl;
            }
            break;
        }

        // I ekrana
        case '2':
        {
            // Formatuotas Išvedimas
            cout << setw(15) << left << "Vardas" << setw(15) << "Pavarde" << setw(18) << "Galutinis (Vid.)";
            if (choice_mediana == 'y')
                cout << "/ " << setw(20) << "Galutinis (Med.)";
            cout << endl
                 << string(75, '-') << endl;

            for (auto &i : grupe)
            {
                cout << setw(15) << left << i.var << setw(15) << i.pav << fixed << setprecision(3) << setw(20);
                cout << i.galutinisVid << " ";
                if (choice_mediana == 'y')
                    cout << i.galutinisMed << " ";
                cout << endl;
            }
            break;
        }
        default:
            throw runtime_error("Netinkamas pasirinkimas. Pasirinkite 1 arba 2");
        }
    }
    catch (runtime_error &e)
    {
        cout << "Klaida: " << e.what() << endl;
        return 1;
    }

    // "Press any key", jei programa paleidžiama ne IDE aplinkoje
    cout << endl
         << "Spauskite bet koki klavisa...";
    getch();

    return 0;
}