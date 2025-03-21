#pragma once
#include "main_lib.h"

void rez_isvedimas(ostream &out, char choice_mediana, const deque<stud_struct> &grupe);
void failo_generavimas(string gen_file, int paz_sk, int dydis);
void stud_isskirstymas(const deque<stud_struct> &grupe);