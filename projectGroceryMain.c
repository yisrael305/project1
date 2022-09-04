#include "projectGroceryHead.h"              // Israel Weiss 

int main() {

	
	struct list* listOfDebts = createList(); // Assigned memory for the list.

	FILE* fp = openFile("listOfDebtors.csv"); // Open file. if the file does not exist the user will asked to enter a different name of the file
	
	readFile(fp, listOfDebts);
	
	printf("\n");
	printList(listOfDebts);
	printInstructions();

	int flag; // Uses to signel when the user wnts to end the program.

	while (flag = getQuery(fp, listOfDebts));  // Get queries from the user.
	
	fclose(fp);               // Saving file

	freeList(listOfDebts);    // free mempry.

	return 0;
}
