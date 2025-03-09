# OOP1

Šis projektas yra C++ programa, skirta studentų pažymių įvedimui ir galutinio rezultato skaičiavimui. Nuo paskutinio README atnaujinimo įdiegta papildoma funkcionalumo refinavimo versija – interaktyvus meniu, papildomi duomenų apdorojimo testai bei patobulintas laiko matavimas.

## Funkcionalumas

- **Duomenų įvedimo parinktys:**
  - **Rankiniu būdu:** Įvedami studentų vardai, pavardės, pažymiai ir egzamino rezultatai.
  - **Automatinis pažymių generavimas:** Sugeneruojami tik pažymiai studentams.
  - **Automatinis studentų vardų bijų ir pažymių generavimas:** Sugeneruojami tiek studentų vardai/pavardės, tiek atsitiktiniai pažymiai.
  - **Duomenų įvedimas iš failo:** Programa leidžia įvesti duomenis iš pasirinktino failo.

- **Galutinio rezultato apskaičiavimas:**
  - Skaičiuojamas galutinis rezultatas pagal pažymių vidurkį.
  - Pasirenkama opcija apskaičiuoti galutinį rezultatą pagal medianą.

- **Studentų rezultatų rūšiavimas:**
  - Rūšiavimas pagal vardą, pavardę.
  - Rūšiavimas pagal galutinį rezultatą – tiek vidurkis, tiek mediana.
  - Galimybė palikti rezultatus nerūšiuotus.

- **Rezultatų išvedimas:**
  - Suformatuotas rezultatų išvedimas į konsolę.
  - Galimybė išvesti rezultatus į failą.

- **Papildoma naudotojo sąsaja:**
  - Interaktyvus meniu su aiškaus pasirinkimų sąrašu.
  - Galimybė tęsti įvedimą arba baigti programą pagal vartotojo pasirinkimą.

- **Papildomi pakeitimai nuo paskutinio atnaujinimo:**
  - Patobulintas laiko matavimas operacijoms (timer funkcijos).
  - Naujas spartos analizės modulis, skirtas išmatuoti veikimo laiką atskiriems programos žingsniams.
  - Daugiau išplėstų klaidų pranešimų ir patikrinimų interaktyviame meniu.

## Kompiliavimas ir paleidimas

Projekto surinkimui rekomenduojama naudoti Visual Studio Code su paruoštu `tasks.json` konfigūracija.

### VSCode projektinio failo `tasks.json` konfigūracija

````jsonc
// filepath: tasks.json
{
    "version": "2.0.0",
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: Surinkti visus šaltinio failus",
            "command": "C:\\Users\\<JusuVartotojoVardas>\\mingw64\\bin\\g++.exe",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "${workspaceFolder}\\OOP1.cpp",
                "${workspaceFolder}\\apdorojimas.cpp",
                "${workspaceFolder}\\ivedimas.cpp",
                "${workspaceFolder}\\isvedimas.cpp",
                "${workspaceFolder}\\main_lib.cpp",
                "-o",
                "${workspaceFolder}\\OOP1.exe"
            ],
            "options": {
                "cwd": "${workspaceFolder}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "Surinkia visus projekto failus"
        }
    ]
}
````

Norėdami surinkti projektą, atidarykite VSCode komandų paletę (`Ctrl+Shift+P`), įveskite `Tasks: Run Build Task` ir pasirinkite aukščiau nurodytą užduotį.

## Programos spartos analizė
| Testas                               | 10000 įrašų | 100000 įrašų | 1000000 įrašų | 10000000 įrašų |
| ------------------------------------ | ----------- | ------------ | ------------- | -------------- |
| Failų generavimas                    | 0.03s       | 0.3s         | 3s            | 29.88s         |
| Duomenų nuskaitymas / Failo įvedimas | 0.01s       | 0.13s        | 1.24s         | 12.78s         |
| Studentų rūšiavimas                  | <0.01s      | 0.1s         | 1.38s         | 16.7s          |
| Išvestis į failą                     | 0.03s       | 0.28s        | 2.71s         | 27s            |
| **Bendras programos veikimo laikas** | 0.08s       | 0.82s        | 8.34s         | 86.37s         |

## Programos veikimo pavyzdžiai

Programos eiga apima duomenų įvedimą, rezultato apskaičiavimą bei spartos analizės etapų išvedimą:

- **Pagrindinis meniu:**  
![image](https://github.com/user-attachments/assets/59b5b9f6-e997-47e4-8fdf-32f85498f852)

- **Sugeneruotas studentų failas:**  
![image](https://github.com/user-attachments/assets/62391314-923f-4ff8-94c8-9cb42682917f)

- **Programos spartos analizė:**
  
  ![image](https://github.com/user-attachments/assets/f359d320-045c-41b3-83af-74726a414b2d)


