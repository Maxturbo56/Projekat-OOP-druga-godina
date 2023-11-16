// 2 of 4 util files in "ASTRAL NEXUS"

#include "Karta.h"

// ---- Setteri Karte ---------- //
void Karta::set_Naziv(string ime){this->naziv = ime;}
void Karta::set_Vrijednost(int broj){this->vrijednost = broj;}
void Karta::set_Tip(tip_Karte type){this->tip = type;}
void Karta::set_Broj(int broj){this->redni_Broj = broj;}

//Keyword 
void Keyword::set_Naziv(string ime){this->naziv = ime;}
void Keyword::set_Vrijednost(int broj){this->vrijednost = broj;}

// ---- Getteri Karte ---------- //
string Karta::get_Naziv(){return this->naziv;}
int Karta::get_Vrijednost(){return this->vrijednost;}
tip_Karte Karta::get_Tip(){return this->tip;}
int Karta::get_Broj(){return this->redni_Broj;}

//Keyword
string Keyword::get_Naziv(){return this->naziv;}
int Keyword::get_Vrijednost(){return this->vrijednost;}

// ----- Konstruktor ------- //
Karta::Karta()
{
    this->naziv = "undefined";
    this->vrijednost = 0;
    this->keyword.set_Naziv("undefined");
}

// Instanca ------------- ˘
Karta Karta::Init_Karta(string ime_Karte, int vrijednost_Karte, int broj, tip_Karte tip)
{   
    Karta obrada;
    obrada.set_Naziv(ime_Karte);
    obrada.set_Vrijednost(vrijednost_Karte);
    obrada.set_Broj(broj);
    obrada.set_Tip(tip);
    return obrada;
}


