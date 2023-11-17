#include<fstream>
#include<windows.h>
#include<iostream>

// -------------- USER ADMIN ACCESS FUNCTION FOR ADDING CARDS INTO THE DATABASE ----------- //

void User_Admin()
{
    std::ofstream file_IN;
    char choice;
    std::string naziv;
    std::string value;
    std::string broj_Karte;

    file_IN.open("Cards_dll.txt", ios::app);	// Ovdje se otvara fajl za upisivanje
    do{
        std::cout<<"Do you wish to add a card to the database? (Y / N)"<<std::endl;
        std::cin>>choice;
        if(choice == 'Y' || choice == 'y')
        {
            std::cout<<"Enter the card number : "<<std::endl;
            std::cin>>broj_Karte;
            std::cout<<"Enter the name of the card : "<<std::endl;
            std::cin>>naziv;
            std::cout<<"Enter the attack value of the card : "<<std::endl;
            std::cin>>value;
            file_IN<<broj_Karte<<std::endl<<naziv<<std::endl<<value<<std::endl<<"#"<<std::endl;
        }
        else if(choice == 'N' || choice == 'n')
        {
            std::cout<<"Exiting Admin Access..."<<std::endl;
            Sleep(500);
            break;
        }
        else
        {
            std::cout<<"Invalid input, try again."<<std::endl;
        }
    }while(1);
    file_IN.close();
}