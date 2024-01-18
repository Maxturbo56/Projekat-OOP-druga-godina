// 4 of 4 util files in "ASTRAL NEXUS"
// include THIS in "Astral_Nexus.cpp"

#include "Igrac.h"
#include "fstream"
#include "cstdlib"
#include "ctime"
#include "string"

// Funkcija koja trazi sirinu terminala
int Player::getTerminalWidth()
{

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;

}

// Funkcija koja ce printati linije u datoj setw sirini //
void Player::printCenteredTextWithinWidth(const std::string& text, int maxWidth)
{
    int padding = (maxWidth - text.length()) / 2;
    std::cout << std::setw(maxWidth) << std::right << std::setw(padding + text.length()) << text<<std::endl;
}

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
            //Varijable velicine karte za "crtanje"//
   const std::string UpDownGranica  ="--------------------";
   const std::string SidesGranica   ="I                  I";
   const std::string MalaSideGranica="                I";
   const std::string Razmak        ="   ";
   const int VisinaKarte=12;
   const std::string BoardKartaUpDownGranica="------------------------------";
   const std::string BoardKartaSidesGranica ="I                            I";
   const int VisinaBoardKarte=8;
   std::string combinedText;
   std::string tempCombinedTekst;
    Karta obrada;

    for(int k=0;k<VisinaKarte;k++)
    { combinedText.clear();
      if(k==0 || k==VisinaKarte-1)
      { combinedText.clear();
        for(int ku=0;ku<deck.size();ku++)
        {
         combinedText=combinedText+UpDownGranica+Razmak;
        }
      }
      else if(k==2)
      {
         tempCombinedTekst.clear();
        for(int ku=0;ku<deck.size();ku++)
        {
          obrada = this->deck[ku];
         int PrazanProstor=17-obrada.get_Naziv().size();
         if(PrazanProstor%2!=0)
             tempCombinedTekst=tempCombinedTekst+"I";
         else {
               PrazanProstor=PrazanProstor-1;
               tempCombinedTekst=tempCombinedTekst+"I ";
              }
         int PolaPrazanProstor=PrazanProstor/2;
         for(int klj=0;klj<=PolaPrazanProstor;klj++)
            {
             tempCombinedTekst=tempCombinedTekst+" ";
            }
         tempCombinedTekst=tempCombinedTekst+obrada.get_Naziv();
          for(int znj=0;znj<=PolaPrazanProstor;znj++)
            {
             tempCombinedTekst=tempCombinedTekst+" ";
            }
         tempCombinedTekst=tempCombinedTekst+"I"+Razmak;
        }
        combinedText=tempCombinedTekst;
      }
     else if(k==10)
      {
         tempCombinedTekst.clear();
        for(int ku=0;ku<deck.size();ku++)
        {
         obrada = this->deck[ku];
         tempCombinedTekst=tempCombinedTekst+"I "+(std::to_string(obrada.get_Vrijednost()))+MalaSideGranica+Razmak;
        }
        combinedText=tempCombinedTekst;
      }

      else
      {
       combinedText.clear();
       for(int ku=0;ku<deck.size();ku++)
        {
         combinedText=combinedText+SidesGranica+Razmak;
        }
      }

     printCenteredTextWithinWidth(combinedText, terminalWidth);
    }
}
//-------Implementacija funkcije Vidi Ruku--------//
void Player::See_Hand()
{
            //Varijable velicine karte za "crtanje"//
    const std::string UpDownGranica ="--------------------";
    const std::string SidesGranica  ="I                  I";
    const std::string MalaSideGranica="                I";
    const std::string Razmak        ="   ";
    const int VisinaKarte=12;
    std::string combinedText;
    std::string tempCombinedTekst;
    Karta obrada;

    for(int k=0;k<VisinaKarte;k++)
    { combinedText.clear();
      if(k==0 || k==VisinaKarte-1)
      { combinedText.clear();
        for(int ku=0;ku<hand.size();ku++)
        {
         combinedText=combinedText+UpDownGranica+Razmak;
        }
      }
      else if(k==2)
      {
         tempCombinedTekst.clear();
        for(int ku=0;ku<hand.size();ku++)
        {
          obrada = this->hand[ku];
         int PrazanProstor=17-obrada.get_Naziv().size();
         if(PrazanProstor%2!=0)
             tempCombinedTekst=tempCombinedTekst+"I";
         else {
               PrazanProstor=PrazanProstor-1;
               tempCombinedTekst=tempCombinedTekst+"I ";
              }
         int PolaPrazanProstor=PrazanProstor/2;
         for(int klj=0;klj<=PolaPrazanProstor;klj++)
            {
             tempCombinedTekst=tempCombinedTekst+" ";
            }
         tempCombinedTekst=tempCombinedTekst+obrada.get_Naziv();
          for(int znj=0;znj<=PolaPrazanProstor;znj++)
            {
             tempCombinedTekst=tempCombinedTekst+" ";
            }
         tempCombinedTekst=tempCombinedTekst+"I"+Razmak;
        }
        combinedText=tempCombinedTekst;
      }
     else if(k==10)
      {
         tempCombinedTekst.clear();
        for(int ku=0;ku<hand.size();ku++)
        {
         obrada = this->hand[ku];
         tempCombinedTekst=tempCombinedTekst+"I "+(std::to_string(obrada.get_Vrijednost()))+MalaSideGranica+Razmak;
        }
        combinedText=tempCombinedTekst;
      }

      else
      {
       combinedText.clear();
       for(int ku=0;ku<hand.size();ku++)
        {
         combinedText=combinedText+SidesGranica+Razmak;
        }
      }

     printCenteredTextWithinWidth(combinedText, terminalWidth);
    }
}

