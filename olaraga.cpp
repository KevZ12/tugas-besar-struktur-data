//PARENT
#include "olahraga.h"
void createListCabangOlahraga(listCabangOlahraga& L) {
	L.first = NULL;
	L.last = NULL;
}

adrCabangOlahraga createCabangOlahraga(infotypeCabangOlahRaga X) {
	adrCabangOlahraga P = new elmCabangOlahraga;
	P->info = X;
	P->next = NULL;
	P->atlet = NULL;
	P->prev = NULL;
	return P;
}




void insertCabangOlahraga(listCabangOlahraga& L, adrCabangOlahraga P) {
	if (L.first == NULL && L.last == NULL)
	{
		L.first = P;
		L.last = P;
	}
	else
	{
		L.last->next = P;
		P->prev = L.last;
		L.last = P;


	}
}

//1.insert Last Parent (5 POINT)
void addCabangOlahraga(listCabangOlahraga& L) {
	infotypeCabangOlahRaga X;
	adrCabangOlahraga P;
	cout << "masukan id cabang olahraga" << endl;
	getline(cin, X.id);
	while (findCabangOlahraga(L,X.id)!= NULL)
	{
		cout << "ID sudah terisi, silahkan masukan id lain" << endl;
		getline(cin, X.id);
	}

	
	cout << "masukan nama cabang olahraga" << endl;
	getline(cin, X.namaCabangOlahraga);
	
	cout << "masukan deskripsi cabang olahraga" << endl;
	getline(cin, X.deskripsi);
	X.jumlahPeserta = 0;
	P = createCabangOlahraga(X);
	insertCabangOlahraga(L, P);
	
}


//2.menampilkan seluruh data parent (5 POINT)
void showCabangOlangraga(listCabangOlahraga L) {
	if (L.first == NULL && L.last == NULL)
	{
		cout << "list cabang olahraga masih kosong" << endl;
	}
	else
	{
		adrCabangOlahraga P = L.first;
		while (P != NULL)
		{
			cout << "Nama Cabang Olahraga: " << P->info.namaCabangOlahraga << endl;
			cout << "ID Cabang Olahraga: " << P->info.id << endl;
			cout << "Deskripsi Cabang Olahraga: " << P->info.deskripsi << endl;
			cout << "Jumlah Peserta Cabang Olahraga: " << P->info.jumlahPeserta << endl;
			P = P->next;
			cout << endl;
		}
	}
	
}


void deleteFirstCabangOlahraga(listCabangOlahraga& L, adrCabangOlahraga P){
	P = L.first;
	L.first = L.first->next;
	P->next = NULL;
	L.first->prev = NULL;
}
void deleteLastCabangOlahraga(listCabangOlahraga& L, adrCabangOlahraga P){
	P = L.last;
	L.last = L.last->prev;
	L.last->next = NULL;
	P->prev = NULL;
}
void deleteAfterCabangOlahraga(listCabangOlahraga& L, adrCabangOlahraga prec, adrCabangOlahraga P){
	P = prec->next;
	prec->next = P->next;
	P->next->prev = prec;
	P->prev = NULL;
	P->next = NULL;
}

//3. menghapus data parent beserta Relasinya (15 point)
void deleteCabangOlahraga(listCabangOlahraga& L) {
	char option;
	string ID;
	adrCabangOlahraga P;
	
	//MEMBERIKAN OPSI UNTUK MENAMPILKAN DATA PARENT
	cout << "Apakah anda ingin menampilkan seluruh data cabang olah raga?y/n" << endl;
		cin >> option;
	if (option == 'y')
	{
		showCabangOlangraga(L);
	}
	//MEMINTA INPUTAN ID
	cout << "masukan id cabang olahraga yang ingin dihapus" << endl;
	cin >> ID;
	P = findCabangOlahraga(L, ID);
	if (L.first == NULL)
	{
		cout << "maaf data cabang olahraga masih kosong" << endl;
	} else if (P == NULL)//KONDISI CABANG OLAHRAGA KOSONG ATAU TIDAK DITEMUKAN
	{
		cout << "maaf id yang anda masukan tidak ditemukan" << endl;
	}
	else {
		if (L.first == L.last) {//KONDISI HANYA ADA 1 CABANG OLAHRAGA
			L.first = NULL;
			L.last = NULL;
		}
		else if (P == L.first)//kondisi p ditemukan di awal
		{
			deleteFirstCabangOlahraga(L, P);
		}
		else if(P == L.last)//kondisi p ditemuian di akhir
		{
			deleteLastCabangOlahraga(L, P);
		}
		else//kondisi p ditemukan ditengah
		{
			deleteAfterCabangOlahraga(L, P->prev, P);
		}
	}



	


}


