#include "main_lib.h"
#include "apdorojimas.h"
#include "ivedimas.h"
#include "isvedimas.h"

int main()
{

    srand(time(NULL));
    char choice; // vartotojo pasirinkimas

    cout << "Ar norite skaiciuoti ivedimo laika?  y/n: ";
    cin >> choice;
    if (choice == 'y')
    {
        ar_skaiciuoti_laika = true;
    }
    else if (choice != 'y' && choice != 'n')
        throw runtime_error("Netinkamas pasirinkimas. Galimi pasirinkimai: 'y' arba 'n'");
    

    // Failo generavimo pasirinkimas
    cout << "Ar norite sugeneruoti studentų failą?  y/n: ";
    cin >> choice;
    if (choice == 'y')
    {
        try
        {
            failo_generavimas();
        }
        catch (runtime_error &e)
        {
            cout << "Klaida: " << e.what() << endl;
            return 1;
        }
    }
    else if (choice != 'y' && choice != 'n')
        throw runtime_error("Netinkamas pasirinkimas. Galimi pasirinkimai: 'y' arba 'n'");

    // Pagrindinis meniu
    cout << "Kaip norite ivesti pazymius/studentu vardus?:" << endl
         << "1 - ranka" << endl
         << "2 - generuoti TIK pazymius" << endl
         << "3 - generuoti studentu vardus IR pazymius" << endl
         << "4 - ivesti duomenis is failo" << endl
         << "5 - baigti darba" << endl;
    cin >> choice;

    stud_struct temp; // laikinas įvedimo masyvas

    try
    {
        switch (choice)
        {

        // ranka
        case '1':
        {
            while (true)
            {
                mok_ivedimas(temp);
                paz_ivedimas(temp);

                grupe.push_back(temp);

                // ar kartoti ivedimo/generavimo cikla?
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
                mok_ivedimas(temp);

                // pazymiu generavimas
                gen_paz(temp);

                grupe.push_back(temp);
                temp.paz.clear();

                // ar kartoti ivedimo/generavimo cikla?
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
                throw runtime_error("Failas tuscias arba netinkamo formato.");
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

    // medianos pasirinkimas
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
        grupe[i].galutinisVid = vidurkis_gal(i);

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

            rez_isvedimas(fr, choice_mediana, grupe);
            break;
        }

        // I ekrana
        case '2':
        {
            rez_isvedimas(cout, choice_mediana, grupe);
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

    return 0;
}