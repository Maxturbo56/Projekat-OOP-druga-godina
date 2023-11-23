#include "Igrac.cpp"

class Runda{
    vector <Player> igraci;
public:
    // ------- Smjestanje Igraca u rundu ... // 
    Player Dodaj_Igraca();
    void Smjesti_Igrace(Player one, Player two);
    Player get_Igrac(int index);
};
