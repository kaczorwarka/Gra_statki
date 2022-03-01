#pragma once
class Gracz
{
public:
	static const int granica = 10;
	int nr;
	int statek[4];
	char plansza[granica][granica];
	char plansza_vs[granica][granica];
	void dodaj_recznie();
	void dodaj_auto();
	void wypelnij();
	void wypisz_twoja();
	void wypisz_vs();
	bool sprawdz_h(int k,int y,int x,int i);
	bool sprawdz_v(int k, int y, int x, int i);
	void strzal(char plansza[granica][granica],int statek_vs[4]);
	bool czy_wygrana(char plansza[granica][granica],int statek_vs[4]);
	bool auto_h(int x, int y, int i);
	bool auto_v(int x, int y, int i);
	bool czy_caly_statek(char plansza[granica][granica],int x, int y,int statek_vs[4]);
	void dop_caly_statek(char plansza[granica][granica], int x, int y);

	friend class Bot;
};


