// Prevent including the header multiple times
#ifndef Class4
#define Class4

// String type support
#include <string>
using namespace std;

const string default_s_name = "Unnamed table";
const int	 default_length = 8;
const string param_string = "Parametr:";
const string no_param_string = "Bezp: ";
const string copy_string = "Kopiuj: ";
const string delete_notification = "Usuwam: ";
const string printing_notification = "Wypisuje dane tabeli: Nazwa: ";
const string size_string = ", Rozmiar: ";
const string line_break = "\n";
const string renamed_string = "Tabela z nowa nazwa";
const string msg_err_table_smaller = " is too small, unable to reduce table size, minimal size is ";

class CTable
{
	private:
		string s_name;
		int length;
		int* array;


	public:
		//Constructors:
		CTable();
		CTable(string sName, int iTableLen);
		CTable(CTable &pcOther);

		//Methods:
		void vSetName(string sName);
		bool bSetNewSize(int iTableLen);
		void vPrintData();
		CTable* pcClone();

		//Destructor:
		~CTable();

};



#endif