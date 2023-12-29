//child
#pragma once
#pragma once
#include <iostream>
#include <string>
using namespace std;

//model untuk atlet 
struct infotypeAtlet
{
	string id, nama,asal;//id bersifta unik dimana setiap atlet memiliki id yang berbeda
	int umur,tanggalLahir,bulanLahir,tahunLahir;
	double berarBadan, tinggiBadan;
};

typedef struct elmAtlet* adrAtlet;
struct elmAtlet
{
	infotypeAtlet info;
	adrAtlet next;
};
struct listAtlet
{
	adrAtlet first;
};

void createListAtlet(listAtlet& L);
adrAtlet createAtlet(infotypeAtlet X);
adrAtlet findAtlet(listAtlet L, string IDatlet);
void insertAtlet(listAtlet &L, adrAtlet P);
void addAtlet(listAtlet& L);
void showAtlet(listAtlet L);
