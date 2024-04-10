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
const string printing_notification = "Wypisuje dane tabeli: \nNazwa: ";
const string size_string = ", Rozmiar: ";
const string line_break = "\n";
const string renamed_string = "Tabela z nowa nazwa";
const string msg_err_table_smaller = " to zbyt maly rozmiar, zmniejszanie rozmiaru tabeli nie jest dozwolone, minimalny rozmiar to ";
const string table1234_name = "tabela 1234";
const int table1234_length = 4;
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
		CTable(const CTable &pcOther);
		CTable(bool);

		//Methods:
		void vSetName(string sName);
		bool bSetNewSize(int iTableLen);
		void vPrintData();
		CTable* pcClone();
		void  vADD1ANDCopy(CTable** copyAdress);

		//Procedures:
		static void v_mod_tab(CTable* pcTab, int iNewSize);
		static void v_mod_tab(CTable cTab, int iNewSize);
		//Static because they are not tied to a specific instance of the class, but to the class itself.
		//They operate on any instance that's passed as a parameter.
		//Hence there is no need for each instance to have its own copy of the procedure.

		//Destructor:
		~CTable();

};



#endif