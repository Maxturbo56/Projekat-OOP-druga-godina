// 3 of 4 util files in "ASTRAL NEXUS"

#include "Karta.cpp"
#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <Windows.h>

class Player{

    // -------------------- Vektori Igrača (Karte u ruci, Karte u špilu, Karte koje su odigrane, Karte na terenu) -------------------- //
    std::vector <Karta> deck;
    std::vector <Karta> hand;
    std::vector <Karta> discard_Pile;
    std::vector <Karta> board;

    // -------------------- Trenutna Karta koja se igra ------------ //
    Karta current;
    int current_Card_Index = 0;
    int replace_Card_Index = 0;

    // ------- Vrijednosti Igrača ----------- //

    int health_Points; //Zdravlje igrača
    std::string ime;
    std::string ime_decka;

    int board_Value; // Vrijednost karata na boardu
    std::string CombinedTekst;
    std::string tempCombinedTekst;

public:

    bool played_Card = false; // Da li je igrač odigrao kartu ili ne
    void Build_Deck(std::string deck_Name); //
    void Shuffle_Deck();

    void Draw_Hand();
    void Draw();
    int getTerminalWidth();
    void printCenteredTextWithinWidth(const std::string& text, int maxWidth);
    int terminalWidth=getTerminalWidth();


    // Funckije kroz koje se vidi koje karte se nalaze u kojem vektoru igrača ---------------- //

    void See_Deck();
    void See_Hand();
    void See_Discard();
    void See_Board();

    void Play_Card(); // Odigraj kartu na board
    void Discard_Card(Karta karta); // Odbaci kartu u vektor 'discard'

    void Next_Card();
    void Previous_Card();

    void Update(); // Update funkcija koja se poziva svaki put kada dodje red da igra THIS igrac

    Player();

    ~Player() = default;

    void Calculate_Board_Value(); // Racuna vrijednost karata na boardu

    // --------- SETTERI ---------- //

    void set_Ime(std::string naziv);
    void set_HP(int broj);
    void set_Current(Karta karta);
    void set_Deck_Name(std::string rijec);

    // --------- GETTERI ---------- //

    std::string get_Ime();
    int get_HP();
    Karta get_Current();
    std::string get_Deck_Name();
    int get_Board_Value();

    // ------------------------------- //

};
