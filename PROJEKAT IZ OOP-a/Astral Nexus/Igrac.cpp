// 4 of 4 util files in "ASTRAL NEXUS"
// include THIS in "Astral_Nexus.cpp"

#include "Igrac.h"
#include <stdlib.h>
#include <ctime>


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

void Player::Build_Deck()
{
    // PLACEHOLDER

    Karta obrada;
    obrada = obrada.Init_Karta("Karta 1", 1, 1, tip_Karte::MAGE);
    deck.push_back(obrada);
    obrada = obrada.Init_Karta("Karta 2", 2, 2, tip_Karte::MAGE);
    deck.push_back(obrada);
    obrada = obrada.Init_Karta("Karta 3", 3, 3, tip_Karte::MAGE);
    deck.push_back(obrada);
    obrada = obrada.Init_Karta("Karta 4", 4, 4, tip_Karte::MAGE);
    deck.push_back(obrada); 
    obrada = obrada.Init_Karta("Karta 5", 5, 5, tip_Karte::MAGE);
    deck.push_back(obrada);
    obrada = obrada.Init_Karta("Karta 6", 6, 6, tip_Karte::MAGE);
    deck.push_back(obrada);
    obrada = obrada.Init_Karta("Karta 7", 7, 7, tip_Karte::MAGE);
    deck.push_back(obrada);
    obrada = obrada.Init_Karta("Karta 8", 8, 8, tip_Karte::MAGE);
    deck.push_back(obrada);
    obrada = obrada.Init_Karta("Karta 9", 9, 9, tip_Karte::MAGE);
    deck.push_back(obrada);

    this->Draw_Hand();
}

/*void Player::Shuffle_Deck()
{
    srand(time(NULL));
    srand(time(NULL));
    int shuffler_Randomiser;
    shuffler_Randomiser = rand()&deck.size()+1;
    shuffle(deck.begin(), deck.end(), shuffler_Randomiser);
}*/

void Player::Draw_Hand()
{  

    for(int i = 0; i < 7; i++)
    {
        Karta temp;
        temp = deck.back();
        hand.push_back(temp);
        deck.pop_back();        
    }
    
    // Hand output ------------------------------
    for(int i = 0; i < hand.size(); i++)
    {
        Karta obrada;
        obrada = hand[i];
        cout<<obrada.get_Naziv()<<" ";
    }
}
