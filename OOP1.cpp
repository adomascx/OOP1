#include "paz_lib.h"

int main() 
{
cout << "Iveskite namu darbu (nd) skaiciu: ";
cin >> n;

vector<stud> grupe;
for(int i = 0; i < k; i++)
    {
    stud laik;
    cout << "Iveskite mokinio varda: ";
    cin >> laik.var;
    cout << "Iveskite mokinio pavarde: ";
    cin >> laik.pav;
    for(auto& nd : laik.paz)
        {
        cout << "Iveskite mokinio pazymi: ";
        cin >> nd;
        }
    
    grupe.push_back(laik);
    }

    return 0;
}