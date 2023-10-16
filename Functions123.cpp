

#include <iostream>
#include "Functions123.h"


void v_alloc_table_fill_34(int iSize) 
{
	//Weryfikacja czy zadany rozmiar tablicy ma sens
	if (iSize < 1) 
	{
		std::cout << msg_err_table_size;
		return;
	}
	//Alokacja tablicy o rozmiarze iSize:
	int* table_1;				
	table_1 = new int[iSize];	

	// Wype�nienie tablicy zadan� liczb�:
	for (int i = 0; i < iSize; i++)
	{
		table_1[i] = table_1_int_value;
	}


	//Wypisanie stanu tablicy:
	cout << msg_table_allocated << iSize <<new_line;
	cout << msg_table_filled << table_1_int_value << new_line;
	cout << msg_printing_table;
	for (int i = 0; i < iSize; i++)
	{
		cout << table_1[i] << new_line;
	}


	// Dealokacja tablicy
	delete[] table_1;
	std::cout <<msg_succesfull_execution << f_name_alloc_table << new_line << new_line;
}

bool b_alloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY) {
	//Weryfikacja wymiar�w
	if (iSizeX < 1 || iSizeY < 1) {
		std::cout << msg_err_table_size;
		return false;
	}

	//Alokacja listy wska�nik�w na rz�dy tablicy
	*piTable = new int*[iSizeY]; 
	if (*piTable == NULL) return false;  // Gdyby z jakiego� powodu alokacja si� nie powiod�a (b��d pami�ci?), informujemy o tym i ko�czymy funkcj�.

	//Alokacja samej listy, ka�da warto�� piTable wskazuje na rz�d tablicy
	for (int i = 0; i < iSizeY; i++)
	{
		(*piTable)[i] = new int[iSizeX];
	}
	

	std::cout << msg_succesfull_execution << f_name_alloc_table_2_dim << new_line << new_line;
	return true;

}

bool b_dealloc_table_2_dim(int ***piTable, int iSizeX, int iSizeY) {

	//Weryfikacja wymiar�w
	if (iSizeX < 1 || iSizeY < 1) {
		std::cout << msg_err_table_size;
		if (*piTable != NULL) //nullptr jest niezgodne z C++98, wi�c u�ywam NULL
		{
			delete[] *piTable; // I tak usuwam pod podanym adresem, lepiej tak ni� zostawi� w pami�ci co� co oczekujeny �e zosta�o usuni�te.
		}
		return false;
	}
	//Sprawdzenie czy tablica zosta�a zaalokowana
	if (*piTable == NULL) {
		std::cout << msg_err_not_allocated;
		return false;
	}

	for (int i = 0; i < iSizeY; i++)
	{
		if ((*piTable)[i] != NULL) delete[] (*piTable)[i];
	}
	delete[] *piTable;

	std::cout << msg_succesfull_execution << f_name_dealloc_table_2_dim << new_line << new_line;
	return true;
}





