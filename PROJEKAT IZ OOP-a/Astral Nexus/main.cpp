#include "Astral_Nexus.cpp"
#include "Data_dll.cpp"

int main()
{

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
    Runda runda;
    Player jedan, dva;
    cout<<"Hello, Mage!"<<endl;

    jedan = runda.Dodaj_Igraca();
    dva = runda.Dodaj_Igraca();
    runda.Smjesti_Igrace(jedan, dva);

    jedan.Build_Deck();
    jedan.Shuffle_Deck();
    
    dva.Build_Deck();
    dva.Shuffle_Deck();

    cout<<"Karte prvog igraca : "<<endl; 

    jedan.Draw_Hand();
    jedan.See_Hand();

    cout<<endl<<"Karte drugog igraca : "<<endl;

    dva.Draw_Hand();
    dva.See_Hand();


    return 0;
}
