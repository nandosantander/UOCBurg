/*
 * File:        svrMain.c
 * Description: Contains the main functionality for the application
 */

#include <stdio.h>
#include "svrMain.h"
#include "svrCategoriesMenu.h"
#include "svrProductsMenu.h"
#include "svrReportsMenu.h"

#include "operations.h"
#include "categories.h"
#include "products.h"
#include "helpers.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 
 * Function:    svrMain_mainMenu
 * Description: Displays the UOCBurg Server application main menu with the available operations
 * Arguments:   ---
 * Returns:     The option the user selected.
 */
char svrMain_mainMenu()
{
	int version;
	char option;
	
	helpers_clearScreen();
	
	version = ops_getVersion();
	
	printf("\nWelcome to the UOCBurg Server application!\n");
	printf("\n------------------------------------\n\n");
	printf("Library version: %d\n\n", version);
	
	printf("Please, select a menu option:\n\n");
	printf("1. Edit Categories \n");
    printf("2. Edit Products \n");
	printf("3. View Report \n");
	printf("\n");
	printf("0. Exit\n\n");
	
	option = helpers_getOption();
	
	return option;
}

/* 
 * Function:    svrMain_displayMenu
 * Description: Displays the UOCBurg Server application main menu
 * Arguments:   ---
 * Returns:     ---
 */
void svrMain_displayMenu()
{
	char option;

    do
	{
		option = svrMain_mainMenu();
		switch(option)
		{
			case '1':
				svrMain_editCategories();
				break;
			case '2':
				svrMain_editProducts();
				break;
			case '3':
				svrMain_viewReport();
				break;
		}

    } while(option != '0');
}


/* 
 * Function:    svrMain_editCategories
 * Description: Displays the Edit Categories sub-menu
 * Arguments:   ---
 * Returns:     ---
 */
void svrMain_editCategories()
{
    char option;
    
	do
	{
		option = svrCategoriesMenu_mainMenu();
		switch(option)
		{
			case '1':
				svrCategoriesMenu_listCategories();
				break;
			case '2':
				svrCategoriesMenu_addCategory();
				break;
			case '3':
				svrCategoriesMenu_removeCategory();
				break;
			case '4':
				categories_sortAlphabetically();
				svrCategoriesMenu_listCategories();
				break;
		}

    } while(option != '0');
}


/* 
 * Function:    svrMain_editProducts
 * Description: Displays the Edit Products sub-menu
 * Arguments:   ---
 * Returns:     ---
 */
void svrMain_editProducts()
{
	char option;
	
	do
	{
		option = svrProductsMenu_mainMenu();
		switch(option)
		{
			case '1':
				svrProductsMenu_listProducts();
				break;
			case '2':
				svrProductsMenu_addProduct();
				break;
			case '3':
				svrProductsMenu_removeProduct();
				break;
			case '4':
				products_sortAlphabetically();
				svrProductsMenu_listProducts();
				break;
		}

    } while(option != '0');
}

/* 
 * Function:    svrMain_viewReport
 * Description: Provides report of the sellings.
 * Arguments:   ---
 * Returns:     ---
 */
void svrMain_viewReport()
{
	char option;
	
	///
	/// EX
	///
	
	do
	{
		option = svrReportsMenu_mainMenu();
		switch(option)
		{
			case '1':
				svrReportsMenu_todayReport();
				break;
			case '2':
				svrReportsMenu_yearReport();
				break;
			case '3':
				svrReportsMenu_fullReport();
				break;
		}

    } while(option != '0');
	
	/// END OF EX
	
}


