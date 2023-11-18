// 3 of 4 util files in "ASTRAL NEXUS"

#include "Karta.cpp"
#include <vector>
#include <fstream>

class Player{

    // -------------------- Vektori Igrača (Karte u ruci, Karte u špilu, Karte koje su odigrane, Karte na terenu) -------------------- //
    vector <Karta> deck;
    vector <Karta> hand;
    vector <Karta> discard_Pile; 
    vector <Karta> board; 

    // -------------------- Trenutna Karta koja se igra ------------ //
    Karta current;
    int current_Card_Index = 0;

    // ------- Vrijednosti Igrača ----------- //

    int health_Points; //Zdravlje igrača
    string ime;
    string ime_decka;

public:

    void Build_Deck(string deck_Name); //
    void Shuffle_Deck();

    void Draw_Hand();
    void Draw();


    // Funckije kroz koje se vidi koje karte se nalaze u kojem vektoru igrača ---------------- //

    void See_Deck();
    void See_Hand();
    void See_Discard();
    void See_Board();

    void Play_Card(); // Odigraj kartu na board
    void Discard_Card(); // Odbaci kartu u vektor 'discard'

    void Next_Card();
    void Previous_Card();

    void Update(); // Update funkcija koja se poziva svaki put kada dodje red da igra THIS igrac

    Player();

    ~Player() = default;

    // --------- SETTERI ---------- //

    void set_Ime(string naziv);
    void set_HP(int broj);
    void set_Current(Karta karta);
    void set_Deck_Name(string rijec);

    // --------- GETTERI ---------- //

    string get_Ime();
    int get_HP();
    Karta get_Current();
    string get_Deck_Name();

    // ------------------------------- //
};
