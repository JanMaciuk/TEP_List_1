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

	CTable::CTable(const CTable& pcOther) 
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

	CTable::CTable(bool)
	{
		s_name = table1234_name;
		length = table1234_length;
		array = new int[length];
		for (int i = 0; i < length; i++)
		{
			array[i] = i + 1;
		}
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
			{ // Nie mogê zmniejszyæ tablicy bez utraty danych
			std:cout << iTableLen<< msg_err_table_smaller << length << line_break << line_break;
			return false;
		}
		else if (iTableLen == length)
		{ // Zmiana rozmiaru na taki sam, najprostszy scenariusz :)
			return true;
		}
		else
		{
			// Zmiana rozmiaru na wiêkszy, kopiuje istniej¹ce dane do nowej tablicy
			int* new_array = new int[iTableLen];
			for (int i = 0; i < length; i++)
			{
				new_array[i] = array[i];
			}

			delete[] array;		// usuwam star¹ tablicê
			length = iTableLen; // aktualizujê rozmiar tablicy
			array = new_array; // zamieniam obecn¹ tabicê na now¹.
			return true;
		}

	}
	CTable* CTable::pcClone() 
	{
		// U¿ywam istniej¹cego konstruktora kopiuj¹cego, komenda "zwróc kopie samego siebie"
		return new CTable(*this);
	}

	void CTable::vADD1ANDCopy(CTable** copyAdress) 
	{
		// Najpierw tworzê kopie tej tablicy pod adresem copyAdress
		*copyAdress = new CTable(*this);
		// Nastêpnie zwiêkszam rozmiar tej tablicy o 1
		(*copyAdress)->bSetNewSize(length + 1);
		// Ustawiam ostatni element na 1
		(*copyAdress)->array[(*copyAdress)->length - 1] = 1;
		//Wyœwietlam zawartoœæ obu tablic:
		vPrintData();
		for (int i = 0; i < this->length; i++)
		{
			std::cout << this->array[i] << line_break;
		}
		(*copyAdress)->vPrintData();
		for (int i = 0; i < (*copyAdress)->length; i++)
		{
			std::cout << (*copyAdress)->array[i] << line_break;
		}

	}

	//Procedury:
	//a->b == (*a).b, strza³ka jest jak kropka ze wskaŸnikiem.
	void CTable::v_mod_tab(CTable* pcTab, int iNewSize) { pcTab->bSetNewSize(iNewSize); }
	void CTable::v_mod_tab(CTable cTab, int iNewSize)   { cTab.bSetNewSize(iNewSize); }

//Destruktor:
	CTable::~CTable() 
	{
		std::cout << delete_notification << s_name << line_break << line_break;
		delete[] array;
	}
