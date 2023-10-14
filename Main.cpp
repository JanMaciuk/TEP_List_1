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

	// U¿ycie procedur na trzeciej tabeli:
	CTable::v_mod_tab(table3,12);	  // Przyjmuje kopie pointera do tablicy, nie mo¿e zmieniæ pointera, ale wskazuje on na to samo co orygina³, to mo¿e zmieniæ.
	CTable::v_mod_tab((*table3), 14); // Rozmiar orygina³u siê nie zmieni, za to stworzona zostanie kopia tablicy (i usuniêta po wykonaniu metody - alokacja statyczna)

	table1->vPrintData();
	table2->vPrintData();
	table3->vPrintData();

	delete table1;
	delete table2;
	delete table3;
	//Table1 jest zainicjowana domyœlnymi parametrami,
	//Table2 i Table3 s¹ kopiami Table1,
	//Nastêpnie nazwa Table1 jest zmieniona, a rozmiar zwiêksza siê do 10,
	//Table3 zachowuje nazwê kopii, ale rozmiar zwiêksza siê do 12, (gdyby procedura przyjmuj¹ca kopie go zmodyfikowa³a to by³oby to 14)
	//Table2 pozostaje niezmieniona po skopiowaniu.

	//Table1-3 alokowane s¹ dynamicznie, wiêc usuwane s¹ poleceniem delete (wywo³uj¹cym destruktor przed zwolnieniem pamiêci)
	//Kopia Table3 tworzona przy podaniu kopii do procedury jest alokowana statycznie na stosie, wiêc usuwana jest ze stosu automatycznie po wykonaniu procedury.


	//Deklaracja tablicy obiektów CTable: (obiekty nie wskaŸniki wed³ug polecenia)
	CTable tableOfTables[2]; // Wartoœæ 2 dozwolona jest w kodzie :)
	//Tablica obiektów CTable alokowana jest staycznie na stosie przy u¿yciu konstruktora bezparametrowego.
	//Dziêki deklaracji na stosie, pamiêæ zwalniana jest automatycznie po zakoñczeniu main().
	//Podczas dealokacji wywo³ywany jest destruktor dla ka¿dego obiektu w tablicy, co widaæ w wyjœciu programu.

	return 0;
}