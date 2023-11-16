#include "Astral_Nexus.cpp"

int main()
{
    Runda runda;
    Player jedan, dva;
    cout<<"Hello, Mage!"<<endl;

    jedan = runda.Dodaj_Igraca();
    dva = runda.Dodaj_Igraca();
    runda.Smjesti_Igrace(jedan, dva);


    return 0;
}