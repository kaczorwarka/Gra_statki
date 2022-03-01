#include "Gracz.h"
#include <iostream>
#include <stdlib.h>
#include <windows.h>

void Gracz::dodaj_recznie()
{
    int x, y;
    char orientacja;
    bool zgodnosc = false;
    int ilosc_statkow = 0;
    int granica2 = (granica * granica) * 0.3;
    std::cout << "Graczu nr " << nr << std::endl;
    while (!zgodnosc)
    {
        zgodnosc = true;
        for (int i = 0; i < 4; i++)
        {
            std::cout << "ile statkow " << i + 2 << " elelemtowych: ";
            std::cin >> statek[i];
            ilosc_statkow += statek[i] * (i + 2);
        }
        if (ilosc_statkow > granica2)
        {
            std::cout << "ilosc statkow jest za duza, podaj statki jeszcze raz" << std::endl;
            zgodnosc = false;
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < statek[i]; j++)
        {
            zgodnosc = false;
            while (!zgodnosc)
            {
                std::cout << "podaj koordynaty pocz¹tku statku "<< i + 2 <<" elementowego" << std::endl;
                std::cout << "Y: ";
                std::cin >> x;
                std::cout << "X: ";
                std::cin >> y;
                std::cout << "podaj orientacje h/v: ";
                std::cin >> orientacja;
                switch (orientacja)
                {
                case 'h':
                {
                    if (x + i + 2 > granica || y >= granica)
                    {
                        std::cout << "statek nie miesci sie na planszy" << std::endl;
                        break;
                    }
                    else
                    {
                        zgodnosc = true;
                        for (int k = 0; k < i + 2; k++)
                        {
                            if (!sprawdz_h(k, y, x, i)) zgodnosc = false;
                        }
                        if (zgodnosc == false) std::cout << "statki koliduja ze soba" << std::endl;
                        else
                        {
                            for (int k = 0; k < i + 2; k++)
                            {
                                plansza[x + k][y] = '0' + (i + 2);
                            }
                        }
                        break;
                    }
                }
                case 'v':
                {
                    if (y + i + 2 > granica || x >= granica) {
                        std::cout << "statek nie miesci sie na planszy" << std::endl;
                        break;
                    }
                    else
                    {
                        zgodnosc = true;
                        for (int k = 0; k < i + 2; k++)
                        {
                            if (!sprawdz_v(k, y, x, i)) zgodnosc = false;
                        }
                        if (zgodnosc == false) std::cout << "statki koliduja ze soba" << std::endl;
                        else
                        {
                            for (int k = 0; k < i + 2; k++)
                            {
                                plansza[x][y + k] = '0' + (i + 2);
                            }
                        }
                        break;
                    }
                }
                }
            }
        }
    }
}

void Gracz::dodaj_auto()
{
    int x, y, ilosc_statkow, random;
    int orientacja;
    int granica2 =  (granica * granica) * 0.3;

    bool zgodnosc = false;
    
    while (!zgodnosc)
    {
        for (int i = 0; i < 4; i++)
        {
            statek[i] = 1;
        }
        ilosc_statkow = 14;
        zgodnosc = true;
        for (int i = 0; i < 4; i++)
        {
            random = rand() % granica2 + 1;
            ilosc_statkow += random;
            statek[i] += random / (i + 2);
        }
        if (ilosc_statkow > granica2)
        {
            zgodnosc = false;

        }
    }
    
    //statek[0] = 20;
    //statek[1] = 20;
    //statek[2] = 20;
    //statek[3] = 18;
    
    for (int i = 3; i > -1; i--)
    {
        for (int j = 0; j < statek[i]; j++)
        {
            zgodnosc = false;
            while (!zgodnosc)
            {
                zgodnosc = true;
                x = rand() % granica;
                y = rand() % granica;
                orientacja = rand() % 2;
                if (zgodnosc == true)
                {
                    
                    switch (orientacja)
                    {
                    case 0:
                    {
                    		zgodnosc = auto_h(x, y, i);
                    		if(zgodnosc == false)
                            {
                                zgodnosc = auto_v(x, y, i);
                            }
							break;
                    }
                    case 1:
                    {
							zgodnosc = auto_v(x, y, i);
                            if(zgodnosc == false)
                            {
                                zgodnosc = auto_h(x, y, i);
                            }
							break;
                    }
                    }
                }
            }
        }
    }
}

void Gracz::wypelnij()
{
    for (int i = 0; i < granica; i++)
    {
        for (int j = 0; j < granica; j++)
        {
            plansza_vs[i][j] = '*';
            plansza[i][j] = '*';
        }
    }
}

void Gracz::wypisz_twoja()
{
    std::cout << "tablia gracza " << nr << std::endl;
    for (int i = 0; i < granica; i++)
    {
        for (int j = 0; j < granica; j++)
        {
            std::cout << "  " << plansza[i][j];
        }
        std::cout << std::endl;
    }
}

