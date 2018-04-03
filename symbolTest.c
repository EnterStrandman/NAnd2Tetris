#include "symbolTable.h"

int main()
{
	struct SymbolTable myTable;
	myTable.head = NULL;
	insertAtEnd(&myTable, "hello", 42);
	insertAtEnd(&myTable, "HI", 78);
	printtable(&myTable);

	printf("%d\n",getAddress(&myTable,"HI"));
	printf("%d\n",getAddress(&myTable,"RIP"));
	destroytable(&myTable);
	return 0;
}
