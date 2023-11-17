// 4 of 4 util files in "ASTRAL NEXUS"
// include THIS in "Astral_Nexus.cpp"

#include "Igrac.h"
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

// ---- Setteri Igrača ---------- //

void Player::set_Ime(string naziv){this->ime = naziv;}
void Player::set_HP(int broj){this->health_Points = broj;}
void Player::set_Current(Karta karta){this->current = karta;}
void Player::set_Deck_Name(string rijec){this->ime_decka = rijec;}	

// ---- Getteri Igrača ---------- //

string Player::get_Ime(){return this->ime;}
int Player::get_HP(){return this->health_Points;}
Karta Player::get_Current(){return this->current;}
string Player::get_Deck_Name(){return this->ime_decka;}

// ------ Implementacija (See_Deck, See_Hand, See_Discard) ------ //

void Player::See_Deck()
{
    Karta obrada;
    cout<<"Karte trenutno u spilu : "<<endl<<endl;

    for(int i = 0; i < deck.size(); i++)
    {
        obrada = this->deck[i];
        cout<<i + 1<<" "<<obrada.get_Naziv()<<endl;
    }
}

void Player::See_Hand()
{
    Karta obrada;
    cout<<"Karte trenutno u ruci : "<<endl<<endl;

    for(int i = 0; i < hand.size(); i++)
    {
        obrada = this->hand[i];
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

void Player::Build_Deck(string deck_Name)
{
    string name_of_Deck; 
    name_of_Deck = deck_Name + ".txt"; 
    cout<<"Deck name set to : "<<name_of_Deck<<endl;  	
    Karta obrada;

    // ------------------- CITANJE BAZE ------------------- //

    vector <string> linije_Baze;
    string linija;

    // ---------- KARTA ---------- //

    string name_of_Card;
    int value_of_Card, index_of_Card;

    ifstream file_IN;

    file_IN.open(name_of_Deck);

    while(getline(file_IN, linija))
    {
        linije_Baze.push_back(linija);
    }

    file_IN.close();

    // ------------------- KREIRANJE DECKA ------------------- //

    for(int i = 0; i < linije_Baze.size(); i++)
    {
        if(linije_Baze[i] == "#")
        {
            name_of_Card = linije_Baze[i + 2];
            value_of_Card = stoi(linije_Baze[i + 3]);
            index_of_Card = stoi(linije_Baze[i + 1]);
            // ------------ INICIJALIZACIJA KARTE -------------- //
            obrada.set_Naziv(name_of_Card);
            cout<<endl<<"Ime obrade : "<<obrada.get_Naziv()<<endl;
            obrada.set_Broj(index_of_Card);
            cout<<endl<<"Index obrade : "<<obrada.get_Broj()<<endl;
            obrada.set_Vrijednost(value_of_Card);
            cout<<endl<<"Vrijednost obrade : "<<obrada.get_Vrijednost()<<endl;
            deck.push_back(obrada);
            cout<<"Obrada dodana u spil!"<<endl;
        }
        else 
        {
            continue;
        }
    }
}

void Player::Shuffle_Deck()
{
    cout<<"Shuffling deck..."<<endl;

    int shuffle_one;
    int shuffle_two;
    Karta obrada;

    for(int i = 0; i < 100; i++)
    {   
        shuffle_one = rand()%deck.size();
        shuffle_two = rand()%deck.size();

        if(shuffle_one != shuffle_two)
        {
            obrada = this->deck[shuffle_one];
            this->deck[shuffle_one] = this->deck[shuffle_two];
            this->deck[shuffle_two] = obrada;

            cout<<"Swapped "<<shuffle_one<<" with "<<shuffle_two<<endl;
        }
        else
        {
            continue;
        }
    }

    cout<<"Deck shuffled!"<<endl;
}

void Player::Draw_Hand()
{  

    for(int i = 0; i < 7; i++)
    {
        Karta temp;
        temp = this->deck.back();
        this->hand.push_back(temp);
        this->deck.pop_back();        
    }
}
