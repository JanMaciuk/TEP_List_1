

#include <iostream>
#include "TEP_List_1.h"

; using namespace std;

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
	std::cout << msg_table_allocated << iSize <<new_line;
	std::cout << msg_table_filled << table_1[0] << new_line;
	//Pobieram warto�� z tablicy nie ze sta�ej aby zweryfikowa� poprawne wype�nienie
	


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

	//Alokacja samej listy, ka�da warto�� piTable wskazuje na rz�d tablicy
	for (int i = 0; i < iSizeY; i++)
	{
		(*piTable)[i] = new int[iSizeX];
	}
	

	std::cout << msg_succesfull_execution << f_name_alloc_table_2_dim << new_line << new_line;
	return true;

}

bool b_dealloc_table_2_dim(int **piTable, int iSizeX, int iSizeY) {

	//Weryfikacja wymiar�w
	if (iSizeX < 1 || iSizeY < 1) {
		std::cout << msg_err_table_size;
		delete[] piTable; // I tak usuwam pod podanym adresem, lepiej tak ni� zostawi� w pami�ci co� co oczekujeny �e zosta�o usuni�te.
		return false;
	}
	//Sprawdzenie czy tablica zosta�a zaalokowana
	if (piTable == nullptr) {
		std::cout << msg_err_not_allocated;
		return false;
	}

	for (int i = 0; i < iSizeY; i++)
	{
		delete[] piTable[i];
	}
	delete[] piTable;

	std::cout << msg_succesfull_execution << f_name_dealloc_table_2_dim << new_line << new_line;
	return true;
}

 int main()
 {
	 std::cout << msg_program_initialized;
	 v_alloc_table_fill_34(table_1_size);
	 int** pi_table;
	 b_alloc_table_2_dim( &pi_table, table_2_size_X, table_2_size_Y);
	 std::cout << (*pi_table)[0] << "\n";
	 b_dealloc_table_2_dim(pi_table, table_2_size_X, table_2_size_Y);
	 std::cout << (*pi_table)[0] << "\n";

 }








// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
