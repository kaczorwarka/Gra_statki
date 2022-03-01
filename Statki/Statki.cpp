#include "Gracz.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "Bot.h"



int main()
{
    bool wygrana = false;
    int wybor;
    bool zgodnosc = true;
    srand(time(NULL));
    std::cout << "tryb gry: [1] - Gracz VS Gracz; [2] - BOT VS BOT; [3] - Gracz VS BOT" << std::endl;
    std::cout << "podaj: ";
    std::cin >> wybor;
    switch(wybor)
    {
    case 1:
	    {
        Gracz g1, g2;
        //stworzenie dwoch tablic graczy ze statakami
        g1.nr = 1;
        g2.nr = 2;
        g1.wypelnij();
        g2.wypelnij();
        std::cout << "jak odadc elementy: [1] - automatycznie; [2] - recznie" << std::endl;
        std::cout << "podaj: ";
        std::cin >> wybor;
        //opcja wyboru w jaki sposob dodac
        switch (wybor)
        {
        case (1):
        {
            g1.dodaj_auto();
            g2.dodaj_auto();
            break;
        }
        case(2):
        {
            g1.dodaj_recznie();
            g2.dodaj_recznie();
            break;
        }
        }
        //mozliwosc wypisania planszy ze statkami
        std::cout << "czy wypisac plansze przed rozpoczeciem gry [1] - tak; [2] - nie" << std::endl;
        std::cout << "podaj: ";
        std::cin >> wybor;
        system("cls");
        switch (wybor)
        {
        case(1):
        {
            g1.wypisz_twoja();
            std::cout << "ilosc statkow" << std::endl;
            for (int i = 0; i < 4; i++)
            {
                std::cout << "ilos statkow " << i + 2 << " masztowych: " << g1.statek[i] << std::endl;
            }
            system("pause");
            system("cls");
            g2.wypisz_twoja();
            std::cout << "ilosc statkow" << std::endl;
            for (int i = 0; i < 4; i++)
            {
                std::cout << "ilos statkow " << i + 2 << " masztowych: " << g2.statek[i] << std::endl;
            }
        		system("pause");
                system("cls");
            break;
        }
        case(2): break;
        }
        while (1)
        {
            //w petli wykonywanie strzalow przez graczy na zmiane az do momentu czyjejs wygranej
            //Aby przejsc do kolejnego gracza nalezy po strzale klikna ENTER
            system("cls");
            g1.wypisz_vs();
            std::cout << "ilosc statkow przeciwnika" << std::endl;
            for (int i = 0; i < 4; i++)
            {
                std::cout << "ilos statkow " << i + 2 << " masztowych: " << g2.statek[i] << std::endl;
            }
            g1.strzal(g2.plansza,g2.statek);
            if (g1.czy_wygrana(g2.plansza, g2.statek))
            {
                break;
            }
            system("cls");
            g1.wypisz_vs();
            std::cout << "ilosc statkow przeciwnika" << std::endl;
            for (int i = 0; i < 4; i++)
            {
                std::cout << "ilos statkow " << i + 2 << " masztowych: " << g2.statek[i] << std::endl;
            }
            system("pause");
            system("cls");
            g2.wypisz_vs();
            std::cout << "ilosc statkow przeciwnika" << std::endl;
            for (int i = 0; i < 4; i++)
            {
                std::cout << "ilos statkow " << i + 2 << " masztowych: " << g1.statek[i] << std::endl;
            }
            g2.strzal(g1.plansza,g1.statek);
            if (g2.czy_wygrana(g1.plansza, g1.statek))
            {
                break;
            }
            system("cls");
            g2.wypisz_vs();
            for (int i = 0; i < 4; i++)
            {
                std::cout << "ilos statkow " << i + 2 << " masztowych: " << g1.statek[i] << std::endl;
            }
            system("pause");
        }
        break;
	    }
    case 2:
	    {
        Bot b1, b2;
        b1.nr = 1;
        b2.nr = 2;
        b1.wypelnij();
        b2.wypelnij();
        system("cls");
        b1.dodaj_auto();
        b2.dodaj_auto();
        b1.wypisz_twoja();
        std::cout << "ilosc statkow" << std::endl;
        for (int i = 0; i < 4; i++)
        {
            std::cout << "ilos statkow " << i + 2 << " masztowych: " << b1.statek[i] << std::endl;
        }
        system("pause");
        system("cls");
        b2.wypisz_twoja();
        std::cout << "ilosc statkow" << std::endl;
        for (int i = 0; i < 4; i++)
        {
            std::cout << "ilos statkow " << i + 2 << " masztowych: " << b2.statek[i] << std::endl;
        }
        system("pause");
        system("cls");
        while(zgodnosc)
        {
            system("cls");
            while(1)
            {
                if(b1.szukaj[5] == 0)
                {
                    b1.wypisz_vs();
                    std::cout << "ilosc statkow przeciwnika" << std::endl;
                    for (int i = 0; i < 4; i++)
                    {
                        std::cout << "ilos statkow " << i + 2 << " masztowych: " << b2.statek[i] << std::endl;
                    }
					//Sleep(1000);
                    system("pause");
                    system("cls");
                }
                b1.strzal_bot(b2.plansza, b2.statek);
                b1.wypisz_vs();
                std::cout << "ilosc statkow przeciwnika" << std::endl;
                for (int i = 0; i < 4; i++)
                {
                    std::cout << "ilos statkow " << i + 2 << " masztowych: " << b2.statek[i] << std::endl;
                }
                if (b1.czy_wygrana(b2.plansza, b2.statek))
                {
                    zgodnosc = false;
                    break;
                }
                //Sleep(1000);
                system("pause");
                system("cls");
                if(b1.szukaj[5] == 0)
                {
                    break;
                }
            }
            if (zgodnosc == true)
            {
                while (1)
                {
                    if (b2.szukaj[5] == 0)
                    {
                        b2.wypisz_vs();
                        std::cout << "ilosc statkow przeciwnika" << std::endl;
                        for (int i = 0; i < 4; i++)
                        {
                            std::cout << "ilos statkow " << i + 2 << " masztowych: " << b1.statek[i] << std::endl;
                        }
                        //Sleep(1000);
                        system("pause");
                        system("cls");
                    }
                    b2.strzal_bot(b1.plansza, b1.statek);
                    b2.wypisz_vs();
                    std::cout << "ilosc statkow przeciwnika" << std::endl;
                    for (int i = 0; i < 4; i++)
                    {
                        std::cout << "ilos statkow " << i + 2 << " masztowych: " << b1.statek[i] << std::endl;
                    }
                    if (b2.czy_wygrana(b1.plansza, b1.statek))
                    {
                        zgodnosc = false;
                        break;
                    }
                    //Sleep(1000);
                    system("pause");
                    system("cls");
                    if (b2.szukaj[5] == 0)
                    {
                        break;
                    }
                }
            }
        }
        break;
	    }
    case 3:
	    {
        Gracz g1;
        Bot b1;
        g1.nr = 1;
        b1.nr = 2;
        g1.wypelnij();
        b1.wypelnij();
        std::cout << "jak odadc elementy: [1] - automatycznie; [2] - recznie" << std::endl;
        std::cout << "podaj: ";
        std::cin >> wybor;
        switch (wybor)
        {
        case 1:
	        {
            g1.dodaj_auto();
            break;
	        }
        case 2:
	        {
            g1.dodaj_recznie();
            break;
	        }
        }
        b1.dodaj_auto();
        std::cout << "czy wypisac plansze przed rozpoczeciem gry [1] - tak; [2] - nie" << std::endl;
        std::cout << "podaj: ";
        std::cin >> wybor;
        system("cls");
        switch (wybor)
        {
        case 1:
	        {
            g1.wypisz_twoja();
            std::cout << "ilosc statkow" << std::endl;
            for (int i = 0; i < 4; i++)
            {
                std::cout << "ilos statkow " << i + 2 << " masztowych: " << g1.statek[i] << std::endl;
            }
            system("pause");
            system("cls");
            b1.wypisz_twoja();
            std::cout << "ilosc statkow przeciwnika" << std::endl;
            for (int i = 0; i < 4; i++)
            {
                std::cout << "ilos statkow " << i + 2 << " masztowych: " << b1.statek[i] << std::endl;
            }
            system("pause");
            system("cls");
            break;
	        }
        case 2: break;
        }
        while (zgodnosc)
        {
            

            system("cls");
            g1.wypisz_vs();
            std::cout << "ilosc statkow przeciwnika" << std::endl;
            for (int i = 0; i < 4; i++)
            {
                std::cout << "ilos statkow " << i + 2 << " masztowych: " << b1.statek[i] << std::endl;
            }
            g1.strzal(b1.plansza,b1.statek);
            if (g1.czy_wygrana(b1.plansza, b1.statek))
            {
                zgodnosc = false;
                break;
            }
            system("cls");
            g1.wypisz_vs();
            std::cout << "ilosc statkow przeciwnika" << std::endl;
            for (int i = 0; i < 4; i++)
            {
                std::cout << "ilos statkow " << i + 2 << " masztowych: " << b1.statek[i] << std::endl;
            }

            system("pause");
            system("cls");
            while(1)
            {
                if (b1.szukaj[5]==0)
                {
                    b1.wypisz_vs();
                    std::cout << "ilosc statkow przeciwnika" << std::endl;
                    for (int i = 0; i < 4; i++)
                    {
                        std::cout << "ilos statkow " << i + 2 << " masztowych: " << g1.statek[i] << std::endl;
                    }
                    system("pause");
                    //Sleep(1000);
                    system("cls");
                }
                b1.strzal_bot(g1.plansza, g1.statek);
                b1.wypisz_vs();
                std::cout << "ilosc statkow przeciwnika" << std::endl;
                for (int i = 0; i < 4; i++)
                {
                    std::cout << "ilos statkow " << i + 2 << " masztowych: " << g1.statek[i] << std::endl;
                }
                if (b1.czy_wygrana(g1.plansza, g1.statek))
                {
                    zgodnosc = false;
                    break;
                }
                system("pause");
                //Sleep(1000);
                system("cls");
                if(b1.szukaj[5]==0)
                {
                    break;
                }

            }
        }
        break;
	    }
    }
}


