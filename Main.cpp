#include <iostream>
#include "Functions123.h"
#include "Class4.h"

int main()
{
	
	v_alloc_table_fill_34(table_1_size);

	int** pi_table;
	b_alloc_table_2_dim(&pi_table, table_2_size_X, table_2_size_Y);
	b_dealloc_table_2_dim(&pi_table, table_2_size_X, table_2_size_Y);

	// Tworzenie 3 tabel:
	CTable* table1 = new CTable();
	table1->vPrintData();
	CTable* table2 = new CTable(*table1);
	CTable* table3 = table1->pcClone();

	// Zmiana pierwszej tabeli:
	table1->vSetName(renamed_string);
	table1->bSetNewSize(10);

	// U�ycie procedur na trzeciej tabeli:
	CTable::v_mod_tab(table3,12);	  // Przyjmuje kopie pointera do tablicy, nie mo�e zmieni� pointera, ale wskazuje on na to samo co orygina�, to mo�e zmieni�.
	CTable::v_mod_tab((*table3), 14); // Rozmiar orygina�u si� nie zmieni, za to stworzona zostanie kopia tablicy (i usuni�ta po wykonaniu metody - alokacja statyczna)

	table1->vPrintData();
	table2->vPrintData();
	table3->vPrintData();

	delete table1;
	delete table2;
	delete table3;
	//Table1 jest zainicjowana domy�lnymi parametrami,
	//Table2 i Table3 s� kopiami Table1,
	//Nast�pnie nazwa Table1 jest zmieniona, a rozmiar zwi�ksza si� do 10,
	//Table3 zachowuje nazw� kopii, ale rozmiar zwi�ksza si� do 12, (gdyby procedura przyjmuj�ca kopie go zmodyfikowa�a to by�oby to 14)
	//Table2 pozostaje niezmieniona po skopiowaniu.

	//Table1-3 alokowane s� dynamicznie, wi�c usuwane s� poleceniem delete (wywo�uj�cym destruktor przed zwolnieniem pami�ci)
	//Kopia Table3 tworzona przy podaniu kopii do procedury jest alokowana statycznie na stosie, wi�c usuwana jest ze stosu automatycznie po wykonaniu procedury.


	//Deklaracja tablicy obiekt�w CTable: (obiekty nie wska�niki wed�ug polecenia)
	CTable tableOfTables[2]; // Warto�� 2 dozwolona jest w kodzie :)
	//Tablica obiekt�w CTable alokowana jest staycznie na stosie przy u�yciu konstruktora bezparametrowego.
	//Dzi�ki deklaracji na stosie, pami�� zwalniana jest automatycznie po zako�czeniu main().
	//Podczas dealokacji wywo�ywany jest destruktor dla ka�dego obiektu w tablicy, co wida� w wyj�ciu programu.

	return 0;
}