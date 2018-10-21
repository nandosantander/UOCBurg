#ifndef _SVRCATEGORIESMENU_H_
#define _SVRCATEGORIESMENU_H_

// Displays the Categories sub-menu with the available operations
char svrCategoriesMenu_mainMenu();

// Creates a new Category struct and requests for the information
void svrCategoriesMenu_addCategory();
	
// Display the list of available categories. 
void svrCategoriesMenu_listCategories();

// Request the user to select which category to remove from the list. 
void svrCategoriesMenu_removeCategory();

#endif