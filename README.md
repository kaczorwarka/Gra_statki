# Treść zadania projektowego
Napisz program -> gra w statki, który będzie operował na planszy o rozmiarze 30x30 i dodatkowych maksymalnych 6 liniach sterowania.  
Ilość poszczególnych rodzajów statków ma być konfigurowalna (2-5 masztów).  
Zaimplementuj mechanizmy:  
a) ręcznego rozstawiania statków (poziomo, pionowo, od danego punktu początkowego statku)   
b) automatycznego rozstawiania statków  
c) weryfikacji ułożenia statku (aut/manual) - statki nie mogą wychodzić poza plansze, ani stykać się bokami.  
Prezentacji planszy na zmianę 2 użytkownikom (przeciwnym stronom)  
# Założenia
Plansza -> początkowo jest zakryta -> za pomocą gwiazdki *  
Ułożone własne statki są reprezentowane poprzez reprezentację graficzną liczbową - ilości ich masztów np. trójmasztowiec określany jest 3-jkami.  
Obszary zatopione nieprzyjaciela określane są jako X  
Obszary typu "pudło" określane są jako o  
# Tryby
a) możliwość gry dla 2 osób (PvP)  
b) możliwość gry 1 osoby z komputerem (PvPC)  
c) możliwość gry komputera (obserwujemy ich ruchy) (PCvsPC)  
