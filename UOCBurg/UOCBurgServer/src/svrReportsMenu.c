/*
 * File:        svrReportsMenu.c
 * Description: Contains the user interface functionality for the Reports related functionality
 * 				Basically, it implements the different menus that will be displayed on the screen
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "svrReportsMenu.h"

#include "helpers.h"
#include "products.h"
#include "categories.h"
#include "operations.h"
#include "orders.h"

/* 
 * Function:    svrReportsMenu_mainMenu
 * Description: Displays the Reports sub-menu with the available operations
 * Arguments:   ---
 * Returns:     The option the user selected.
 */
char svrReportsMenu_mainMenu()
{
	char option;
	
	helpers_clearScreen();

	
	printf("\nView Reports\n");
	printf("\n------------------------------------\n\n");
	
	printf("Please, select a menu option:\n\n");
	printf("1. View Today Report \n");
	printf("2. View This Year Report \n");
	printf("3. View All Data \n");
	printf("\n");
	printf("0. Exit\n\n");

	
	option = helpers_getOption();
	
	return option;
}

/*
 * Function:    svrReportsMenu_todayReport
 * Description: Displays the report of the orders made during today 
 * Arguments:   ---
 * Returns:     ---
 */
void svrReportsMenu_todayReport()
{
	
	helpers_clearScreen();
	printf("\n\nToday's Report: \n\n");
	printf("\n-------------------\n\n");
	
	
	///
	/// EX.5.2. Display a report with the summary of all the products requested during today.
	///
	
	svrReportsMenu_generateReport(SVRREPORT_TODAY);
	
	/// END OF EX.5.2.
	
	helpers_pressAnyKey();	
}

/*
 * Function:    svrReportsMenu_yearReport
 * Description: Displays the report of the orders made during this year 
 * Arguments:   ---
 * Returns:     ---
 */
void svrReportsMenu_yearReport()
{
	
	helpers_clearScreen();
	printf("\n\nThis Year Report: \n\n");
	printf("\n-------------------\n\n");
	
	///
	/// EX.5.3. Display a report with the summary of all the products requested during this year.
	///
	
    svrReportsMenu_generateReport(SVRREPORT_YEAR);
	
	/// END OF EX.5.3.
	
	helpers_pressAnyKey();	
}



/*
 * Function:    svrReportsMenu_fullReport
 * Description: Displays the report of all the historic data 
 * Arguments:   ---
 * Returns:     ---
 */
void svrReportsMenu_fullReport()
{	
	
	helpers_clearScreen();
	printf("\n\nHistoric Report: \n\n");
	printf("\n-------------------\n\n");
	
	///
	/// EX.5.1. Display a report with the summary of all the products requested since the very beginning.
	///
	
    svrReportsMenu_generateReport(SVRREPORT_FULL);
	
	/// END OF EX.5.1.
	
	helpers_pressAnyKey();	
}

/*
 * Function:    svrReportsMenu_generateReport
 * Description: Generates the report according the selected option 
 * Arguments:   type: The kind of report (just this day, this year or whole data)
 * Returns:     ---
 */
void svrReportsMenu_generateReport(reportType type)
{
	///
	/// EX.
	/// 
	
	tOrder * currentOrder;
	tProduct * currentProduct;
	tProductOrder * currentProductOrder;
	float total;
	int quantity;
	time_t tTime;
	struct tm * currentTime;  

	time(&tTime);
	currentTime = localtime(&tTime);
	
	total = 0;
	currentProduct = products_firstProduct;
	while (currentProduct != NULL)
	{
		quantity = 0;
		currentOrder = orders_firstOrder;
		while (currentOrder != NULL)
		{
			if ((type == SVRREPORT_FULL) ||
				((type == SVRREPORT_YEAR) && (currentOrder->dateTime.year == (currentTime->tm_year + 1900))) ||
				((type == SVRREPORT_TODAY) && (currentOrder->dateTime.day == currentTime->tm_mday)))
			{
				currentProductOrder = currentOrder->firstProduct;
				while (currentProductOrder != NULL)
				{
					if (currentProductOrder->id == currentProduct->id)
					{
						quantity += currentProductOrder->quantity; 
					}
					currentProductOrder = currentProductOrder->nextProduct;
				}
				currentOrder = currentOrder->nextOrder;
			}
		}
		total += quantity * currentProduct->price;
		
		if (quantity > 0)
		{
			printf("%s\n", currentProduct->text);
			printf("\t\t%02d x %.02fE\n\n", quantity, currentProduct->price);
		}
		currentProduct = currentProduct->nextProduct;
	}
	
	printf("Total:\t\t    %.02fE\n", total);
    printf("\n");
	
}
