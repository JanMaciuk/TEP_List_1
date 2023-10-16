// Prevent including the header multiple times
#ifndef TEP_List_1
#define TEP_List_1

// String type support
#include <string>
using namespace std; 

// Constants:
const int table_1_int_value = 34;
const int table_1_size = 5;

const int table_2_size_X = 3;
const int table_2_size_Y = 3;

// Messages:
const string msg_printing_table = "Wypisuje zawartosc tablicy:\n";
const string msg_err_table_size = "Nieprawidlowy rozmiar tablicy, sprawdz przekazana wartosc\n";
const string msg_table_allocated = "Zaalokowano tablice o rozmiarze ";
const string msg_table_filled = "Wypelniono tablice wartoscia ";
const string msg_succesfull_execution = "Pomyslnie wykonano ";
const string new_line = "\n";
const string msg_err_not_allocated = "Invalid argument passed, seems like table is not allocated properly\n";
// Function names:
const string f_name_alloc_table = "v_alloc_table_fill_34";
const string f_name_alloc_table_2_dim = "b_alloc_table_2_dim";
const string f_name_dealloc_table_2_dim = "b_dealloc_table_2_dim";


// Function prototypes declarations:
bool b_alloc_table_fill_34(int iSize);
bool b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY);
bool b_dealloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY);

#endif 