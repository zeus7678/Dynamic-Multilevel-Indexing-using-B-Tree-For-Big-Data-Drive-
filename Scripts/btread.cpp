#include <cctype>
#include "btree.h"

bool ReadKeyboard(KeyFieldType Word)
{
	int k, ch;
	bool start;

	cin >> Word;
	cin.get();   // get the newline

	if (Word[0] == '.')
		return false;

	start = true;

	for (k = 0; k < KeyFieldMax; k++) {
		ch = Word[k];
		if (ch == '\0')
			start = false;
		if (start)
			Word[k] = toupper(ch);   // capitalize
		else
			Word[k] = ' ';   // pad with blanks
	}

	Word[KeyFieldMax] = NULLCHAR;
	return true;
}


int main(void)
{
	ItemType Item;
	KeyFieldType SearchKey;
	BTTableClass BTTable('r', "btree.dat");

	if (BTTable.Empty())
		Error("Table is empty");

	cout << "Enter the word to be looked up (or . to quit): ";

	while (ReadKeyboard(SearchKey)) {
		if (BTTable.Retrieve(SearchKey, Item))
			cout << " Definition:   " << Item.DataField << endl;
		else
			cout << " Not found" << endl;
		cout << endl << "Enter the word to be looked up (or . to quit): ";
	}

	return 0;
}