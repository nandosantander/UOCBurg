/*
 * File:        appMain.c
 * Description: Contains the main functionality for the application
 */

#include "appMain.h"
#include "appOrder.h"

#include "operations.h"
#include "categories.h"
#include "products.h"
#include "orders.h"
#include "helpers.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* 
 * Function:    appMain_mainMenu
 * Description: Displays the UOCBurg application main menu with the available operations
 * Arguments:   ---
 * Returns:     The option the user selected.
 */
char appMain_mainMenu()
{
	int version;
	char option;
	
	helpers_clearScreen();
	
	version = ops_getVersion();
	
	printf("\nWelcome to the UOCBurg application!\n");
	printf("\n------------------------------------\n\n");
	printf("Library version: %d\n\n", version);
	
	printf("Please, select a menu option:\n\n");
	printf("1. New Order \n");
    printf("2. View Orders \n");
	printf("\n");
	printf("0. Exit\n\n");
	
	option = helpers_getOption();
	
	return option;
}

/* 
 * Function:    appMain_displayMenu
 * Description: Displays the UOCBurg application main menu
 * Arguments:   ---
 * Returns:     ---
 */
void appMain_displayMenu()
{
	char option;

    do
	{
		option = appMain_mainMenu();
		switch(option)
		{
			case '1':
				appMain_newOrder();
				break;
			case '2':
				appOrder_viewOrders();
				break;
		}
    } while(option != '0');
}


/* 
 * Function:    appMain_newOrder
 * Description: Requests the user the information to process the new order.
 * Arguments:   ---
 * Returns:     ---
 */
void appMain_newOrder()
{
    char option;
   	tOrder * order = NULL;

	do
	{
		// If memory is not already allocated yet, let's do it.
		if (order == NULL)
		{
			order = (tOrder *)malloc(sizeof(tOrder));
			order->id = orders_getHighestId() + 1;
			order->total = 0;
			order->firstProduct = NULL;
			order->nextOrder = NULL;
		}
		
		option = appOrder_newOrder();
		switch(option)
		{
			case '1':
				appOrder_addProduct(order);
				break;
			case '2':
				appOrder_viewBasket(order);
				break;
			case '3':
				appOrder_processOrder(order);
				break;
		}
    } while((option != '0') && (option != '3'));
	
	if (option == '0')
	{
		// This order has not been processed, so we can free its memory
		orders_freeMemory(order);
	}
}
