#include "Astral_Nexus.h"

Player Runda::Dodaj_Igraca()
{
    string naziv_Igraca;
    Player current;

    cout<<"Unesite svoje ime : "<<endl;
    cin>>naziv_Igraca;
    current.set_Ime(naziv_Igraca);

    return current;
}

void Runda::Smjesti_Igrace(Player one, Player two)
{
    Player current;
    this->igraci.push_back(one);
    this->igraci.push_back(two);

    cout<<"Zapocinje runda ASTRAL NEXUS - a!!!"<<endl<<endl;
    
    for(int i = 0; i < igraci.size(); i++)
    {
        current = igraci[i];
        cout<<"Igrac "<<i + 1<<" je : "<<current.get_Ime()<<endl;
    }
   
    cout<<endl<<"Sretno i neka najbolji pobjedi!"<<endl;
}

Player Runda::get_Igrac(int index)
{
    return this->igraci[index];
}