#include "Bot.h"
#include "Gracz.h"
#include <iostream>
#include <stdlib.h>
#include <Windows.h>

int Bot::strzal_bot(char plansza_przeciwnika[granica][granica],int statek_vs[4])
{
    
    int x, y;
   
    if (szukaj[4]==0)
    {
        //strzal bota w losowe miejsce
        random_strzal(plansza_przeciwnika);
    }
    else
    {
        x = szukaj[0];
        y = szukaj[1];
        if (szukaj[4]==1)
        {
            if (y - 1 >= 0 && plansza_vs[x][y - 1] == '*')
            {
                if (plansza_przeciwnika[x][y - 1] != '*')
                {
                    plansza_vs[x][y - 1] = 'x';
                    szukaj[5] = 1;
                    y = y - 1;
                    if (x + 1 < granica && y + 1 < granica)  plansza_vs[x + 1][y + 1] = 'o';
                    if (x + 1 < granica && y - 1 >= 0)  plansza_vs[x + 1][y - 1] = 'o';
                    if (x - 1 >= 0 && y - 1 >= 0)  plansza_vs[x - 1][y - 1] = 'o';
                    if (x - 1 >= 0 && y + 1 < granica)  plansza_vs[x - 1][y + 1] = 'o';
                    if (czy_caly_statek(plansza_przeciwnika, x, y, statek_vs))
                    {
                        dop_caly_statek(plansza_przeciwnika, x, y);
                        if (czy_wygrana(plansza_przeciwnika, statek_vs))
                        {
                            std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                            return 0;
                        }
                        else
                        {
                            szukaj[4] = 0;
                            wypisz_vs();
                            std::cout << "ilosc statkow przeciwnika" << std::endl;
                            for (int i = 0; i < 4; i++)
                            {
                                std::cout << "ilos statkow " << i + 2 << " masztowych: " << statek_vs[i] << std::endl;
                            }
                            //Sleep(1000);
                            system("pause");
                            system("cls");
                            random_strzal(plansza_przeciwnika);
                            return 0;
                        }
                    }
                    szukaj[0] = x;
                    szukaj[1] = y;
                    szukaj[4] = 2;
                }
                else
                {
                    plansza_vs[x][y - 1] = 'o';
                    szukaj[5] = 0;
                }
            }

            else if (y + 1 < granica && plansza_vs[x][y + 1] == '*')
            {
                if (plansza_przeciwnika[x][y + 1] != '*')
                {
                    plansza_vs[x][y + 1] = 'x';
                    szukaj[5] = 1;
                    y = y + 1;
                    if (x + 1 < granica && y + 1 < granica)  plansza_vs[x + 1][y + 1] = 'o';
                    if (x + 1 < granica && y - 1 >= 0)  plansza_vs[x + 1][y - 1] = 'o';
                    if (x - 1 >= 0 && y - 1 >= 0)  plansza_vs[x - 1][y - 1] = 'o';
                    if (x - 1 >= 0 && y + 1 < granica)  plansza_vs[x - 1][y + 1] = 'o';
                    if (czy_caly_statek(plansza_przeciwnika, x, y, statek_vs))
                    {
                        dop_caly_statek(plansza_przeciwnika, x, y);
                        if (czy_wygrana(plansza_przeciwnika, statek_vs))
                        {
                            std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                            return 0;
                        }
                        else
                        {
                            szukaj[4] = 0;
                            wypisz_vs();
                            std::cout << "ilosc statkow przeciwnika" << std::endl;
                            for (int i = 0; i < 4; i++)
                            {
                                std::cout << "ilos statkow " << i + 2 << " masztowych: " << statek_vs[i] << std::endl;
                            }
                            //Sleep(1000);
                            system("pause");
                            system("cls");
                            random_strzal(plansza_przeciwnika);
                            return 0;
                        }
                    }
                    if (czy_wygrana(plansza_przeciwnika, statek_vs))
                    {
                        std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                    }
                    szukaj[0] = x;
                    szukaj[1] = y;
                    szukaj[4] = 2;
                }
                else
                {
                    plansza_vs[x][y + 1] = 'o';
                    szukaj[5] = 0;
                }
            }
            else if (x + 1 < granica && plansza_vs[x + 1][y] == '*')
            {
                if (plansza_przeciwnika[x + 1][y] != '*')
                {
                    plansza_vs[x + 1][y] = 'x';
                    szukaj[5] = 1;
                    x = x + 1;
                    if (x + 1 < granica && y + 1 < granica)  plansza_vs[x + 1][y + 1] = 'o';
                    if (x + 1 < granica && y - 1 >= 0)  plansza_vs[x + 1][y - 1] = 'o';
                    if (x - 1 >= 0 && y - 1 >= 0)  plansza_vs[x - 1][y - 1] = 'o';
                    if (x - 1 >= 0 && y + 1 < granica)  plansza_vs[x - 1][y + 1] = 'o';
                    if (czy_caly_statek(plansza_przeciwnika, x, y, statek_vs))
                    {
                        dop_caly_statek(plansza_przeciwnika, x, y);
                        if (czy_wygrana(plansza_przeciwnika, statek_vs))
                        {
                            std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                            return 0;
                        }
                        else
                        {
                            szukaj[4] = 0;
                            wypisz_vs();
                            std::cout << "ilosc statkow przeciwnika" << std::endl;
                            for (int i = 0; i < 4; i++)
                            {
                                std::cout << "ilos statkow " << i + 2 << " masztowych: " << statek_vs[i] << std::endl;
                            }
                            //Sleep(1000);
                            system("pause");
                            system("cls");
                            random_strzal(plansza_przeciwnika);
                            return 0;
                        }
                    }
                    if (czy_wygrana(plansza_przeciwnika, statek_vs))
                    {
                        std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                    }
                    szukaj[0] = x;
                    szukaj[1] = y;
                    szukaj[4] = 3;
                }
                else
                {
                    plansza_vs[x + 1][y] = 'o';
                    szukaj[5] = 0;
                }
            }
            else if (x - 1 >= 0 && plansza_vs[x - 1][y] == '*')
            {
                if (plansza_przeciwnika[x - 1][y] != '*')
                {
                    plansza_vs[x - 1][y] = 'x';
                    szukaj[5] = 1;
                    x = x - 1;
                    if (x + 1 < granica && y + 1 < granica)  plansza_vs[x + 1][y + 1] = 'o';
                    if (x + 1 < granica && y - 1 >= 0)  plansza_vs[x + 1][y - 1] = 'o';
                    if (x - 1 >= 0 && y - 1 >= 0)  plansza_vs[x - 1][y - 1] = 'o';
                    if (x - 1 >= 0 && y + 1 < granica)  plansza_vs[x - 1][y + 1] = 'o';
                    if (czy_caly_statek(plansza_przeciwnika, x, y, statek_vs))
                    {
                        dop_caly_statek(plansza_przeciwnika, x, y);
                        if (czy_wygrana(plansza_przeciwnika, statek_vs))
                        {
                            std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                            return 0;
                        }
                        else
                        {
                            szukaj[4] = 0;
                            wypisz_vs();
                            std::cout << "ilosc statkow przeciwnika" << std::endl;
                            for (int i = 0; i < 4; i++)
                            {
                                std::cout << "ilos statkow " << i + 2 << " masztowych: " << statek_vs[i] << std::endl;
                            }
                            //Sleep(1000);
                            system("pause");
                            system("cls");
                            random_strzal(plansza_przeciwnika);
                            return 0;
                        }
                    }
                    if (czy_wygrana(plansza_przeciwnika, statek_vs))
                    {
                        std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                    }
                    szukaj[0] = x;
                    szukaj[1] = y;
                    szukaj[4] = 3;
                }
                else
                {
                    plansza_vs[x - 1][y] = 'o';
                    szukaj[5] = 0;

                }
            }
            else
            {
	            szukaj[2] = 0;
                 random_strzal(plansza_przeciwnika);
            }
        }
        //lewe lub prawe pole moze byc statkiem
        else if(szukaj[4] == 2)
        {
	        if (y + 1 < granica && plansza_vs[x][y + 1] == '*')
            {
                if (plansza_przeciwnika[x][y + 1] != '*')
                {
                    plansza_vs[x][y + 1] = 'x';
                    szukaj[5] = 1;
                    y = y + 1;
                    if (x + 1 < granica && y + 1 < granica)  plansza_vs[x + 1][y + 1] = 'o';
                    if (x + 1 < granica && y - 1 >= 0)  plansza_vs[x + 1][y - 1] = 'o';
                    if (x - 1 >= 0 && y - 1 >= 0)  plansza_vs[x - 1][y - 1] = 'o';
                    if (x - 1 >= 0 && y + 1 < granica)  plansza_vs[x - 1][y + 1] = 'o';
                    if (czy_caly_statek(plansza_przeciwnika, x, y, statek_vs))
                    {
                        dop_caly_statek(plansza_przeciwnika, x, y);
                        if (czy_wygrana(plansza_przeciwnika, statek_vs))
                        {
                            std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                            return 0;
                        }
                        else
                        {
                            szukaj[4] = 0;
                            wypisz_vs();
                            std::cout << "ilosc statkow przeciwnika" << std::endl;
                            for (int i = 0; i < 4; i++)
                            {
                                std::cout << "ilos statkow " << i + 2 << " masztowych: " << statek_vs[i] << std::endl;
                            }
                            //Sleep(1000);
                            system("pause");
                            system("cls");
                            random_strzal(plansza_przeciwnika);
                            return 0;
                        }
                    }
                    if (czy_wygrana(plansza_przeciwnika, statek_vs))
                    {
                        std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                    }
                    szukaj[0] = x;
                    szukaj[1] = y;
                }
                else
                {
                    plansza_vs[x][y + 1] = 'o';
                    szukaj[5] = 0;
                    
                }
            }
            else if (y - 1 >= 0 && plansza_vs[x][y-1] == '*')
            {
                if (plansza_przeciwnika[x][y - 1] != '*')
                {
                    plansza_vs[x][y-1] = 'x';
                    szukaj[5] = 1;
                    y = y - 1;
                    if (x + 1 < granica && y + 1 < granica)  plansza_vs[x + 1][y + 1] = 'o';
                    if (x + 1 < granica && y - 1 >= 0)  plansza_vs[x + 1][y - 1] = 'o';
                    if (x - 1 >= 0 && y - 1 >= 0)  plansza_vs[x - 1][y - 1] = 'o';
                    if (x - 1 >= 0 && y + 1 < granica)  plansza_vs[x - 1][y + 1] = 'o';
                    if (czy_caly_statek(plansza_przeciwnika, x, y, statek_vs))
                    {
                        dop_caly_statek(plansza_przeciwnika, x, y);
                        if (czy_wygrana(plansza_przeciwnika, statek_vs))
                        {
                            std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                            return 0;
                        }
                        else
                        {
                            szukaj[4] = 0;
                            wypisz_vs();
                            std::cout << "ilosc statkow przeciwnika" << std::endl;
                            for (int i = 0; i < 4; i++)
                            {
                                std::cout << "ilos statkow " << i + 2 << " masztowych: " << statek_vs[i] << std::endl;
                            }
                            //Sleep(1000);
                            system("pause");
                            system("cls");
                            random_strzal(plansza_przeciwnika);
                            return 0;
                        }
                    }
                    if (czy_wygrana(plansza_przeciwnika, statek_vs))
                    {
                        std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                    }
                    szukaj[0] = x;
                    szukaj[1] = y;
                }
                else
                {
                    plansza_vs[x][y-1] = 'o';
                    szukaj[5] = 0;
                }
            }
            else
            {
	            szukaj[4] = 4;
                x = szukaj[2];
                y = szukaj[3];
                if (y + 1 < granica && plansza_vs[x][y + 1] == '*')
                {
                    if (plansza_przeciwnika[x][y + 1] != '*')
                    {
                        plansza_vs[x][y + 1] = 'x';
                        szukaj[5] = 1;
                        y = y + 1;
                        if (x + 1 < granica && y + 1 < granica)  plansza_vs[x + 1][y + 1] = 'o';
                        if (x + 1 < granica && y - 1 >= 0)  plansza_vs[x + 1][y - 1] = 'o';
                        if (x - 1 >= 0 && y - 1 >= 0)  plansza_vs[x - 1][y - 1] = 'o';
                        if (x - 1 >= 0 && y + 1 < granica)  plansza_vs[x - 1][y + 1] = 'o';
                        if (czy_caly_statek(plansza_przeciwnika, x, y, statek_vs))
                        {
                            dop_caly_statek(plansza_przeciwnika, x, y);
                            if (czy_wygrana(plansza_przeciwnika, statek_vs))
                            {
                                std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                                return 0;
                            }
                            else
                            {
                                szukaj[4] = 0;
                                wypisz_vs();
                                std::cout << "ilosc statkow przeciwnika" << std::endl;
                                for (int i = 0; i < 4; i++)
                                {
                                    std::cout << "ilos statkow " << i + 2 << " masztowych: " << statek_vs[i] << std::endl;
                                }
                                //Sleep(1000);
                                system("pause");
                                system("cls");
                                random_strzal(plansza_przeciwnika);
                                return 0;
                            }
                        }
                        if (czy_wygrana(plansza_przeciwnika, statek_vs))
                        {
                            std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                        }
                        szukaj[2] = x;
                        szukaj[3] = y;
                    }
                    else
                    {
                        plansza_vs[x][y + 1] = 'o';
                        szukaj[5] = 0;
                    }
                }
                else if (y - 1 >= 0 && plansza_vs[x][y - 1] == '*')
                {
                    if (plansza_przeciwnika[x][y - 1] != '*')
                    {
                        plansza_vs[x][y - 1] = 'x';
                        szukaj[5] = 1;
                        y = y - 1;
                        if (x + 1 < granica && y + 1 < granica)  plansza_vs[x + 1][y + 1] = 'o';
                        if (x + 1 < granica && y - 1 >= 0)  plansza_vs[x + 1][y - 1] = 'o';
                        if (x - 1 >= 0 && y - 1 >= 0)  plansza_vs[x - 1][y - 1] = 'o';
                        if (x - 1 >= 0 && y + 1 < granica)  plansza_vs[x - 1][y + 1] = 'o';
                        if (czy_caly_statek(plansza_przeciwnika, x, y, statek_vs))
                        {
                            dop_caly_statek(plansza_przeciwnika, x, y);
                            if (czy_wygrana(plansza_przeciwnika, statek_vs))
                            {
                                std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                                return 0;
                            }
                            else
                            {
                                szukaj[4] = 0;
                                wypisz_vs();
                                std::cout << "ilosc statkow przeciwnika" << std::endl;
                                for (int i = 0; i < 4; i++)
                                {
                                    std::cout << "ilos statkow " << i + 2 << " masztowych: " << statek_vs[i] << std::endl;
                                }
                                //Sleep(1000);
                                system("pause");
                                system("cls");
                                random_strzal(plansza_przeciwnika);
                                return 0;
                            }
                        }
                        if (czy_wygrana(plansza_przeciwnika, statek_vs))
                        {
                            std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                        }
                        szukaj[2] = x;
                        szukaj[3] = y;
                    }
                    else
                    {
                        plansza_vs[x][y - 1] = 'o';
                        szukaj[5] = 0;
                    }
                }
                else
                {
                    szukaj[4] = 0;
                	random_strzal(plansza_przeciwnika);
                }
            }

        }
        else if (szukaj[4]==4)
        {
			x = szukaj[2];
            y = szukaj[3];
			if (y + 1 < granica && plansza_vs[x][y+1] == '*')
			{
				if (plansza_przeciwnika[x][y + 1] != '*')
				{
					plansza_vs[x][y+1] = 'x';
                    szukaj[5] = 1;
					y = y + 1;
                    if (x + 1 < granica && y + 1 < granica)  plansza_vs[x + 1][y + 1] = 'o';
                    if (x + 1 < granica && y - 1 >= 0)  plansza_vs[x + 1][y - 1] = 'o';
                    if (x - 1 >= 0 && y - 1 >= 0)  plansza_vs[x - 1][y - 1] = 'o';
                    if (x - 1 >= 0 && y + 1 < granica)  plansza_vs[x - 1][y + 1] = 'o';
                    if (czy_caly_statek(plansza_przeciwnika, x, y, statek_vs))
                    {
                        dop_caly_statek(plansza_przeciwnika, x, y);
                        if (czy_wygrana(plansza_przeciwnika, statek_vs))
                        {
                            std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                            return 0;
                        }
                        else
                        {
                            szukaj[4] = 0;
                            wypisz_vs();
                            std::cout << "ilosc statkow przeciwnika" << std::endl;
                            for (int i = 0; i < 4; i++)
                            {
                                std::cout << "ilos statkow " << i + 2 << " masztowych: " << statek_vs[i] << std::endl;
                            }
                            //Sleep(1000);
                            system("pause");
                            system("cls");
                            random_strzal(plansza_przeciwnika);
                            return 0;
                        }
                    }
                    if (czy_wygrana(plansza_przeciwnika, statek_vs))
                    {
                        std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                    }
					szukaj[2] = x;
					szukaj[3] = y;
				}
				else
				{
					plansza_vs[x][y+1] = 'o';
                    szukaj[5] = 0;
				}
			}
			else if (y - 1 >= 0 && plansza_vs[x][y-1] == '*')
			{
				if (plansza_przeciwnika[x][y-1] != '*')
				{
					plansza_vs[x][y-1] = 'x';
                    szukaj[5] = 1;
					y = y - 1;
                    if (x + 1 < granica && y + 1 < granica)  plansza_vs[x + 1][y + 1] = 'o';
                    if (x + 1 < granica && y - 1 >= 0)  plansza_vs[x + 1][y - 1] = 'o';
                    if (x - 1 >= 0 && y - 1 >= 0)  plansza_vs[x - 1][y - 1] = 'o';
                    if (x - 1 >= 0 && y + 1 < granica)  plansza_vs[x - 1][y + 1] = 'o';
                    if (czy_caly_statek(plansza_przeciwnika, x, y, statek_vs))
                    {
                        dop_caly_statek(plansza_przeciwnika, x, y);
                        if (czy_wygrana(plansza_przeciwnika, statek_vs))
                        {
                            std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                            return 0;
                        }
                        else
                        {
                            szukaj[4] = 0;
                            wypisz_vs();
                            std::cout << "ilosc statkow przeciwnika" << std::endl;
                            for (int i = 0; i < 4; i++)
                            {
                                std::cout << "ilos statkow " << i + 2 << " masztowych: " << statek_vs[i] << std::endl;
                            }
                            //Sleep(1000);
                            system("pause");
                            system("cls");
                            random_strzal(plansza_przeciwnika);
                            return 0;
                        }
                    }
                    if (czy_wygrana(plansza_przeciwnika, statek_vs))
                    {
                        std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                    }
					szukaj[2] = x;
					szukaj[3] = y;
				}
				else
				{
					plansza_vs[x][y-1] = 'o';
                    szukaj[5] = 0;
				}
			}
            else
            {
	            szukaj[4] = 0;
            	random_strzal(plansza_przeciwnika);

            }
        }
        //gorne lub dolne pole moze byc statkiem
        else if (szukaj[4] == 3)
        {
            if (x - 1 >= 0 && plansza_vs[x-1][y] == '*')
            {
                if (plansza_przeciwnika[x-1][y] != '*')
                {
                    plansza_vs[x-1][y] = 'x';
                    szukaj[5] = 1;
                    x = x - 1;
                    if (x + 1 < granica && y + 1 < granica)  plansza_vs[x + 1][y + 1] = 'o';
                    if (x + 1 < granica && y - 1 >= 0)  plansza_vs[x + 1][y - 1] = 'o';
                    if (x - 1 >= 0 && y - 1 >= 0)  plansza_vs[x - 1][y - 1] = 'o';
                    if (x - 1 >= 0 && y + 1 < granica)  plansza_vs[x - 1][y + 1] = 'o';
                    if (czy_caly_statek(plansza_przeciwnika, x, y, statek_vs))
                    {
						dop_caly_statek(plansza_przeciwnika, x, y);
                        if (czy_wygrana(plansza_przeciwnika, statek_vs))
                        {
                            std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                            return 0;
                        }
                        else
                        {
                            szukaj[4] = 0;
                            wypisz_vs();
                            std::cout << "ilosc statkow przeciwnika" << std::endl;
                            for (int i = 0; i < 4; i++)
                            {
                                std::cout << "ilos statkow " << i + 2 << " masztowych: " << statek_vs[i] << std::endl;
                            }
                            //Sleep(1000);
                            system("pause");
                            system("cls");
                            random_strzal(plansza_przeciwnika);
                            return 0;
                        }
                    }
                    if (czy_wygrana(plansza_przeciwnika, statek_vs))
                    {
                        std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                    }
                    szukaj[0] = x;
                    szukaj[1] = y;
                }
                else
                {
                    plansza_vs[x-1][y] = 'o';
                    szukaj[5] = 0;
                }
            }
            else if (x + 1 < granica && plansza_vs[x+1][y] == '*')
            {
                if (plansza_przeciwnika[x+1][y] != '*')
                {
                    plansza_vs[x+1][y] = 'x';
                    szukaj[5] = 1;
                    x = x + 1;
                    if (x + 1 < granica && y + 1 < granica)  plansza_vs[x + 1][y + 1] = 'o';
                    if (x + 1 < granica && y - 1 >= 0)  plansza_vs[x + 1][y - 1] = 'o';
                    if (x - 1 >= 0 && y - 1 >= 0)  plansza_vs[x - 1][y - 1] = 'o';
                    if (x - 1 >= 0 && y + 1 < granica)  plansza_vs[x - 1][y + 1] = 'o';
                    if (czy_caly_statek(plansza_przeciwnika, x, y, statek_vs))
                    {
                        dop_caly_statek(plansza_przeciwnika, x, y);
                        if (czy_wygrana(plansza_przeciwnika, statek_vs))
                        {
                            std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                            return 0;
                        }
                        else
                        {
                            szukaj[4] = 0;
                            wypisz_vs();
                            std::cout << "ilosc statkow przeciwnika" << std::endl;
                            for (int i = 0; i < 4; i++)
                            {
                                std::cout << "ilos statkow " << i + 2 << " masztowych: " << statek_vs[i] << std::endl;
                            }
                            //Sleep(1000);
                            system("pause");
                            system("cls");
                            random_strzal(plansza_przeciwnika);
                            return 0;
                        }
                    }
                    if (czy_wygrana(plansza_przeciwnika, statek_vs))
                    {
                        std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                    }
                    szukaj[0] = x;
                    szukaj[1] = y;
                }
                else
                {
                    plansza_vs[x+1][y] = 'o';
                    szukaj[5] = 0;
                }
            }
            else
            {
	            szukaj[4] = 5;
                x = szukaj[2];
                y = szukaj[3];
                if (x - 1 >= 0 && plansza_vs[x - 1][y] == '*')
                {
                    if (plansza_przeciwnika[x - 1][y] != '*')
                    {
                        plansza_vs[x - 1][y] = 'x';
                        szukaj[5] = 1;
                        x = x - 1;
                        if (x + 1 < granica && y + 1 < granica)  plansza_vs[x + 1][y + 1] = 'o';
                        if (x + 1 < granica && y - 1 >= 0)  plansza_vs[x + 1][y - 1] = 'o';
                        if (x - 1 >= 0 && y - 1 >= 0)  plansza_vs[x - 1][y - 1] = 'o';
                        if (x - 1 >= 0 && y + 1 < granica)  plansza_vs[x - 1][y + 1] = 'o';
                        if (czy_caly_statek(plansza_przeciwnika, x, y, statek_vs))
                        {
							dop_caly_statek(plansza_przeciwnika, x, y);
                            if (czy_wygrana(plansza_przeciwnika, statek_vs))
                            {
                                std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                                return 0;
                            }
                            else
                            {
                                szukaj[4] = 0;
                                wypisz_vs();
                                std::cout << "ilosc statkow przeciwnika" << std::endl;
                                for (int i = 0; i < 4; i++)
                                {
                                    std::cout << "ilos statkow " << i + 2 << " masztowych: " << statek_vs[i] << std::endl;
                                }
                                //Sleep(1000);
                                system("pause");
                                system("cls");
                                random_strzal(plansza_przeciwnika);
                                return 0;
                            }
                        }
                        if (czy_wygrana(plansza_przeciwnika, statek_vs))
                        {
                            std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                        }
                        szukaj[2] = x;
                        szukaj[3] = y;
                    }
                    else
                    {
                        plansza_vs[x - 1][y] = 'o';
                        szukaj[5] = 0;
                    }
                }
                else if (x + 1 < granica && plansza_vs[x + 1][y] == '*')
                {
                    if (plansza_przeciwnika[x + 1][y] != '*')
                    {
                        plansza_vs[x + 1][y] = 'x';
                        szukaj[5] = 1;
                        x = x + 1;
                        if (x + 1 < granica && y + 1 < granica)  plansza_vs[x + 1][y + 1] = 'o';
                        if (x + 1 < granica && y - 1 >= 0)  plansza_vs[x + 1][y - 1] = 'o';
                        if (x - 1 >= 0 && y - 1 >= 0)  plansza_vs[x - 1][y - 1] = 'o';
                        if (x - 1 >= 0 && y + 1 < granica)  plansza_vs[x - 1][y + 1] = 'o';
                        if (czy_caly_statek(plansza_przeciwnika, x, y, statek_vs))
                        {
                            dop_caly_statek(plansza_przeciwnika, x, y);
                            if (czy_wygrana(plansza_przeciwnika, statek_vs))
                            {
                                std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                                return 0;
                            }
                            else
                            {
                                szukaj[4] = 0;
                                wypisz_vs();
                                std::cout << "ilosc statkow przeciwnika" << std::endl;
                                for (int i = 0; i < 4; i++)
                                {
                                    std::cout << "ilos statkow " << i + 2 << " masztowych: " << statek_vs[i] << std::endl;
                                }
                                //Sleep(1000);
                                system("pause");
                                system("cls");
                                random_strzal(plansza_przeciwnika);
                                return 0;
                            }
                        }
                        if (czy_wygrana(plansza_przeciwnika, statek_vs))
                        {
                            std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                        }
                        szukaj[2] = x;
                        szukaj[3] = y;
                        
                    }
                    else
                    {
                        plansza_vs[x + 1][y] = 'o';
                        szukaj[5] = 0;
                    }
                }
                else
                {
                    szukaj[4] = 0;
                    
                    random_strzal(plansza_przeciwnika);
                }
            }
        }
        else if(szukaj[4]==5)
        {
			x = szukaj[2];
			y = szukaj[3];
            if (x - 1 >= 0 && plansza_vs[x - 1][y] == '*')
            {
                if (plansza_przeciwnika[x - 1][y] != '*')
                {
                    plansza_vs[x - 1][y] = 'x';
                    szukaj[5] = 1;
                    x = x - 1;
                    if (x + 1 < granica && y + 1 < granica)  plansza_vs[x + 1][y + 1] = 'o';
                    if (x + 1 < granica && y - 1 >= 0)  plansza_vs[x + 1][y - 1] = 'o';
                    if (x - 1 >= 0 && y - 1 >= 0)  plansza_vs[x - 1][y - 1] = 'o';
                    if (x - 1 >= 0 && y + 1 < granica)  plansza_vs[x - 1][y + 1] = 'o';
                    if (czy_caly_statek(plansza_przeciwnika, x, y, statek_vs))
                    {
                        dop_caly_statek(plansza_przeciwnika, x, y);
                        if (czy_wygrana(plansza_przeciwnika, statek_vs))
                        {
                            std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                            return 0;
                        }
                        else
                        {
                            szukaj[4] = 0;
                            wypisz_vs();
                            std::cout << "ilosc statkow przeciwnika" << std::endl;
                            for (int i = 0; i < 4; i++)
                            {
                                std::cout << "ilos statkow " << i + 2 << " masztowych: " << statek_vs[i] << std::endl;
                            }
                            //Sleep(1000);
                            system("pause");
                            system("cls");
                            random_strzal(plansza_przeciwnika);
                            return 0;
                        }
                    }
                    if (czy_wygrana(plansza_przeciwnika, statek_vs))
                    {
                        std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                    }
                    szukaj[2] = x;
                    szukaj[3] = y;
                }
                else
                {
                    plansza_vs[x - 1][y] = 'o';
                    szukaj[5] = 0;
                    
                }
            }
            else if (x + 1 < granica && plansza_vs[x + 1][y] == '*')
            {
                if (plansza_przeciwnika[x + 1][y] != '*')
                {
                    plansza_vs[x + 1][y] = 'x';
                    szukaj[5] = 1;
                    x = x + 1;
                    if (x + 1 < granica && y + 1 < granica)  plansza_vs[x + 1][y + 1] = 'o';
                    if (x + 1 < granica && y - 1 >= 0)  plansza_vs[x + 1][y - 1] = 'o';
                    if (x - 1 >= 0 && y - 1 >= 0)  plansza_vs[x - 1][y - 1] = 'o';
                    if (x - 1 >= 0 && y + 1 < granica)  plansza_vs[x - 1][y + 1] = 'o';
                    if (czy_caly_statek(plansza_przeciwnika, x, y, statek_vs))
                    {
                        dop_caly_statek(plansza_przeciwnika, x, y);
                        if (czy_wygrana(plansza_przeciwnika, statek_vs))
                        {
                            std::cout << "Graczu numer " << nr << " WYGRALES" << std::endl;
                            return 0;
                        }
                        else
                        {
                            szukaj[4] = 0;
                            wypisz_vs();
                            std::cout << "ilosc statkow przeciwnika" << std::endl;
                            for (int i = 0; i < 4; i++)
                            {
                                std::cout << "ilos statkow " << i + 2 << " masztowych: " << statek_vs[i] << std::endl;
                            }
                            //Sleep(1000);
                            system("pause");
                            system("cls");
                            random_strzal(plansza_przeciwnika);
                            return 0;
                        }
                    }

                    szukaj[2] = x;
                    szukaj[3] = y;
                }
                else
                {
                    plansza_vs[x + 1][y] = 'o';
                    szukaj[5] = 0;
                }
            }
            else
            {
                szukaj[4] = 0;
            	random_strzal(plansza_przeciwnika);
            }
        }
    }
    return 0;
}

void Bot::random_strzal(char plansza_przeciwnika[granica][granica])
{
    int x, y;
    while (1)
    {
        x = rand() % granica;
        y = rand() % granica;
        if (plansza_vs[x][y] != 'o' and plansza_vs[x][y] != 'x') break;
    }
    if (plansza_przeciwnika[x][y] != '*')
    {
        plansza_vs[x][y] = 'x';
        szukaj[5] = 1;
        if (x + 1 < granica && y + 1 < granica)  plansza_vs[x + 1][y + 1] = 'o';
        if (x + 1 < granica && y - 1 >= 0)  plansza_vs[x + 1][y - 1] = 'o';
        if (x - 1 >= 0 && y - 1 >= 0)  plansza_vs[x - 1][y - 1] = 'o';
        if (x - 1 >= 0 && y + 1 < granica)  plansza_vs[x - 1][y + 1] = 'o';
        //czy_caly_statek(plansza_przeciwnika, x, y, statek_vs);
        szukaj[0] = x;
        szukaj[1] = y;
        szukaj[2] = x;
    	szukaj[3] = y;
        szukaj[4] = 1;
    }
    else
    {
	    plansza_vs[x][y] = 'o';
        szukaj[5] = 0;
    }
}


