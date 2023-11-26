#include "Astral_Nexus.h"

Player Runda::Dodaj_Igraca()
{
    std::string naziv_Igraca;
    Player current;

    std::cout << "Unesite svoje ime : " << std::endl;
    std::cin >> naziv_Igraca;
    current.set_Ime(naziv_Igraca);

    return current;
}

void Runda::Smjesti_Igrace(Player one, Player two)
{
    Player current;
    this->igraci.push_back(one);
    this->igraci.push_back(two);

    std::cout << "Zapocinje runda ASTRAL NEXUS - a!!!" << std::endl << std::endl;

    for (int i = 0; i < igraci.size(); i++)
    {
        current = igraci[i];
        std::cout << "Igrac " << i + 1 << " je : " << current.get_Ime() << std::endl;
    }

    std::cout << std::endl << "Sretno i neka najbolji pobjedi!" << std::endl;
}

Player Runda::get_Igrac(int index)
{
    return this->igraci[index];
}