void Gracz::wypisz_vs()
{
    for (int i = 0; i < granica; i++)
    {
        for (int j = 0; j < granica; j++)
        {
            std::cout << "  " << plansza_vs[i][j];
        }
        std::cout << std::endl;
    }
    
}
//obie fukcje sprawdzaja czy statek nie bedzie kolidowal z zadnym innym statkiem  w zalezonsci czy jest on umieszczany poziomo czy pionowo
bool Gracz::sprawdz_h(int k, int y, int x, int i)
{
    if (plansza[x][y] != '*') return false;
    else
    {
        if (x + k + 1 < granica && plansza[x + k + 1][y] != '*') return false;
        else if (x + k + 1 < granica && y + 1 < granica && plansza[x + k + 1][y + 1] != '*') return false;
        else if (x + k + 1 < granica && y - 1 > -1 && plansza[x + k + 1][y - 1] != '*') return false;
        else if (y + 1 < granica && plansza[x + k][y + 1] != '*') return false;
        else if (y - 1 > -1 && plansza[x + k][y - 1] != '*') return false;
        else if (x - 1 > -1 && plansza[x - 1][y] != '*') return false;
        else if (x - 1 > -1 && y + 1 < granica && plansza[x - 1][y + 1] != '*') return false;
        else if (x - 1 > -1 && y - 1 > -1 && plansza[x - 1][y - 1] != '*') return false;
        else return true;
    }
    return true;
}

bool Gracz::sprawdz_v(int k, int y, int x, int i)
{
    if (plansza[x][y] != '*') return false;
    else
    {
        if (x + 1 < granica && plansza[x + 1][y+k] != '*') return false;
        else if (x + 1 < granica && y + k + 1 < granica && plansza[x + 1][y + k + 1] != '*') return false;
        else if (x + 1 < granica && y - 1 > -1 && plansza[x + 1][y - 1] != '*') return false;
        else if (y + k + 1 < granica && plansza[x][y + k + 1] != '*') return false;
        else if (y - 1 > -1 && plansza[x][y - 1] != '*') return false;
        else if (x - 1 > -1 && plansza[x - 1][y + k] != '*') return false;
        else if (x - 1 > -1 && y + k + 1 < granica && plansza[x - 1][y + k + 1] != '*') return false;
        else if (x - 1 > -1 && y - 1 > -1 && plansza[x - 1][y - 1] != '*') return false;
        return true;
    }
    return true;
}

void Gracz::strzal(char plansza_przeciwnika[granica][granica],int statek_vs[4])
{
    int x, y;
    int start[3] = {0,0,0};
    bool zgodnosc = false;
    std::cout << "Graczu numer " << nr << " podaj komorke na strzal" << std::endl;
    while (!zgodnosc)
    {
        zgodnosc = true;
        std::cout << "Y: ";
        std::cin >> x;
        std::cout << "X: ";
        std::cin >> y;
        if (x >= granica || y >= granica)
        {
            system("cls");
            wypisz_vs();
            std::cout << "wartosci wychodza poza granice! Wybierz inne punkty" << std::endl;
            zgodnosc = false;
        }
        else if (plansza_vs[x][y] != '*')
        {
            zgodnosc = false;
            system("cls");
            wypisz_vs();
            std::cout << "W to pole juz strzelales! Wybierz inne punkty" << std::endl;
        }
        else if (plansza_przeciwnika[x][y] != '*')
        {
            plansza_vs[x][y] = 'x';
            if (x + 1 < granica && y + 1 < granica)  plansza_vs[x + 1][y + 1] = 'o';
            if (x + 1 < granica && y - 1 >= 0)  plansza_vs[x + 1][y - 1] = 'o';
            if (x - 1 >= 0 && y - 1 >= 0)  plansza_vs[x - 1][y - 1] = 'o';
            if (x - 1 >= 0 && y + 1 < granica)  plansza_vs[x - 1][y + 1] = 'o';
            zgodnosc = false;
            system("cls");
            if(start[2] == 0)
            {
                start[0] = x;
                start[1] = y;
                start[2] = 1;
            }
            if(czy_caly_statek(plansza_przeciwnika, x, y,statek_vs))
            {
                dop_caly_statek(plansza_przeciwnika, x, y);
            }
            wypisz_vs();
            if (czy_wygrana(plansza_przeciwnika,statek_vs))
            {
                std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                zgodnosc = true;
                break;
            }
            else
            {
	            std::cout << "Trafienie! Strzelaj jeszcze raz" << std::endl;
            }
            std::cout << "ilosc statkow przeciwnika" << std::endl;
            for (int i = 0; i < 4; i++)
            {
                std::cout << "ilos statkow " << i + 2 << " masztowych: " << statek_vs[i] << std::endl;
            }
        }
        else
        {
	        plansza_vs[x][y] = 'o';
            start[2] = 0;
        }
    }

}

bool Gracz::czy_wygrana(char plansza_przeciwnika[granica][granica],int statek_vs[4])
{
    
    for(int i=0;i<4;i++)
    {
        if (statek_vs[i] != 0) return false;
    }
    return true;
}

