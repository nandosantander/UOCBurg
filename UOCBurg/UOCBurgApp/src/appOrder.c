/*
 * File:        appOrder.c
 * Description: Contains the functionality that will manage the orders requested by the customers.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "appOrder.h"

#include "helpers.h"
#include "categories.h"
#include "products.h"
#include "operations.h"


/* 
 * Function:    appOrder_newOrder
 * Description: The customer requests products to be added to the basket
 * Arguments:   ---
 * Returns:     The option the user selected.
 */
char appOrder_newOrder()
{
	char option;

	helpers_clearScreen();
	
	printf("\nNew Order\n");
	printf("\n------------------------------------\n\n");
	
	printf("Please, select a menu option:\n\n");
	printf("1. Add product \n");
    printf("2. View basket \n");
    printf("3. Process order \n");
	printf("\n");
	printf("0. Exit\n\n");

	option = helpers_getOption();
	
	return option;
}

/*
 * Function:    appOrder_addProduct
 * Description: Adds a new product to the order
 * Arguments:   order: The order where the product shall be added
 * Returns:     ---
 */
void appOrder_addProduct(tOrder * order)
{
	tCategory * category;
	tProduct * product;
	tProductOrder * lastProduct, * newProduct;
	int option, count = 1;
	
	if (order == NULL)
	{
		return;
	}
	
	newProduct = (tProductOrder *)malloc(sizeof(tProductOrder));
	newProduct->nextProduct = NULL;
	
	helpers_clearScreen();
	
	// Request the values to the user.
	printf("\nNew Order\n");
	printf("\n------------------------------------\n\n");
	
	printf("Select the category:\n\n");
	category = categories_selectCategory();
	
	if (category == NULL)
	{
		free(newProduct);
		return;
	}
	
	printf("\n%s\n", category->text);
	printf("-------------------------------------\n\n");
		
	product = products_firstProduct;
    while(product != NULL)
	{
		if (product->category == category->id)
		{
			printf("%03d - %s\n", count, product->text);
			count++;
		}
        product = product->nextProduct;
    }
	
	if (count != 1)
    {
		// Once we have the category selected, let's display the products this category has.
		printf("\n\nSelect the product:  ");
		helpers_scanInt(&option);
		if (option == 0)
		{
			free(newProduct);
			return;
		}
		product = products_firstProduct;
		count = 0;
		while (product != NULL)
		{
			if (product->category == category->id)
			{
				count++;
			}
			if (count >= option)
			{
				break;
			}
			product = product->nextProduct;
		}
		
		if (product != NULL)
		{
			newProduct->id = product->id;
			printf("\n%s\n", product->text);
			printf("\nSelect the quantity: ");
			helpers_scanInt(&newProduct->quantity);
			
			if (newProduct->quantity > 0)
			{
				// Append the requested product to the order.
				lastProduct = orders_getLastProduct(order);
				if (lastProduct == NULL)
				{
					order->firstProduct = newProduct;
				}
				else
				{
					lastProduct->nextProduct = newProduct;
				}
				printf("\nProduct added to basket:\n");
				printf("\n%d x %s\n", newProduct->quantity, product->text);
				
				// Update the total of the order according to the selected product price and quantity.
				order->total += (product->price * newProduct->quantity);
				
				helpers_pressAnyKey();	
			}
		}
	}
}


/*
 * Function:    appOrder_displayBasket
 * Description: Auxilliary function to display on screen the contents of an order
 * Arguments:   order: The order to display
 * Returns:     ---
 */
void appOrder_displayBasket(tOrder * order)
{
	tProductOrder * productOrder;
	tProduct * product;
	
	// Display each requested product in the order.
	productOrder = order->firstProduct;
	while (productOrder != NULL)
	{
		product = products_getProductFromId(productOrder->id);
		if (product != NULL)
		{
			printf("%s\n", product->text);
			printf("\t\t%d x %.02fE\n\n", productOrder->quantity, product->price);
		}
		productOrder = productOrder->nextProduct;
	}
	printf("Total:\t\t    %.02fE\n", order->total);
    printf("\n");
}

/*
 * Function:    appOrder_viewBasket
 * Description: Displays the contents of an order
 * Arguments:   order: The order to display
 * Returns:     ---
 */
void appOrder_viewBasket(tOrder * order)
{
	
	helpers_clearScreen();
	
	if (order == NULL)
	{
		return;
	}
    
	printf("\nBasket (Order %d)\n", order->id);
    printf("\n------------------\n\n");
	
	appOrder_displayBasket(order);
	helpers_pressAnyKey();
}

/*
 * Function:    appOrder_processOrder
 * Description: Process the order by providing it the current datetime, appending it to the list and recording it into the proper file. 
 * Arguments:   order: The order to process
 * Returns:     ---
 */
void appOrder_processOrder(tOrder * order)
{
	time_t tTime;
	struct tm * currentTime;  
	tOrder * lastOrder;
	
	helpers_clearScreen();
    if (order->firstProduct == NULL)
	{
		printf("\n\nOrder %d not processed: No products in basket\n\n", order->id);
		printf("--------------------------------\n\n");			
	}
	else
	{
		time(&tTime);
		currentTime = localtime(&tTime);
		order->dateTime.year = currentTime->tm_year + 1900;
		order->dateTime.month = currentTime->tm_mon + 1;
		order->dateTime.day = currentTime->tm_mday;
		order->dateTime.hour = currentTime->tm_hour;
		order->dateTime.minute = currentTime->tm_min;
		
		lastOrder = orders_getLastOrder();
		if (lastOrder == NULL)
		{
			orders_firstOrder = order;
		}
		else
		{
			lastOrder->nextOrder = order;
		}
		
		ops_saveOrdersList();
		ops_saveOrderDescription(order);
		
		
		printf("\n\nOrder %d correctly processed\n\n", order->id);
		printf("--------------------------------\n\n");
		
		appOrder_displayBasket(order);
	}

	helpers_pressAnyKey();
}


/*
 * Function:    appOrder_viewOrders
 * Description: Displays the list of orders already submitted
 * Arguments:   ---
 * Returns:     ---
 */
void appOrder_viewOrders()
{
	tOrder * order;
	int option;
		
	helpers_clearScreen();
	
	printf("\nView Orders\n");
	printf("\n------------------------------------\n\n");
		
	order = orders_firstOrder;
    while(order != NULL)
	{
		printf("%d. %02d/%02d/%02d %02d:%02d\n", order->id, order->dateTime.year, order->dateTime.month, order->dateTime.day, order->dateTime.hour, order->dateTime.minute);
		order = order->nextOrder;
    }
   	printf("\n");
	printf("0. Exit\n\n");

	printf("\nSelect the order:  ");

	helpers_scanInt(&option);
	if (option != 0)
	{	
		order = orders_getOrderFromId(option);
		appOrder_viewBasket(order);
	}
}
