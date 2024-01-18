// 1 of 4 util files in "ASTRAL NEXUS"

#include <iostream>
#include <string>
#include <memory>
class Keyword {

    std::string naziv;
    int vrijednost;

public:
    void Efekat_Keyworda(); // Funkcija koja dozvoljava obradu polja, oba igrača i bilo koje druge karte.

    // --------- SETTERI ---------- //

    void set_Naziv(std::string ime);
    void set_Vrijednost(int broj);

    // --------- GETTERI ---------- //

    std::string get_Naziv();
    int get_Vrijednost();

    // ------------------------------- //
};

enum tip_Karte { NAPAD = 1, ODBRANA, MAGE, BOARD, SPECIFIC };  //Enumeracija TIPa karte.

class Karta { //standardna klasa za predstavljanje svih karti u Astral Nexus - u

    // ----------- Standardne Vrijednosti --------------- //

    std::string naziv;
    int vrijednost, redni_Broj;
    tip_Karte tip;
    Keyword keyword;

public:

    // --------------  PISANO ZASEBNO ZA SVAKU KOMPOZICIJU KARTE  ------------ //
    void Efekat_Karte();

    Karta();

    ~Karta() = default;

    // Instanca ------------- ˘
    Karta Init_Karta(std::string ime_Karte, int vrijednost_Karte, int broj, int tip);

    // --------- SETTERI ---------- //

    void set_Naziv(std::string ime);
    void set_Vrijednost(int broj);
    void set_Tip(int tip);
    void set_Broj(int broj);

    // --------- GETTERI ---------- //

    std::string get_Naziv();
    int get_Vrijednost();
    tip_Karte get_Tip();
    int get_Broj();

    // ------------------------------- //
};
