#ifndef _SVRPRODUCTSMENU_H_
#define _SVRPRODUCTSMENU_H_

// Displays the Products sub-menu with the available operations
char svrProductsMenu_mainMenu();

// Creates a new Product struct and requests for the information
void svrProductsMenu_addProduct();

// Display the list of available products. 
void svrProductsMenu_listProducts();

// Request the user to select which product to remove from the list.
void svrProductsMenu_removeProduct();


#endif