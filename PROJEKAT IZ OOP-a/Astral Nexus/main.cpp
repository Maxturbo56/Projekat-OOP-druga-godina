#include "Astral_Nexus.cpp"
#include "Data_dll.cpp"
#include "conio.h"

Player jedan, dva;
int do_4 = 0;

void DO_THE_MATH()
{
    std::cout<<"ODIGRANA RUNDA!!"<<std::endl;
    jedan.Calculate_Board_Value();
    dva.Calculate_Board_Value();
    int jedan_Vrijednost = jedan.get_Board_Value();
    int dva_Vrijednost = dva.get_Board_Value();
    jedan.set_HP(jedan.get_HP() - dva_Vrijednost);
    dva.set_HP(dva.get_HP() - jedan_Vrijednost);
    jedan.Draw();
    dva.Draw();
    do_4 = 0;
    system("CLS");
    std::cout<<"POCINJE NOVA RUNDA! OBA IGRACA SU IZVUKLI PO JEDNU KARTU!"<<std::endl;
    Sleep(1000);   
}

void Handle_Jedan()
{
    jedan.Update();
    std::cout<<jedan.get_Ime()<<" : Health Points : "<<jedan.get_HP()<<std::endl<<std::endl;
    std::cout<<"----------------------------------"<<std::endl<<std::endl;   
    std::cout<<"Karta koja se igra : "<<jedan.get_Current().get_Naziv()<<std::endl<<std::endl;
    std::cout<<"----------------------------------"<<std::endl<<std::endl;   
    std::cout<<jedan.get_Ime()<<" HAND :" <<std::endl;
    jedan.See_Hand();        
    std::cout<<std::endl<<"----------------------------"<<std::endl<<std::endl;   
    std::cout<<jedan.get_Ime()<<" BOARD :" <<std::endl;
    jedan.See_Board();
    std::cout<<std::endl<<"----------------------------"<<std::endl<<std::endl;
    std::cout<<"DISCARD PILE : "<<std::endl;
    jedan.See_Discard();
    std::cout<<std::endl<<"----------------------------"<<std::endl<<std::endl;
    std::cout<<" >>>>>>>>>>> DRUGI IGRAC <<<<<<<<<"<<std::endl<<std::endl;
    std::cout<<dva.get_Ime()<<" : Health Points : "<<dva.get_HP()<<std::endl<<std::endl;
    std::cout<<"----------------------------------"<<std::endl<<std::endl;
    std::cout<<dva.get_Ime()<<" BOARD :" <<std::endl;
    dva.See_Board();
}

void Handle_Dva()
{
    dva.Update();
    std::cout<<dva.get_Ime()<<" : Health Points : "<<dva.get_HP()<<std::endl<<std::endl;
    std::cout<<"----------------------------------"<<std::endl<<std::endl;   
    std::cout<<"Karta koja se igra : "<<dva.get_Current().get_Naziv()<<std::endl<<std::endl;
    std::cout<<"----------------------------------"<<std::endl<<std::endl;   
    std::cout<<dva.get_Ime()<<" HAND :" <<std::endl;
    dva.See_Hand();        
    std::cout<<std::endl<<"----------------------------------"<<std::endl<<std::endl;   
    std::cout<<dva.get_Ime()<<" BOARD :" <<std::endl;
    dva.See_Board();
    std::cout<<std::endl<<"----------------------------------"<<std::endl<<std::endl;
    std::cout<<" >>>>>>>>>>> DRUGI IGRAC <<<<<<<<<"<<std::endl<<std::endl;
    std::cout<<jedan.get_Ime()<<" : Health Points : "<<jedan.get_HP()<<std::endl<<std::endl;
    std::cout<<"----------------------------------"<<std::endl<<std::endl;
    std::cout<<jedan.get_Ime()<<" BOARD :" <<std::endl;
    jedan.See_Board();
}

int main()
{
    std::string user_Input;
    std::string user;
    std::string pass;

    // -------------------- RANDOMIZATION --------------------- //
    srand(time(NULL));
    srand(time(NULL));

    //---------- ADMIN ACCESS -------------- //

    std::cout<<"Enter your username : "<<std::endl;
    std::cin>>user;
    std::cout<<"Enter your password : "<<std::endl;
    std::cin>>pass;
    if(user == "admin" && pass == "admin")
    {
        User_Admin();
    }
    else
    {
        std::cout<<"User Access... \n\n\tLoading..."<<std::endl;
        Sleep(300);
    }

    // -------------------- MAIN --------------------- //

    // SETUP TO PLAY

    Runda runda;
    std::cout<<"Hello, Mage!"<<std::endl;

    jedan = runda.Dodaj_Igraca();
    dva = runda.Dodaj_Igraca();
    runda.Smjesti_Igrace(jedan, dva);

    std::cout<<"Igrac jedan molimo unesite ime spila koji zelite igrati : "<<std::endl;
    std::cin>>user_Input;
    jedan.set_Deck_Name(user_Input);

    std::cout<<"Igrac dva molimo unesite ime spila koji zelite igrati : "<<std::endl;
    std::cin>>user_Input;
    dva.set_Deck_Name(user_Input);

    jedan.Build_Deck(jedan.get_Deck_Name());
    jedan.Shuffle_Deck();
    
    dva.Build_Deck(dva.get_Deck_Name());
    dva.Shuffle_Deck();

    std::cout<<"Karte prvog igraca : "<<std::endl; 

    jedan.Draw_Hand();
    jedan.See_Hand();

    std::cout<<std::endl<<"Karte drugog igraca : "<<std::endl;

    dva.Draw_Hand();
    dva.See_Hand();

    // ------- THE GAMEPLAY LOOP ---------- //

    system("cls");

    std::cout<<"MAGES, CLASH!"<<std::endl;

    Sleep(400);

    int trenutni = 0;
    do{

        if(do_4 == 4)
        {
            DO_THE_MATH();
        }
    
        std::cout<<" H = sljedeca karta ; J = prethodna karta ; K = odigraj kartu ;  Q = izadji iz igre"<<std::endl<<std::endl;

        if(trenutni == 0)
        {
            Handle_Jedan();
            if(jedan.played_Card)
            {
                do_4++;
                jedan.played_Card = false;
                trenutni = 1;
                system("CLS"); 
                std::cout<<"Mijenja se igrac na : "<<dva.get_Ime()<<" molimo pricekajte ..."<<std::endl<<std::endl;
                jedan.Calculate_Board_Value();
                Sleep(1500);
            }
        }
        else if(trenutni == 1)
        {
            Handle_Dva();
            if(dva.played_Card)
            {
                do_4++;
                dva.played_Card = false;
                trenutni = 0;
                system("CLS");
                std::cout<<"Mijenja se igrac na : "<<jedan.get_Ime()<<" molimo pricekajte ..."<<std::endl<<std::endl;
                dva.Calculate_Board_Value();
                Sleep(1500);
            }
        }

        if(GetKeyState('Q') & 0x8000)
        {
            break;
        }
        Sleep(90);
        system("CLS");
    }while(1);


    system("helloworld.exe");
    return 0;
}
