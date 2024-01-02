#include "olahraga.h"

int main() {
    listCabangOlahraga cabangOlahraga;
    createListCabangOlahraga(cabangOlahraga);
    listAtlet atlet;
    createListAtlet(atlet);

    /*
    cout << "===========MENU============" << endl;
	cout << "1. Insert Parent" << endl;
	cout << "2. Print All Parent" << endl;
	cout << "3. Insert Child" << endl;
	cout << "4. Print All Child" << endl;
	cout << "5. Connect Parent and Child" << endl;
	cout << "6. Check Parent Connection" << endl;
	cout << "7. Disconnect" << endl;
	cout << "8. Print All" << endl;
	cout << "9. Print child of a Parent" << endl;
	cout << "10. Delete child" << endl;
	cout << "11. Delete Parent" << endl;
	cout << "Pilihan menu: " << endl;
	cout << "===========================" << endl;
    */
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
            break;
        }

        
               
        }
        
    }

    return 0;
}