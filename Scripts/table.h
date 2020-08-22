#include <fstream>
#include "itemtype.h"


class TableBaseClass
{
	public:
		virtual bool Empty(void) const = 0;
		virtual bool Insert(const ItemType & Item) = 0;
		virtual bool Retrieve(KeyFieldType SearchKey, ItemType & Item) = 0;
	protected:
		fstream DataFile;   // the file stream for the table data
		long NumItems;      // number of records of type ItemType in the table
		char OpenMode;      // r or w (read or write) mode for the table
};


