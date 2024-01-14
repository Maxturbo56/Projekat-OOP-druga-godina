#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <vector>
#include <string>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/ioctl.h>
#include <unistd.h>
#endif

// Funkcija koja trazi sirinu terminala
int getTerminalWidth() {
#ifdef _WIN32
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
#else
    struct winsize size;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
    return size.ws_col;
#endif
}

// Function to print centered text within setw
void printCenteredTextWithinWidth(const std::string& text, int maxWidth) {
    int padding = (maxWidth - text.length()) / 2;
    std::cout << std::setw(maxWidth) << std::right << std::setw(padding + text.length()) << text<<std::endl;
}

int main() {
#ifdef _WIN32
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_MAXIMIZE);
#endif

    int terminalWidth = getTerminalWidth();

    //Globalne varijable velicine karte
    std::string UpDownGranica ="--------------------";
    std::string SidesGranica  ="I                  I";
    std::string MalaSideGranica="            I";
    std::string Razmak        ="   ";
    int VisinaKarte=12;
    std::string BoardKartaUpDownGranica="------------------------------";
    std::string BoardKartaSidesGranica ="I                            I";
    int VisinaBoardKarte=8;
//______________________________________________________________________________________________________________________________________________________________
    //Ovo ovdje je za ispit karti protivnika, vidimo samo zadnje strane karti
    int OpponentKarteRuka =10;
    int brKrt= OpponentKarteRuka;
    std::string combinedText;
    for(int k=0;k<VisinaKarte;k++)
    { combinedText.clear();
      if(k==0 || k==VisinaKarte-1)
      { combinedText.clear();
        for(int ki=0;ki<brKrt;ki++)
        {
         combinedText=combinedText+UpDownGranica+Razmak;
        }
      }
      else if (k==5)
      { combinedText.clear();
        for(int ki=0;ki<brKrt;ki++)
        {
         combinedText=combinedText+"I  Zadnja strana   I"+Razmak;
        }
      }
      else
      {
       combinedText.clear();
       for(int ki=0;ki<brKrt;ki++)
        {
         combinedText=combinedText+SidesGranica+Razmak;
        }
      }

     printCenteredTextWithinWidth(combinedText, terminalWidth);
    }
