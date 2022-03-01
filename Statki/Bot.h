#pragma once
#include "Gracz.h"
class Bot : public Gracz
{
public:

	int szukaj[6] = {0,0,0,0,0,0};
	int strzal_bot(char plansza[granica][granica], int stateki_vs[4]);
	void random_strzal(char plansza[granica][granica]);

};

