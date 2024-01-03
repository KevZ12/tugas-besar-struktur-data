#include "olahraga.h"

int main() {
    listCabangOlahraga cabangOlahraga;
    createListCabangOlahraga(cabangOlahraga);
    listAtlet atlet;
    createListAtlet(atlet);

 
    int pilihan;
    
    pilihan = -1;
    while (pilihan != 0) {
        system("cls");
        selectMenu();
        cin >> pilihan;
        cin.ignore();
        switch (pilihan) {
        case 1: {
            addCabangOlahraga(cabangOlahraga);

            break;
        }

        case 2: {
            showCabangOlangraga(cabangOlahraga);
            getchar();
            break;
        }

        case 3: {
            addAtlet(atlet);
            break;
        }

        case 4: {

            showAtlet(atlet);
            getchar();
            break;
        }

        case 5: {
            addAtletToOlaraga(cabangOlahraga, atlet);
            break;
        }

        case 6: {
            checkParentConnection(cabangOlahraga);
            getchar();
            break;
        }

        case 7: {
            deleteAtletRelation(cabangOlahraga);
            break;
        }

        case 8: {
            PrintAtletOlahraga(cabangOlahraga);
            getchar();
            break;
        }

        case 9: {

            deleteChild(cabangOlahraga, atlet);
            getchar();
            
            break;
        }

        case 10: {

            deleteCabangOlahraga(cabangOlahraga);
            getchar();
            break;
        }

        
               
        }
        
    }

    return 0;
}