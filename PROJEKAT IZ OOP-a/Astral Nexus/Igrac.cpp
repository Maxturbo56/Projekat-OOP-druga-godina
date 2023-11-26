// 4 of 4 util files in "ASTRAL NEXUS"
// include THIS in "Astral_Nexus.cpp"

#include "Igrac.h"
#include "fstream"
#include "cstdlib"
#include "ctime"
#include "string"
#include "windows.h"

// ---- Setteri Igrača ---------- //

void Player::set_Ime(std::string naziv){this->ime = naziv;}
void Player::set_HP(int broj){this->health_Points = broj;}
void Player::set_Current(Karta karta){this->current = karta;}
void Player::set_Deck_Name(std::string rijec){this->ime_decka = rijec;}	

// ---- Getteri Igrača ---------- //

std::string Player::get_Ime(){return this->ime;}
int Player::get_HP(){return this->health_Points;}
Karta Player::get_Current(){return this->current;}
std::string Player::get_Deck_Name(){return this->ime_decka;}

// ------ Implementacija (See_Deck, See_Hand, See_Discard) ------ //

void Player::See_Deck()
{
    Karta obrada;
    std::cout<<"Karte trenutno u spilu : "<<std::endl<<std::endl;

    for(int i = 0; i < deck.size(); i++)
    {
        obrada = this->deck[i];
        std::cout<<i + 1<<" "<<obrada.get_Naziv()<<" ( "<<obrada.get_Vrijednost()<<" )"<<std::endl;
    }
}

void Player::See_Hand()
{
    Karta obrada;
    std::cout<<"Karte trenutno u ruci : "<<std::endl<<std::endl;

    for(int i = 0; i < hand.size(); i++)
    {
        obrada = this->hand[i];
        std::cout<<i + 1<<" "<<obrada.get_Naziv()<<" ( "<<obrada.get_Vrijednost()<<" )\t";
    }
}

void Player::See_Discard()
{
    Karta obrada;
    std::cout<<"Karte trenutno u discard - u : "<<std::endl<<std::endl;

    for(int i = 0; i < discard_Pile.size(); i++)
    {
        obrada = discard_Pile[i];
        std::cout<<i + 1<<" "<<obrada.get_Naziv()<<" ( "<<obrada.get_Vrijednost()<<" )\t";
    }
}

void Player::See_Board()
{
    Karta obrada;
    std::cout<<"Karte trenutno u BOARD - u : "<<std::endl<<std::endl;

    if(board.size() != 0)
    {
        for(int i = 0; i < board.size(); i++)
        {
            obrada = board[i];
            std::cout<<i + 1<<" "<<obrada.get_Naziv()<<" ( "<<obrada.get_Vrijednost()<<" )\t";
        }
    }
}

// -------------- KONSTRUKTOR --------- //

Player :: Player()
{
    this->ime = "undefined";
    this->health_Points = 20;
}

// --------- IZGRADANJA SPILA -------- //

void Player::Build_Deck(std::string deck_Name)
{
    std::string name_of_Deck; 
    name_of_Deck = deck_Name + ".txt"; 
    std::cout<<"Deck name set to : "<<name_of_Deck<<std::endl;  	
    Karta obrada;

    // ------------------- CITANJE BAZE ------------------- //

    std::vector <std::string> linije_Baze;
    std::string linija;

    // ---------- KARTA ---------- //

    std::string name_of_Card;
    int value_of_Card, index_of_Card;

    std::ifstream file_IN;

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
            value_of_Card = std::stoi(linije_Baze[i + 3]);
            index_of_Card = std::stoi(linije_Baze[i + 1]);
            // ------------ INICIJALIZACIJA KARTE -------------- //
            obrada.set_Naziv(name_of_Card);
            std::cout<<std::endl<<"Ime obrade : "<<obrada.get_Naziv()<<std::endl;
            obrada.set_Broj(index_of_Card);
            std::cout<<std::endl<<"Index obrade : "<<obrada.get_Broj()<<std::endl;
            obrada.set_Vrijednost(value_of_Card);
            std::cout<<std::endl<<"Vrijednost obrade : "<<obrada.get_Vrijednost()<<std::endl;
            deck.push_back(obrada);
            std::cout<<"Obrada dodana u spil!"<<std::endl;
        }
        else 
        {
            continue;
        }
    }
}

int Player::get_Board_Value()
{
    return this->board_Value;
}

void Player::Calculate_Board_Value()
{
    int temp = 0;
    for(int i = 0; i < board.size(); i++)
    {
        temp += board[i].get_Vrijednost();
    }
    this->board_Value = temp;
}

void Player::Shuffle_Deck()
{
    std::cout<<"Shuffling deck..."<<std::endl;

    int shuffle_one;
    int shuffle_two;
    Karta obrada;

    for(int i = 0; i < 400; i++)
    {   
        shuffle_one = rand()%deck.size();
        shuffle_two = rand()%deck.size();

        if(shuffle_one != shuffle_two)
        {
            obrada = this->deck[shuffle_one];
            this->deck[shuffle_one] = this->deck[shuffle_two];
            this->deck[shuffle_two] = obrada;

            std::cout<<"Swapped "<<shuffle_one<<" with "<<shuffle_two<<std::endl;
        }
        else
        {
            continue;
        }
    }

    std::cout<<"Deck shuffled!"<<std::endl;
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

void Player::Draw()
{
    Karta temp;
    temp = this->deck.back();
    this->hand.push_back(temp);
    this->deck.pop_back();   
}

void Player::Discard_Card(Karta karta)
{
    this->discard_Pile.push_back(karta);
}

void Player::Play_Card()
{
    if(board.size() < 4)
    {
        board.push_back(hand[current_Card_Index]);
        hand.erase(hand.begin() + current_Card_Index);
        played_Card = true;
    }
    else
    {
        std::cout<<"Trenutno je vas board pun!!!\nMolimo izaberite kartu na boardu (index) koju zelite zamijeniti sa vasom trenutnom kartom : "<<std::endl;
        See_Board(); // this might break the game
        std::cin>>this->replace_Card_Index;
        Discard_Card(board[replace_Card_Index]);
        board[replace_Card_Index] = hand[current_Card_Index];
        hand.erase(hand.begin() + current_Card_Index);
        std::cout<<"Karta uspjesno zamijenjena!"<<std::endl;
        Sleep(1000);
        played_Card = true;
    }
}

void Player::Next_Card()
{
    if(current_Card_Index < hand.size() - 1)
    {
        current_Card_Index++;
    }
    else
    {
        current_Card_Index = 0;
    }
}

void Player::Previous_Card()
{
    if(current_Card_Index > 0)
    {
        current_Card_Index--;
    }
    else
    {
        current_Card_Index = hand.size() - 1;
    }
}

void Player::Update()
{
    current = hand[current_Card_Index];
    if(GetKeyState('H') & 0x8000)
	{
        this->Next_Card();
	}
    else if(GetKeyState('J') & 0x8000)
    {
        this->Previous_Card();
    }
    else if(GetKeyState('K') & 0x8000)
    {
        this->Play_Card();
    }

}