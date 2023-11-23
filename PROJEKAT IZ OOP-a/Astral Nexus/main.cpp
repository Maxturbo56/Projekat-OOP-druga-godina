#include "Astral_Nexus.cpp"
#include "Data_dll.cpp"
#include <conio.h>

Player jedan, dva;
int do_4 = 0;

void DO_THE_MATH()
{
    cout<<"ODIGRANA RUNDA!!"<<endl;
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
    cout<<"POCINJE NOVA RUNDA! OBA IGRACA SU IZVUKLI PO JEDNU KARTU!"<<endl;
    Sleep(1000);   
}

void Handle_Jedan()
{
    jedan.Update();
    cout<<jedan.get_Ime()<<" : Health Points : "<<jedan.get_HP()<<endl<<endl;
    cout<<"----------------------------------"<<endl<<endl;   
    cout<<"Karta koja se igra : "<<jedan.get_Current().get_Naziv()<<endl<<endl;
    cout<<"----------------------------------"<<endl<<endl;   
    cout<<jedan.get_Ime()<<" HAND :" <<endl;
    jedan.See_Hand();        
    cout<<endl<<"----------------------------"<<endl<<endl;   
    cout<<jedan.get_Ime()<<" BOARD :" <<endl;
    jedan.See_Board();
    cout<<endl<<"----------------------------"<<endl<<endl;
    cout<<"DISCARD PILE : "<<endl;
    jedan.See_Discard();
    cout<<endl<<"----------------------------"<<endl<<endl;
    cout<<" >>>>>>>>>>> DRUGI IGRAC <<<<<<<<<"<<endl<<endl;
    cout<<dva.get_Ime()<<" : Health Points : "<<dva.get_HP()<<endl<<endl;
    cout<<"----------------------------------"<<endl<<endl;
    cout<<dva.get_Ime()<<" BOARD :" <<endl;
    dva.See_Board();
}

void Handle_Dva()
{
    dva.Update();
    cout<<dva.get_Ime()<<" : Health Points : "<<dva.get_HP()<<endl<<endl;
    cout<<"----------------------------------"<<endl<<endl;   
    cout<<"Karta koja se igra : "<<dva.get_Current().get_Naziv()<<endl<<endl;
    cout<<"----------------------------------"<<endl<<endl;   
    cout<<dva.get_Ime()<<" HAND :" <<endl;
    dva.See_Hand();        
    cout<<endl<<"----------------------------------"<<endl<<endl;   
    cout<<dva.get_Ime()<<" BOARD :" <<endl;
    dva.See_Board();
    cout<<endl<<"----------------------------------"<<endl<<endl;
    cout<<" >>>>>>>>>>> DRUGI IGRAC <<<<<<<<<"<<endl<<endl;
    cout<<jedan.get_Ime()<<" : Health Points : "<<jedan.get_HP()<<endl<<endl;
    cout<<"----------------------------------"<<endl<<endl;
    cout<<jedan.get_Ime()<<" BOARD :" <<endl;
    jedan.See_Board();
}

int main()
{
    string user_Input;
    string user;
    string pass;

    // -------------------- RANDOMIZATION --------------------- //
    srand(time(NULL));
    srand(time(NULL));

    //---------- ADMIN ACCESS -------------- //

    cout<<"Enter your username : "<<endl;
    cin>>user;
    cout<<"Enter your password : "<<endl;
    cin>>pass;
    if(user == "admin" && pass == "admin")
    {
        User_Admin();
    }
    else
    {
        cout<<"User Access... \n\n\tLoading..."<<endl;
        Sleep(300);
    }

    // -------------------- MAIN --------------------- //

    // SETUP TO PLAY

    Runda runda;
    cout<<"Hello, Mage!"<<endl;

    jedan = runda.Dodaj_Igraca();
    dva = runda.Dodaj_Igraca();
    runda.Smjesti_Igrace(jedan, dva);

    cout<<"Igrac jedan molimo unesite ime spila koji zelite igrati : "<<endl;
    cin>>user_Input;
    jedan.set_Deck_Name(user_Input);

    cout<<"Igrac dva molimo unesite ime spila koji zelite igrati : "<<endl;
    cin>>user_Input;
    dva.set_Deck_Name(user_Input);

    jedan.Build_Deck(jedan.get_Deck_Name());
    jedan.Shuffle_Deck();
    
    dva.Build_Deck(dva.get_Deck_Name());
    dva.Shuffle_Deck();

    cout<<"Karte prvog igraca : "<<endl; 

    jedan.Draw_Hand();
    jedan.See_Hand();

    cout<<endl<<"Karte drugog igraca : "<<endl;

    dva.Draw_Hand();
    dva.See_Hand();

    // ------- THE GAMEPLAY LOOP ---------- //

    system("cls");

    cout<<"MAGES, CLASH!"<<endl;

    Sleep(400);

    int trenutni = 0;
    do{

        if(do_4 == 4)
        {
            DO_THE_MATH();
        }
    
        cout<<" H = sljedeca karta ; J = prethodna karta ; K = odigraj kartu ;  Q = izadji iz igre"<<endl<<endl;

        if(trenutni == 0)
        {
            Handle_Jedan();
            if(jedan.played_Card)
            {
                do_4++;
                jedan.played_Card = false;
                trenutni = 1;
                system("CLS"); 
                cout<<"Mijenja se igrac na : "<<dva.get_Ime()<<" molimo pricekajte ..."<<endl<<endl;
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
                cout<<"Mijenja se igrac na : "<<jedan.get_Ime()<<" molimo pricekajte ..."<<endl<<endl;
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
