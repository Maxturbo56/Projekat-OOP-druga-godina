#include "Astral_Nexus.cpp"
#include "Data_dll.cpp"

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
    Player jedan, dva;
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

    do{
        jedan.Update();

        cout<<jedan.get_Ime()<<" : Health Points : "<<jedan.get_HP()<<endl;
        cout<<"Karta koja se igra : "<<jedan.get_Current().get_Naziv()<<endl<<endl;

        cout<<"HAND ONE : "<<endl;
        jedan.See_Hand();


        cout<<endl<<endl<<"BOARD ONE : "<<endl;
        jedan.See_Board();

        cout<<endl<<endl<<endl<<dva.get_Ime()<<" : Health Points : "<<dva.get_HP()<<endl<<endl;
        
        if(GetKeyState('Q') & 0x8000)
        {
            break;
        }
        Sleep(300);
        system("CLS");
    }while(1);


    system("helloworld.exe");
    return 0;
}
