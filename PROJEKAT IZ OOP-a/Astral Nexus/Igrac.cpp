// 4 of 4 util files in "ASTRAL NEXUS"
// include THIS in "Astral_Nexus.cpp"

#include "Igrac.h"

// ---- Setteri Igrača ---------- //

void Player::set_Ime(string naziv){this->ime = naziv;}
void Player::set_HP(int broj){this->health_Points = broj;}
void Player::set_Current(Karta karta){this->current = karta;}

// ---- Getteri Igrača ---------- //

string Player::get_Ime(){return this->ime;}
int Player::get_HP(){return this->health_Points;}
Karta Player::get_Current(){return this->current;}

// ------ Implementacija (See_Deck, See_Hand, See_Discard) ------ //

void Player::See_Deck()
{
    Karta obrada;
    cout<<"Karte trenutno u spilu : "<<endl<<endl;

    for(int i = 0; i < deck.size(); i++)
    {
        obrada = deck[i];
        cout<<i + 1<<" "<<obrada.get_Naziv()<<endl;
    }
}

void Player::See_Hand()
{
    Karta obrada;
    cout<<"Karte trenutno u ruci : "<<endl<<endl;

    for(int i = 0; i < hand.size(); i++)
    {
        obrada = hand[i];
        cout<<i + 1<<" "<<obrada.get_Naziv()<<endl;
    }
}

void Player::See_Discard()
{
    Karta obrada;
    cout<<"Karte trenutno u discard - u : "<<endl<<endl;

    for(int i = 0; i < discard_Pile.size(); i++)
    {
        obrada = discard_Pile[i];
        cout<<i + 1<<" "<<obrada.get_Naziv()<<endl;
    }
}

void Player::See_Board()
{
    Karta obrada;
    cout<<"Karte trenutno u discard - u : "<<endl<<endl;

    for(int i = 0; i < board.size(); i++)
    {
        obrada = board[i];
        cout<<i + 1<<" "<<obrada.get_Naziv()<<endl;
    }
}

// -------------- Konstruktor --------- //

Player :: Player()
{
    this->ime = "undefined";
    this->health_Points = 20;
}