void Player::See_Discard()
{
            //Varijable velicine karte za "crtanje"//
    const std::string UpDownGranica ="--------------------";
    const std::string SidesGranica  ="I                  I";
    const std::string MalaSideGranica="                I";
    const std::string Razmak        ="   ";
    const int VisinaKarte=12;

    std::string combinedText;
    std::string tempCombinedTekst;
    Karta obrada;

    if(discard_Pile.size()!=0)
    {
     for(int k=0;k<VisinaKarte;k++)
     { combinedText.clear();
      if(k==0 || k==VisinaKarte-1)
      { combinedText.clear();
        for(int ku=0;ku<discard_Pile.size();ku++)
        {
         combinedText=combinedText+UpDownGranica+Razmak;
        }
      }
      else if(k==2)
      {
         tempCombinedTekst.clear();
        for(int ku=0;ku<discard_Pile.size();ku++)
        {
          obrada = this->discard_Pile[ku];
         int PrazanProstor=17-obrada.get_Naziv().size();
         if(PrazanProstor%2!=0)
             tempCombinedTekst=tempCombinedTekst+"I";
         else {
               PrazanProstor=PrazanProstor-1;
               tempCombinedTekst=tempCombinedTekst+"I ";
              }
         int PolaPrazanProstor=PrazanProstor/2;
         for(int klj=0;klj<=PolaPrazanProstor;klj++)
            {
             tempCombinedTekst=tempCombinedTekst+" ";
            }
         tempCombinedTekst=tempCombinedTekst+obrada.get_Naziv();
          for(int znj=0;znj<=PolaPrazanProstor;znj++)
            {
             tempCombinedTekst=tempCombinedTekst+" ";
            }
         tempCombinedTekst=tempCombinedTekst+"I"+Razmak;
        }
        combinedText=tempCombinedTekst;
      }
     else if(k==10)
      {
         tempCombinedTekst.clear();
        for(int ku=0;ku<discard_Pile.size();ku++)
        {
         obrada = this->discard_Pile[ku];
         tempCombinedTekst=tempCombinedTekst+"I "+(std::to_string(obrada.get_Vrijednost()))+MalaSideGranica+Razmak;
        }
        combinedText=tempCombinedTekst;
      }

      else
      {
       combinedText.clear();
       for(int ku=0;ku<discard_Pile.size();ku++)
        {
         combinedText=combinedText+SidesGranica+Razmak;
        }
      }

     printCenteredTextWithinWidth(combinedText, terminalWidth);
    }
   }
}

void Player::See_Board()
{
            //Varijable velicine karte za "crtanje"//
    const std::string UpDownGranica ="--------------------";
    const std::string SidesGranica  ="I                  I";
    const std::string MalaSideGranica="                I";
    const std::string Razmak        ="   ";
    const int VisinaKarte=12;

    std::string combinedText;
    std::string tempCombinedTekst;
    Karta obrada;

    if(board.size() != 0)
    {
        for(int k=0;k<VisinaKarte;k++)
    { combinedText.clear();
      if(k==0 || k==VisinaKarte-1)
      { combinedText.clear();
        for(int ku=0;ku<board.size();ku++)
        {
         combinedText=combinedText+UpDownGranica+Razmak;
        }
      }
      else if(k==2)
      {
         tempCombinedTekst.clear();
        for(int ku=0;ku<board.size();ku++)
        {
          obrada = board[ku];
         int PrazanProstor=17-obrada.get_Naziv().size();
         if(PrazanProstor%2!=0)
             tempCombinedTekst=tempCombinedTekst+"I";
         else {
               PrazanProstor=PrazanProstor-1;
               tempCombinedTekst=tempCombinedTekst+"I ";
              }
         int PolaPrazanProstor=PrazanProstor/2;
         for(int klj=0;klj<=PolaPrazanProstor;klj++)
            {
             tempCombinedTekst=tempCombinedTekst+" ";
            }
         tempCombinedTekst=tempCombinedTekst+obrada.get_Naziv();
          for(int znj=0;znj<=PolaPrazanProstor;znj++)
            {
             tempCombinedTekst=tempCombinedTekst+" ";
            }
         tempCombinedTekst=tempCombinedTekst+"I"+Razmak;
        }
        combinedText=tempCombinedTekst;
      }
     else if(k==10)
      {
         tempCombinedTekst.clear();
        for(int ku=0;ku<board.size();ku++)
        {
         obrada = this->deck[ku];
         tempCombinedTekst=tempCombinedTekst+"I "+(std::to_string(obrada.get_Vrijednost()))+MalaSideGranica+Razmak;
        }
        combinedText=tempCombinedTekst;
      }

      else
      {
       combinedText.clear();
       for(int ku=0;ku<board.size();ku++)
        {
         combinedText=combinedText+SidesGranica+Razmak;
        }
      }

     printCenteredTextWithinWidth(combinedText, terminalWidth);
    }
        //---------------------------------------------------------
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
            Sleep(50);
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

    for(int i = 0; i < 200; i++)
    {
        shuffle_one = rand()%deck.size();
        shuffle_two = rand()%deck.size();

        if(shuffle_one != shuffle_two)
        {
            obrada = this->deck[shuffle_one];
            this->deck[shuffle_one] = this->deck[shuffle_two];
            this->deck[shuffle_two] = obrada;

            std::cout<<"Swapped "<<shuffle_one<<" with "<<shuffle_two<<std::endl;
            Sleep(10);
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
    std::unique_ptr <Karta> temp = std::make_unique <Karta> ();
    *temp = this->deck.back();
    this->hand.push_back(*temp);
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