//_____________________________________________________________________________________________________________________________________________________________
//Ovo je za ispis karti protivnika koje su na stolu

    std::vector<std::string> ImenaKarti;
    std::string prva="Kemo";
    std::string druga="Nedim";
    std::string treca="Amina";
    std::string Sesta="Ormar";
    ImenaKarti.push_back(prva);
    ImenaKarti.push_back(druga);
    ImenaKarti.push_back(treca);
    ImenaKarti.push_back(Sesta);
    brKrt= ImenaKarti.size();
    std::vector<std::string> Efekt;
    std::string Eprva="ATK:3";
    std::string Edruga="DEF:3";                        //Ovo se treba pokupiti getterima iz klase karti !!!!IMPORTANT AF
    std::string Etreca="MAGE ";
    std::string ESesta="DEF:2";
    Efekt.push_back(Eprva);
    Efekt.push_back(Edruga);
    Efekt.push_back(Etreca);
    Efekt.push_back(ESesta);
    //____________________________________________________
    for(int k=0;k<VisinaKarte;k++)
    { combinedText.clear();
      if(k==0 || k==VisinaKarte-1)
      { combinedText.clear();
        for(int ku=0;ku<brKrt;ku++)
        {
         combinedText=combinedText+UpDownGranica+Razmak;
        }
      }
      else if(k==2)
      {
        std::string tempCombinedTekst;
         tempCombinedTekst.clear();
        for(int ku=0;ku<brKrt;ku++)
        {
         int PrazanProstor=17-ImenaKarti[ku].size();
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
         tempCombinedTekst=tempCombinedTekst+ImenaKarti[ku];
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
        std::string tempCombinedTekst;
         tempCombinedTekst.clear();
        for(int ku=0;ku<brKrt;ku++)
        {
         tempCombinedTekst=tempCombinedTekst+"I "+Efekt[ku]+MalaSideGranica+Razmak;
        }
        combinedText=tempCombinedTekst;
      }

      else
      {
       combinedText.clear();
       for(int ku=0;ku<brKrt;ku++)
        {
         combinedText=combinedText+SidesGranica+Razmak;
        }
      }

     printCenteredTextWithinWidth(combinedText, terminalWidth);
    }
//____________________________________________________________________________________________________________________________________________________
//Ispis healtha protivnika
    int OpponentHealth=5;
    combinedText="OPPONENT HEALTH: "+std::to_string(OpponentHealth);
    printCenteredTextWithinWidth(combinedText, terminalWidth);

//____________________________________________________________________________________________________________________________________________________
//BOARD KARTA
 std::string BoardCardIme ="Board card";
  for(int ki=0;ki<=VisinaBoardKarte;ki++)
     { combinedText.clear();
      if(ki==0 || ki==VisinaBoardKarte)
        combinedText=BoardKartaUpDownGranica;
      else if(ki==4)
      {
        int TempSirinaBoardKarte=BoardKartaSidesGranica.size()-BoardCardIme.size();
            combinedText=combinedText+"I";
            TempSirinaBoardKarte-=2;
        if (TempSirinaBoardKarte%2!=0)
            {
             combinedText=combinedText+" ";
             TempSirinaBoardKarte--;
            }
            for(int ka=0;ka<=TempSirinaBoardKarte/2;ka++)
                combinedText=combinedText+" ";
            combinedText=combinedText+BoardCardIme;
            for(int ka=1;ka<TempSirinaBoardKarte/2;ka++)
                combinedText=combinedText+" ";
            combinedText=combinedText+"I";
      }
      else
        combinedText=BoardKartaSidesGranica;

        printCenteredTextWithinWidth(combinedText, terminalWidth);
     }
//_________________________________________________________________________________________________________________________________________________
//Ispis odigranih karti trenutnog igraca
 std::vector<std::string> ImenaKartiIgraca;
    std::string prva1="Bejzik";
    std::string druga1="Nosmoke";
    std::string treca1="Ameena";
    ImenaKartiIgraca.push_back(prva1);
    ImenaKartiIgraca.push_back(druga1);
    ImenaKartiIgraca.push_back(treca1);
    brKrt= ImenaKartiIgraca.size();
    std::vector<std::string> Efekt1;
    std::string Eprva1="MAGE ";
    std::string Edruga1="ATK:1";                        //Ovo se treba pokupiti getterima iz klase karti !!!!IMPORTANT AF
    std::string Etreca1="MAGE ";
    Efekt1.push_back(Eprva1);
    Efekt1.push_back(Edruga1);
    Efekt1.push_back(Etreca1);
    //____________________________________________________
    for(int k=0;k<VisinaKarte;k++)
    { combinedText.clear();
      if(k==0 || k==VisinaKarte-1)
      { combinedText.clear();
        for(int ku=0;ku<brKrt;ku++)
        {
         combinedText=combinedText+UpDownGranica+Razmak;
        }
      }
      else if(k==2)
      {
        std::string tempCombinedTekst;
         tempCombinedTekst.clear();
        for(int ku=0;ku<brKrt;ku++)
        {
         int PrazanProstor=17-ImenaKartiIgraca[ku].size();
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
         tempCombinedTekst=tempCombinedTekst+ImenaKartiIgraca[ku];
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
        std::string tempCombinedTekst;
         tempCombinedTekst.clear();
        for(int ku=0;ku<brKrt;ku++)
        {
         tempCombinedTekst=tempCombinedTekst+"I "+Efekt1[ku]+MalaSideGranica+Razmak;
        }
        combinedText=tempCombinedTekst;
      }

      else
      {
       combinedText.clear();
       for(int ku=0;ku<brKrt;ku++)
        {
         combinedText=combinedText+SidesGranica+Razmak;
        }
      }

     printCenteredTextWithinWidth(combinedText, terminalWidth);
    }
//__________________________________________________________________________________________________________________________
//Ispis karti u ruci trenutnog igraca
 std::vector<std::string> ImenaKartiIgracaRuka;
    std::string prva0="Bejzik";
    std::string druga0="Nosmoke";
    std::string treca0="Ameena";
    std::string cetvrta0="Ohm";
    ImenaKartiIgracaRuka.push_back(prva0);
    ImenaKartiIgracaRuka.push_back(druga0);
    ImenaKartiIgracaRuka.push_back(treca0);
    ImenaKartiIgracaRuka.push_back(cetvrta0);
    brKrt= ImenaKartiIgracaRuka.size();
    std::vector<std::string> Efekt0;
    std::string Eprva0   ="ATK:2";
    std::string Edruga0  ="ATK:2";                        //Ovo se treba pokupiti getterima iz klase karti !!!!IMPORTANT AF
    std::string Etreca0  ="MAGE ";                        //Efekt zautima iskljucivo 6 karaktera,visak dodaj space ili popravi
    std::string Ecetvrta0="DEF:2";
    Efekt0.push_back(Eprva0);
    Efekt0.push_back(Edruga0);
    Efekt0.push_back(Etreca0);
    Efekt0.push_back(Ecetvrta0);
    //____________________________________________________
    for(int k=0;k<VisinaKarte;k++)
    { combinedText.clear();
      if(k==0 || k==VisinaKarte-1)
      { combinedText.clear();
        for(int ku=0;ku<brKrt;ku++)
        {
         combinedText=combinedText+UpDownGranica+Razmak;
        }
      }
      else if(k==2)
      {
        std::string tempCombinedTekst;
         tempCombinedTekst.clear();
        for(int ku=0;ku<brKrt;ku++)
        {
         int PrazanProstor=17-ImenaKartiIgracaRuka[ku].size();
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
         tempCombinedTekst=tempCombinedTekst+ImenaKartiIgracaRuka[ku];
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
        std::string tempCombinedTekst;
         tempCombinedTekst.clear();
        for(int ku=0;ku<brKrt;ku++)
        {
         tempCombinedTekst=tempCombinedTekst+"I "+Efekt0[ku]+MalaSideGranica+Razmak;
        }
        combinedText=tempCombinedTekst;
      }

      else
      {
       combinedText.clear();
       for(int ku=0;ku<brKrt;ku++)
        {
         combinedText=combinedText+SidesGranica+Razmak;
        }
      }

     printCenteredTextWithinWidth(combinedText, terminalWidth);
    }
    return 0;
}
