/*
 * File:        main.c
 * Description: Initialization point
 * IMPORTANT NOTE: ¡¡¡¡Do not add modify this file!!!!.
 * 				   It will be used for the automated validation.
 */

#include <stdio.h>

#include "operations.h"
#include "svrMain.h"
#include "products.h"
#include "categories.h"

/* 
 * Function:    main
 * Description: Application entry method
 * Arguments:   ---
 * Returns:     0 always.
 */
int main(int argc, char **argv)
{
	// Initialize the first entry of the list
	categories_firstCategory = NULL;
	products_firstProduct = NULL;
	orders_firstOrder = NULL;
	
	ops_loadCategoriesInformation();
	ops_loadProductsInformation();
	ops_loadOrdersInformation();

	// Display the main application menu
	svrMain_displayMenu();

	return 0;
}

