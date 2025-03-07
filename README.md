# OOP1

Šis projektas yra C++ programa, skirta studentų pažymių įvedimui ir galutinio rezultato skaičiavimui.

## Funkcionalumas

- **Duomenų įvedimo parinktys:**
  - **Rankiniu būdu:** Įvedami studentų vardai, pavardės, pažymiai ir egzamino rezultatai.
  - **Automatinis pažymių generavimas:** Sugeneruojami tik pažymiai studentams.
  - **Automatinis studentų vardų ir pažymių generavimas:** Sugeneruojami tiek studentų vardai/pavardės, tiek atsitiktiniai pažymiai.
  - **Duomenų įvedimas iš failo:** Programa leidžia įvesti duomenis iš pasirinktino failo, įskaitant studentų vardus, pavardes, pažymius ir egzamino rezultatus.

- **Galutinio rezultato apskaičiavimas:**
  - Apskaičiuojamas galutinis rezultatas pagal pažymių vidurkį.
  - Pasirenkama opcija apskaičiuoti ir galutinį rezultatą pagal medianą.

- **Studentų rezultatų rūšiavimas:**
  - Rūšiavimas pagal vardą.
  - Rūšiavimas pagal pavardę.
  - Rūšiavimas pagal galutinį rezultatą (vidurkis).
  - Rūšiavimas pagal galutinį rezultatą (mediana).
  - Galimybė palikti rezultatus nerūšiuotus.

- **Rezultatų išvedimas:**
  - Suformatuotas rezultatų išvedimas į konsolę.
  - Galimybė išvesti rezultatus į failą.

- **Papildoma naudotojo sąsaja:**
  - Interaktyvus meniu su pasirinkimais.
  - Galimybė tęsti įvedimą arba baigti programą pagal vartotojo pasirinkimą.

## VSCode projektinio failo `tasks.json` konfigūracija

Norėdami surinkti visus projektą sudarančius failus naujame PC naudojant Visual Studio Code, atlikite šiuos veiksmus:

1. **Sukurkite `.vscode` katalogą:**  
   Projekto šakninėje direktorijoje sukurkite katalogą pavadinimu `.vscode`, jei jis dar nėra sukurtas.

2. **Sukurkite arba atnaujinkite `tasks.json`:**  
   `.vscode` kataloge sukurkite (arba atnaujinkite) failą `tasks.json` su tokiu turiniu:

   ````jsonc
   // filepath: .vscode/tasks.json
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
                   "${workspaceFolder}\\paz_lib.cpp",
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

   **Pastaba:** Pakeiskite `C:\\Users\\<JusuVartotojoVardas>\\mingw64\\bin\\g++.exe` su atitinkama jūsų turima g++ vykdomąja failo vieta.

3. **Surinkite projektą:**  
   Atidarykite VSCode komandų paletę (`Ctrl+Shift+P`), įveskite `Tasks: Run Build Task` ir pasirinkite šią užduotį, kad būtų surinktas projektas.
