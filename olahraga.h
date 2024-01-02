//parent
//parent miliki child yang dihubungkan oleh suatu relation
#include "atlet.h"

//model untuk relation
//relation digunakan untuk menghubungkan child dan parent
typedef struct elmRelation* adrRelation;
struct elmRelation
{
	adrAtlet nextAtlet;
	adrRelation next;
};

//model untuk cabang olah raga yang merupakan parent dari daftar atlet
struct infotypeCabangOlahRaga
{
	string id, namaCabangOlahraga, deskripsi;
	int jumlahPeserta;
};

typedef struct elmCabangOlahraga* adrCabangOlahraga;
struct elmCabangOlahraga
{
	infotypeCabangOlahRaga info;
	adrCabangOlahraga next;
	adrCabangOlahraga prev;
	adrRelation atlet;

};

struct listCabangOlahraga
{
	adrCabangOlahraga first;
	adrCabangOlahraga last;
};

void createListCabangOlahraga(listCabangOlahraga& L);
adrCabangOlahraga createCabangOlahraga(infotypeCabangOlahRaga X);
void insertCabangOlahraga(listCabangOlahraga& L, adrCabangOlahraga P);
void addCabangOlahraga(listCabangOlahraga& L);



void showCabangOlangraga(listCabangOlahraga L);
void deleteFirstCabangOlahraga(listCabangOlahraga& L, adrCabangOlahraga P);
void deleteLastCabangOlahraga(listCabangOlahraga& L, adrCabangOlahraga P);
void deleteAfterCabangOlahraga(listCabangOlahraga& L,adrCabangOlahraga prec ,adrCabangOlahraga P);
void deleteCabangOlahraga(listCabangOlahraga& L);
adrCabangOlahraga findCabangOlahraga(listCabangOlahraga L, string IDcabangOlahraga);



void addAtletToOlaraga(listCabangOlahraga& L1, listAtlet& l2);

void PrintAtletOlahraga(listCabangOlahraga L1);


adrRelation findAtletinCabangOlahraga(adrCabangOlahraga L, string IDatlet);
void checkParentConnection(listCabangOlahraga L);



int hitungJumlahChild(listCabangOlahraga L,string id);



void deleteFirstRelation(adrCabangOlahraga& L, adrRelation P);
void deleteLastRelation(adrCabangOlahraga& L, adrRelation P);
void deleteAfterRelation(adrCabangOlahraga& L, adrRelation PREC, adrRelation P);
void deleteAtletRelation(listCabangOlahraga& L);

void deleteFirstChild(listAtlet& L, adrAtlet P);
void deletLastChild(listAtlet& L, adrAtlet P);
void deleteAfterChild(listAtlet& L, adrAtlet PREC, adrAtlet P);
void deleteChild(listCabangOlahraga& L1, listAtlet& L2);