#include <iostream>
#include "Functions123.h"
#include "Class4.h"

int main()
{
	
	v_alloc_table_fill_34(table_1_size);
	int** pi_table;
	b_alloc_table_2_dim(&pi_table, table_2_size_X, table_2_size_Y);

	b_dealloc_table_2_dim(&pi_table, table_2_size_X, table_2_size_Y);

	
	CTable* table1 = new CTable();
	table1->vPrintData();
	CTable* table2 = new CTable(*table1);
	CTable* table3 = table1->pcClone();
	table1->vSetName(renamed_string);
	table1->bSetNewSize(10);
	table3->bSetNewSize(12);
	table1->vPrintData();
	table2->vPrintData();
	table3->vPrintData();
	//TODO: write the two procedures, test them, and test allocation (as per task).
	delete table1;
	delete table2;
	delete table3;
	//Table1 is initialized with default parameters,
	//Table2 and Table3 are copies of Table1,
	//Then Table1 name is changed and size is increased to 10,
	//Table3 retains copy name, but size increases to 12,
	//Table2 stays unmodified after copy.
}