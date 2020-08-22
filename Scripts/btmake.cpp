#include "btree.h"

const int LineMax = KeyFieldMax + DFMaxPlus1;

typedef char StringType[LineMax];

void ReadLine(fstream & InputFile, KeyFieldType Word, DataFieldType Definition)
{
	char Line[LineMax];
	int k, ch;

	InputFile.getline(Line, LineMax);   // will read the newline char

	for (k = 0; k < KeyFieldMax; k++)
		Word[k] = Line[k];
	Word[KeyFieldMax] = NULLCHAR;

	for (k = 0; k < DataFieldMax; k++)
	{
		ch = Line[KeyFieldMax + k];
		if (ch == '\n')
			break;
		Definition[k] = ch;
	}
	Definition[k] = NULLCHAR;
}


/* Given:  InputFile   A file stream already opened for input.
Task:   To read the data from InputFile and load it into the Table.
Return: Table       The B-tree table containing the data.
*/
void Load(fstream & InputFile, BTTableClass & Table)
{
	ItemType Item;
	int Count;

	Count = 0;
	ReadLine(InputFile, Item.KeyField, Item.DataField);

	while (! InputFile.fail())
	{
#ifdef DEBUG
		Count++;
		if (Count == 22)
		{
			Count = 0;
			cout << endl << "Press ENTER";
			cin.get();
		}
		cout << endl << "DEBUG: ready to insert " << Item.KeyField << " ";
#endif

		Table.Insert(Item);

#ifdef DEBUG
		Table.Check();
#endif

		ReadLine(InputFile, Item.KeyField, Item.DataField);
	}
}


int main(void)
{
	fstream Source;
	BTTableClass BTTable('w', "btree.dat");

	Source.open("btree.txt", ios::in);
	if (Source.fail())
	{
		cerr << "ERROR: Unable to open file btree.txt" << endl;
		exit(1);
	}

	Load(Source, BTTable);
	Source.close();
	return 0;
}


