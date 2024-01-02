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
	bool keluar = false;

	cout << "apakah anda ingin menampilkan list cabang olahraga?y/n" << endl;
	cin >> option;
	cin.ignore();
	if (option == "y")
	{
		showCabangOlangraga(L1);
	}
	cout << "Masukan ID cabang olahraga yang anda ingin tambahkan" << endl;
	cin >> IDcabangOlahraga;

	while (findCabangOlahraga(L1,IDcabangOlahraga)==NULL && keluar == false)
	{
		cout << "ID cabang olah raga yang anda masukan tidak ditemukan" << endl;
		cout << "Apakah anda ingin menambahkan cabang olahraga lainnya?y/n" << endl;
		cin >> option;
		
		if (option == "y")
		{	
			cin.ignore();
			addCabangOlahraga(L1);
		}
		else
		{
			return;
		}
		cout << "apakah anda ingin menampilkan list cabang olahraga?y/n" << endl;// y untuk iya dan n untuk kembali kemenu utama
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
			else
			{
				return;
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


	if (cabangOlahraga->atlet == NULL)
	{
		cabangOlahraga->atlet = newRelation;
	}
	else {
		adrRelation lastRelation = cabangOlahraga->atlet;
		while (lastRelation->next!=NULL)
		{
			lastRelation = lastRelation->next;
		}
		lastRelation->next = newRelation;
	}

	cabangOlahraga->info.jumlahPeserta = hitungJumlahChild(L1, cabangOlahraga->info.id);

}

void PrintAtletOlahraga(listCabangOlahraga L1) {
	adrCabangOlahraga P = L1.first;
	if (P == NULL)
	{
		cout << "List cabang Olahrag masih kosong" << endl;
	}
	else
	{
		cout << "Berikut merupakan list cabang olahraga beserta para atletnya:" << endl;
		while (P != NULL) {
			cout << "Nama Cabang Olahraga   : " << P->info.namaCabangOlahraga << endl;
			cout << "deskripsi              : " << P->info.deskripsi << endl;
			cout << "Jumlah Peserta         : " << P->info.jumlahPeserta << endl;


			adrRelation Q = P->atlet;
			if (Q == NULL)
			{
				cout << "-" << endl;
			}
			while (Q != NULL) {
				adrAtlet R = Q->nextAtlet;
				cout << "     Nama          : " << R->info.nama << endl;
				cout << "     Umur          : " << R->info.umur << endl;
				cout << "     Tanggal Lahir : " << R->info.tanggalLahir << "-" << R->info.bulanLahir << "-" << R->info.tahunLahir << endl;
				cout << "     Berat Badan   :" << R->info.berarBadan << endl;
				cout << "     Tinggi Badan  :" << R->info.tinggiBadan << endl;

				Q = Q->next;
			}
			P = P->next;
		}
	}
	
}


adrRelation findAtletinCabangOlahraga(adrCabangOlahraga L,string IDatlet){
	adrRelation relasi = L->atlet;
	
	while (relasi!=NULL)
	{
		if (relasi->nextAtlet->info.id == IDatlet)
		{
			return relasi;
		}
		relasi = relasi->next;
	}
	return NULL;
	
}


void checkParentConnection(listCabangOlahraga L) {
	string option;
	

	cout << "apakah anda ingin melihat daftar cabang Olahraga?y/n" << endl;
	cin >> option;
	if (option == "y")
	{
		showCabangOlangraga(L);
	}

	cout<< "masukan id cabang olahraga yang ingin anda check" << endl;
	cin >> option;
	adrCabangOlahraga P = findCabangOlahraga(L, option);
	if (P == NULL)
	{
		cout << "id yang anda masukan tidak ditemukan" << endl;
	}
	else {
		adrRelation Q = P->atlet;
		if (Q== NULL)
		{
			cout << "data child pada cabang Olahraga " << P->info.namaCabangOlahraga << " masih kosong" << endl;
		}
		else {
			
			cout << "berikut daftar list atlet dari cabang olah raga " << P->info.namaCabangOlahraga<<endl;
			while (Q != NULL) {
				adrAtlet R = Q->nextAtlet;
				cout << "     Nama          : " << R->info.nama << endl;
				cout << "     Umur          : " << R->info.umur << endl;
				cout << "     Tanggal Lahir : " << R->info.tanggalLahir << "-" << R->info.bulanLahir << "-" << R->info.tahunLahir << endl;
				cout << "     Berat Badan   :" << R->info.berarBadan << endl;
				cout << "     Tinggi Badan  :" << R->info.tinggiBadan << endl;

				Q = Q->next;
				cout << endl;
			}
		}
		
	}
	getchar();
	
}



int hitungJumlahChild(listCabangOlahraga L, string id) {
	int i = 0;
	adrCabangOlahraga cabangOlahraga = findCabangOlahraga(L, id);
	if (cabangOlahraga == NULL)
	{
		cout << "maaf id yang anda masukan tidak ditemukan" << endl;
		return NULL;
	}
	else {
		adrRelation atlet = cabangOlahraga->atlet;
		while (atlet != NULL)
		{
			i++;
			atlet = atlet->next;
		}
		return i;
	}
}


void deleteFirstRelation(adrCabangOlahraga& L, adrRelation P){
	P = L->atlet;
	L->atlet = L->atlet->next;
	P->next = NULL;

}
void deleteLastRelation(adrCabangOlahraga& L, adrRelation P){
	P = L->atlet;
	while (P->next->next != NULL)
	{
		P = P->next;
	}
	P->next = NULL;
}
void deleteAfterRelation(adrCabangOlahraga& L, adrRelation PREC,adrRelation P){
	P = PREC->next;
	PREC->next = P->next;
	P->next = NULL;
}
void deleteAtletRelation(listCabangOlahraga& L){
	char option;
	string ID;
	adrRelation R;
	adrCabangOlahraga P;
	adrRelation s = L.first->atlet;
	cout << "apakah anda ingin menampilkan list cabang olahraga yang ingin dihapus?y/n" << endl;
	cin >> option;
	if (option =='y')
	{
		showCabangOlangraga(L);
	}
	cout << "Masukan ID cabang olahraga yang ingin anda hapus" << endl;
	cin >> ID;
	P = findCabangOlahraga(L, ID);

	if (P == NULL)
	{
		cout << "ID yang anda masukan tidak ditemukan" << endl;
		
	}
	else
	{
		cout << "apakah anda ingin menampilkan relasi dari cabang olahraga?" << endl;
		cin >> option;
		if (option == 'y')
		{
			adrRelation Q = L.first->atlet;
			while (Q != NULL) {
				adrAtlet R = Q->nextAtlet;
				cout << "     Nama          : " << R->info.nama << endl;
				cout << "     Umur          : " << R->info.umur << endl;
				cout << "     Tanggal Lahir : " << R->info.tanggalLahir << "-" << R->info.bulanLahir << "-" << R->info.tahunLahir << endl;
				cout << "     Berat Badan   :" << R->info.berarBadan << endl;
				cout << "     Tinggi Badan  :" << R->info.tinggiBadan << endl;

				Q = Q->next;
			}
			

		}
		cout << "Masukan ID Relasi cabang olahraga yang ingin anda hapus" << endl;
		cin >> ID;
		R = findAtletinCabangOlahraga(P, ID);
		

		adrRelation PREC = L.first->atlet;
		while (PREC != NULL && PREC->next != R)
		{
			PREC = PREC->next;
		}
	
		

		if (R == NULL)// KONDISI TIDAK DITEMUKAN
		{
			cout << "Relasi dari atlet tidak ditemukan" << endl;
			
		}
		else if (R->next == NULL && hitungJumlahChild(L, P->info.id) == 1) {// KONDISI HANY ADA 1 RELASI
			P->atlet = NULL;
			
		}
		else if (R->next != NULL && hitungJumlahChild(L, P->info.id) > 1 && PREC == NULL)// KONDISI HANYA ADA 1 RELASI DAN LEBIH DARI 1 DATA KONDISI
		{
			
			deleteFirstRelation(P, R);
		}
		else  if (R->next == NULL && hitungJumlahChild(L, P->info.id) > 1) // KONDISI DATA TERAKHIR DAN LEBIH DARI SATU RELASI
		{
			
			deleteLastRelation(P, R);
		}
		else
		{
			
			deleteAfterRelation(P, PREC, R);
		}

		P->info.jumlahPeserta = hitungJumlahChild(L, P->info.id);
	}


	
}




void deleteFirstChild(listAtlet& L, adrAtlet P) {
	P = L.first;
	L.first = L.first->next;
	P->next = NULL;

}


void deletLastChild(listAtlet& L, adrAtlet P) {
	P = L.first;
	while (P->next->next!= NULL)
	{
		P = P->next;
	}
	P->next = NULL;
}


void deleteAfterChild(listAtlet& L, adrAtlet PREC, adrAtlet P) {
	P = PREC->next;
	PREC->next = P->next;
	P->next = NULL;
}


void deleteChild(listCabangOlahraga& L1, listAtlet &L2) {
	 string id,option;
	 adrCabangOlahraga cabangOlahraga;
	 cabangOlahraga = L1.first;
	 adrRelation listAtletinParent;
	
	
	cout << "Apakah anda ingin melihat daftar atlet terlebih dahulu" << endl;
	cin >> option;
	if (option =="y")
	{
		showAtlet(L2);
	}
	cout << "masukan id atlet yang ingin dihapus yang ingin dihapus" << endl;
	cin >> id;
	adrAtlet atlet = findAtlet(L2, id);
	if (atlet == NULL)
	{
		cout << "id yang anda masukan tidak ditemukan" << endl;
	}
	else
	{
		
		while (cabangOlahraga != NULL)
		{
			cout << "test" << endl;

			listAtletinParent = findAtletinCabangOlahraga(cabangOlahraga, id);
			if (listAtletinParent != NULL)
			{	
				cout << "test2" << endl;
				adrRelation R = findAtletinCabangOlahraga(cabangOlahraga, id);
				cout << R->nextAtlet->info.nama;
				adrRelation PREC = cabangOlahraga->atlet;
				while (PREC != NULL && PREC->next != R)
				{
					PREC = PREC->next;
				}



				if (R == NULL)// KONDISI TIDAK DITEMUKAN
				{
					cout << "Relasi dari atlet tidak ditemukan" << endl;

				}
				else if (R->next == NULL && hitungJumlahChild(L1,cabangOlahraga->info.id) == 1) {// KONDISI HANY ADA 1 RELASI
					cabangOlahraga->atlet = NULL;

				}
				else if (R->next != NULL && hitungJumlahChild(L1, cabangOlahraga->info.id) > 1 && PREC == NULL)// KONDISI HANYA ADA 1 RELASI DAN LEBIH DARI 1 DATA KONDISI
				{

					deleteFirstRelation(cabangOlahraga,R);
				}
				else  if (R->next == NULL && hitungJumlahChild(L1, cabangOlahraga->info.id) > 1) // KONDISI DATA TERAKHIR DAN LEBIH DARI SATU RELASI
				{

					deleteLastRelation(cabangOlahraga, R);
				}
				else
				{

					deleteAfterRelation(cabangOlahraga, PREC, R);
				}

				cabangOlahraga->info.jumlahPeserta = hitungJumlahChild(L1, cabangOlahraga->info.id);
			}//asdsadsa
			cabangOlahraga = cabangOlahraga->next;
		}

		

		if (atlet == L2.first && L2.first->next == NULL)
		{
			
			L2.first = NULL;
		}
		else if (atlet == L2.first && L2.first->next != NULL)
		{
			
			deleteFirstChild(L2, atlet);
		}
		else if (atlet != L2.first && atlet->next == NULL)
		{
			
			deletLastChild(L2, atlet);
		}
		else
		{
			
			adrAtlet PrecAtlet = L2.first;
			while (PrecAtlet->next != atlet)
			{
				PrecAtlet = PrecAtlet->next;
			}
			deleteAfterChild(L2, PrecAtlet, atlet);
		}
	}

	getchar();

}




