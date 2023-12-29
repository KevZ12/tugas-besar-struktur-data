//CHILD
#include "atlet.h"
void createListAtlet(listAtlet& L) {
	L.first = NULL;
}

adrAtlet createAtlet(infotypeAtlet X) {
	adrAtlet P = new elmAtlet;
	P->info = X;
	P->next = NULL;
	return P;
}


//mencari data child (5)
adrAtlet findAtlet(listAtlet L, string IDatlet) {
	adrAtlet P = L.first;
	while (P != NULL)
	{
		if (P->info.id==IDatlet)
		{
			return P;
		}
		P = P->next;
		
	}
	return NULL;
}





void insertAtlet(listAtlet &L, adrAtlet P) {
	adrAtlet X;
	if (L.first == NULL)
	{
		L.first = P;
	}
	else {
		X = L.first;
		while (X->next != NULL)
		{
			X = X->next;
		}
		X->next = P;
	}
}

void addAtlet(listAtlet& L) {
	infotypeAtlet X;
	adrAtlet P;
	


	
	cout << "Masukan ID Atlet" << endl;
	
	getline(cin, X.id);
	
	while (findAtlet(L,X.id)!=NULL)
	{	

		cout << "ID sudah terisi, silahkan masukan id lain" << endl;
		getline(cin, X.id);
		
	}
	
	cout << "Masukan nama Atlet" << endl;
	getline(cin, X.nama);
	
	cout << "Masukan asal daerah Atlet" << endl;
	getline(cin, X.asal);
	
	cout << "Masukan umur Atlet" << endl;
	cin>>X.umur;
	cout << "Masukan tanggal Lahir Atlet" << endl;
	cin >> X.tanggalLahir;
	cout << "Masukan bulan lahir Atlet" << endl;
	cin >> X.bulanLahir;
	cout << "Masukan tahun lahir Atlet" << endl;
	cin >> X.tahunLahir;
	cout << "Masukan berat badan Atlet" << endl;
	cin >> X.berarBadan;
	cout << "Masukan tinggi badan Atlet" << endl;
	cin >> X.tinggiBadan;
	cin.ignore();
	P = createAtlet(X);
	insertAtlet(L, P);
	


}


void showAtlet(listAtlet L) {
	adrAtlet P = L.first;
	while (P != NULL) {
		cout << "ID              :" << P->info.id << endl;
		cout << "Nama            :" << P->info.nama << endl;
		cout << "Asal            :" << P->info.asal << endl;
		cout << "Umur            :" << P->info.umur << endl;
		cout << "Tanggal Lahir   :" << P->info.tanggalLahir << endl;
		cout << "Bulan Lahir     :" << P->info.bulanLahir << endl;
		cout << "Tahun Lahir     :" << P->info.tahunLahir << endl;
		cout << "Berat Badan     :" << P->info.berarBadan << endl;
		cout << "Tinggi Badan    :" << P->info.tinggiBadan << endl;
		P = P->next;
	}
}