//4. mecari data parent (5 point)
adrCabangOlahraga findCabangOlahraga( listCabangOlahraga L,string IDcabangOlahraga) {
	adrCabangOlahraga P = L.first;

	while (P!= NULL)
	{

		if (P->info.id == IDcabangOlahraga)
		{
			return P;
		}
		P = P->next;
	}
	return NULL;
}



//7. MENGHUBUNGKAN DATA PARENT DAN CHILD
void addAtletToOlaraga(listCabangOlahraga& L1, listAtlet &l2) {
	string option;
	string IDcabangOlahraga, IDatlet;
	adrAtlet atlet;
	adrCabangOlahraga cabangOlahraga;

	cout << "apakah anda ingin menampilkan list cabang olahraga?y/n" << endl;
	cin >> option;
	cin.ignore();
	if (option == "y")
	{
		showCabangOlangraga(L1);
	}
	cout << "Masukan ID cabang olahraga yang anda ingin tambahkan" << endl;
	cin >> IDcabangOlahraga;

	while (findCabangOlahraga(L1,IDcabangOlahraga)==NULL)
	{
		cout << "ID cabang olah raga yang anda masukan tidak ditemukan" << endl;
		cout << "Apakah anda ingin menambahkan cabang olahraga lainnya?y/n" << endl;
		cin >> option;
		
		if (option == "y")
		{	
			cin.ignore();
			addCabangOlahraga(L1);
		}
		cout << "apakah anda ingin menampilkan list cabang olahraga?y/n" << endl;
		cin >> option;
		cin.ignore();
		if (option == "y")
		{
			showCabangOlangraga(L1);
		}
		cout << "Masukan ID cabang olahraga yang anda ingin tambahkan" << endl;
		cin >> IDcabangOlahraga;
	}

	cabangOlahraga = findCabangOlahraga(L1, IDcabangOlahraga);


	cout << "apakah anda ingin menampilkan list atlet?y/n" << endl;
	cin >> option;
	if (option == "y")
	{	
		cin.ignore();
		showAtlet(l2);
	}
	cout << "masukan ID atlet yang ingin anda tambahkan" << endl;
	cin>>IDatlet;

	while (findAtlet(l2,IDatlet) == NULL || findAtletinCabangOlahraga(cabangOlahraga,IDatlet)!= NULL)
	{
		if (findAtlet(l2, IDatlet) == NULL)
		{
			cout << "ID atlet yang anda masukan tidak ditemukan" << endl;
			cout << "Apakah anda ingin menambahkan atlet lainnya?y/n" << endl;
			cin >> option;
			cin.ignore();
			if (option == "y")
			{
				addAtlet(l2);
			}
		}
		else if(findAtletinCabangOlahraga(cabangOlahraga, IDatlet) != NULL)
		{
			cout << "ID atlet yang anda masukan sudah ada dalam list cabang olahraga yang anda masukan" << endl;
		}
		
		
		cout << "apakah anda ingin menampilkan list atlet?y/n" << endl;
	cin >> option;
	if (option == "y")
	{	
		cin.ignore();
		showAtlet(l2);
	}
		cout << "Masukan ID atlet yang anda ingin tambahkan" << endl;
		cin >> IDatlet;
	}

	atlet = findAtlet(l2, IDatlet);


	adrRelation newRelation = new elmRelation;
	newRelation->nextAtlet = atlet;
	newRelation->next = NULL;


	if (L1.first->atlet == NULL)
	{
		L1.first->atlet = newRelation;
	}
	else {
		adrRelation lastRelation = L1.first->atlet;
		while (lastRelation->next!=NULL)
		{
			lastRelation = lastRelation->next;
		}
		lastRelation->next = newRelation;
	}


}

void PrintAtletOlahraga(listCabangOlahraga L1) {
	adrCabangOlahraga P = L1.first;
	cout << "Berikut merupakan list cabang olahraga beserta para atletnya:" << endl;
	while (P != NULL) {
		cout << "Nama Cabang Olahraga   : " << P->info.namaCabangOlahraga << endl;
		cout << "Jumlah Peserta         : " << P->info.jumlahPeserta << endl;

		adrRelation Q = P->atlet;
		while (Q != NULL) {
			adrAtlet R = Q->nextAtlet;
			cout << "   - Nama          : " << R->info.nama << endl;
			cout << "     Umur          : " << R->info.umur << endl;
			cout << "     Tanggal Lahir : " << R->info.tanggalLahir << R->info.bulanLahir << R->info.tahunLahir << endl;

			Q = Q->next;
		}
		P = P->next;
	}
}


adrAtlet findAtletinCabangOlahraga(adrCabangOlahraga L,string IDatlet){
	adrRelation relasi = L->atlet;
	
	while (relasi!=NULL)
	{
		if (relasi->nextAtlet->info.id == IDatlet)
		{
			return relasi->nextAtlet;
		}
		relasi = relasi->next;
	}
	return NULL;
}