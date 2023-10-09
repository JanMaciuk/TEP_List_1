// Prevent including the header multiple times (not really possible in a single .cpp project, but a good practice to follow)
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
const string msg_program_initialized = "Poprawna inicjalizacja programu \n\n";
const string msg_err_table_size = "Table size invalid, check passed value\n";
const string msg_table_allocated = "Aloccated a table of size ";
const string msg_table_filled = "Table filled with value ";
const string msg_succesfull_execution = "Succesfully executed ";
const string new_line = "\n";
const string msg_err_not_allocated = "Invalid argument passed, seems like table is not allocated properly\n";
// Function names:
const string f_name_alloc_table = "v_alloc_table_fill_34";
const string f_name_alloc_table_2_dim = "b_alloc_table_2_dim";
const string f_name_dealloc_table_2_dim = "b_dealloc_table_2_dim";


// Function prototypes declarations:
void v_alloc_table_fill_34(int iSize);
bool b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY);
bool b_dealloc_table_2_dim(int** piTable, int iSizeX, int iSizeY);

#endif 