bool Gracz::auto_h(int x, int y, int i)
{
    if (x + i + 2 > granica || y >= granica)
    {
        return  false;
    }
    else
    {
        for (int k = 0; k < i + 2; k++)
        {
            if (!sprawdz_h(k, y, x, i)) return  false;
        }
    	for (int k = 0; k < i + 2; k++)
    	{
    		plansza[x + k][y] = '0' + (i + 2);
    	}
        return true;
    }

}

bool Gracz::auto_v(int x, int y, int i)
{
    if (y + i + 2 > granica || x >= granica) {
        return false;
    }
    else
    {
        for (int k = 0; k < i + 2; k++)
        {
            if (!sprawdz_v(k, y, x, i)) return  false;
        }
    	for (int k = 0; k < i + 2; k++)
    	{
    		plansza[x][y + k] = '0' + (i + 2);
    	}
        return true;
    }
}

bool Gracz::czy_caly_statek(char plansza_przeciwnika[granica][granica],int x, int y,int statek_vs[4])
{
    int maszt = 1;
    int i;
    if ((y - 1 >= 0 && plansza_przeciwnika[x][y - 1] != '*')||(y + 1 < granica && plansza_przeciwnika[x][y + 1] != '*'))
    {
        i = 1;
        while(y-i >=0 && plansza_przeciwnika[x][y - i] != '*')
        {
            if (plansza_vs[x][y - i] == 'x')
            {
                maszt++;
            }
            else return false;
            i++;
        }
        i = 1;
        while (y + i < granica && plansza_przeciwnika[x][y + i] != '*')
        {
            if (plansza_vs[x][y + i] == 'x')
            {
	            maszt++;
            }
            else return false;
            i++;
        }
        statek_vs[maszt - 2] -= 1;
        return true;
    }
    else if ((x + 1 < granica && plansza_przeciwnika[x + 1][y] != '*') || (x - 1 >= 0 && plansza_przeciwnika[x - 1][y] != '*'))
    {
        i = 1;
        while (x - i >= 0 && plansza_przeciwnika[x - i][y] != '*')
        {
            if (plansza_vs[x-i][y] == 'x') maszt++;
            else return false;
            i++;
        }
        i = 1;
        while (x + i < granica && plansza_przeciwnika[x + i][y] != '*')
        {
            if (plansza_vs[x + i][y] == 'x') maszt++;
            else return false;
            i++;
        }
        statek_vs[maszt - 2] -= 1;
        return true;
    }
    
    
}

void Gracz::dop_caly_statek(char plansza_przeciwnika[granica][granica], int x, int y)
{
    int i;
    if ((y - 1 >= 0 && plansza_vs[x][y - 1] == 'x') || (y + 1 < granica && plansza_vs[x][y + 1] == 'x'))
    {
        i = 0;
        while (y - i >= 0 && plansza_vs[x][y - i] == 'x')
        {
            if (x + 1 < granica)plansza_vs[x + 1][y-i] = 'o';
            if (x - 1 >= 0)plansza_vs[x - 1][y-i] = 'o';

            i++;
        }
        if (y - i >= 0 && plansza_vs[x][y - i] == '*') plansza_vs[x][y - i] = 'o';
        i = 0;
        while (y + i < granica && plansza_vs[x][y + i] == 'x')
        {
            if (x + 1 < granica)plansza_vs[x + 1][y + i] = 'o';
            if (x - 1 >= 0)plansza_vs[x - 1][y + i] = 'o';
           
            i++;
        }
        if (y + i < granica && plansza_vs[x][y + i] == '*') plansza_vs[x][y + i] = 'o';
    }
    else if ((x + 1 < granica && plansza_vs[x + 1][y] == 'x') || (x - 1 >= 0 && plansza_vs[x - 1][y] == 'x'))
    {
        i = 0;
        while (x - i >= 0 && plansza_vs[x - i][y] == 'x')
        {
            if (y - 1 >= 0 && plansza_vs[x - i][y - 1] == '*') plansza_vs[x - i][y - 1] = 'o';
            if (y + 1 < granica && plansza_vs[x - i][y + 1] == '*') plansza_vs[x - i][y + 1] = 'o';
           
            i++;
        }
        if (x - i >= 0 && plansza_vs[x - i][y] == '*')plansza_vs[x - i][y] = 'o';
        i = 0;
        while (x + i < granica && plansza_vs[x + i][y] == 'x')
        {

            if (y - 1 >= 0 && plansza_vs[x + i][y - 1] == '*') plansza_vs[x + i][y - 1] = 'o';
            if (y + 1 < granica && plansza_vs[x + i][y + 1] == '*') plansza_vs[x + i][y + 1] = 'o';
           
            i++;
        }
        if (x + i <granica && plansza_vs[x + i][y] == '*')plansza_vs[x + i][y] = 'o';
    }
}



