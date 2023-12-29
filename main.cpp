// olah raga dan atlet perlombaan.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "olahraga.h"
int main()
{
    
    listAtlet atlet;
    listCabangOlahraga cabangOlahRaga;
    createListCabangOlahraga(cabangOlahRaga);
    createListAtlet(atlet);

    /*addCabangOlahraga(cabangOlahRaga);
    addCabangOlahraga(cabangOlahRaga);

    showCabangOlangraga(cabangOlahRaga);
    
    addAtlet(atlet);
    addAtlet(atlet);

    showAtlet(atlet);*/



    addAtletToOlaraga(cabangOlahRaga, atlet);
    addAtletToOlaraga(cabangOlahRaga, atlet);
    cout << endl << endl;

    PrintAtletOlahraga(cabangOlahRaga);
 
    
    
   
    
    return 0;
    
}

