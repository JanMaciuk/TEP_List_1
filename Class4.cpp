#include <iostream>
#include "Class4.h"



//Konstruktory:
	CTable::CTable()
	{
		s_name = default_s_name;
		length = default_length;
		array = new int[length];
		std::cout << no_param_string << s_name << line_break << line_break;

	}

	CTable::CTable(string sName, int iTableLen)
	{
		s_name = sName;
		length = iTableLen;
		array = new int[length];
		std::cout << param_string << s_name << line_break << line_break;
	}

	CTable::CTable(CTable& pcOther) 
	{
		s_name = pcOther.s_name + "_copy";
		length = pcOther.length;
		array = new int[length];
		for (int i = 0; i < length; i++)
		{
			array[i] = pcOther.array[i];
		}
		std::cout << copy_string << s_name << line_break << line_break;
	}


//Metody:
	void CTable::vSetName(string sName)
	{
		s_name = sName;
	}
	void CTable::vPrintData()
	{
		std::cout << printing_notification << s_name << size_string << length << line_break << line_break;
	}

	bool CTable::bSetNewSize(int iTableLen)
	{
		if (iTableLen < length)
			{ // Nie mog� zmniejszy� tablicy bez utraty danych
			std:cout << iTableLen<< msg_err_table_smaller << length << line_break << line_break;
			return false;
		}
		else if (iTableLen == length)
		{ // Zmiana rozmiaru na taki sam, najprostszy scenariusz :)
			return true;
		}
		else
		{
			// Zmiana rozmiaru na wi�kszy, kopiuje istniej�ce dane do nowej tablicy
			int* new_array = new int[iTableLen];
			for (int i = 0; i < length; i++)
			{
				new_array[i] = array[i];
			}

			delete[] array;		// usuwam star� tablic�
			length = iTableLen; // aktualizuj� rozmiar tablicy
			array = new_array; // zamieniam obecn� tabic� na now�.
			return true;
		}

	}
	CTable* CTable::pcClone() 
	{
		// U�ywam istniej�cego konstruktora kopiuj�cego, komenda "zwr�c kopie samego siebie"
		return new CTable(*this);
	}

	//Procedury:
	//a->b == (*a).b, strza�ka jest jak kropka ze wska�nikiem.
	void CTable::v_mod_tab(CTable* pcTab, int iNewSize) { pcTab->bSetNewSize(iNewSize); }
	void CTable::v_mod_tab(CTable cTab, int iNewSize)   { cTab.bSetNewSize(iNewSize); }

//Destruktor:
	CTable::~CTable() 
	{
		std::cout << delete_notification << s_name << line_break << line_break;
		delete[] array;
	}
