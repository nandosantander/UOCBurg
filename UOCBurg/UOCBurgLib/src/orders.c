/*
 * File:        orders.c
 * Description: Contains the functionality related to the orders management.
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "orders.h"
#include "helpers.h"

/*
 * Function: 	orders_freeMemory
 * Description: Frees the previously allocated memory of a non-processed order
 * Arguments:   The order whose memory shall be freed.
 * Returns: 	---
 */
void orders_freeMemory(tOrder * order)
{
	tProductOrder * currentProduct, * nextProduct;
	
	if (order == NULL)
	{
		return;
	}
	
	// Free the memory of all the products it contains
	currentProduct = order->firstProduct;
	while (currentProduct != NULL)
	{
		nextProduct = currentProduct->nextProduct;
		free(currentProduct);
		currentProduct = nextProduct;
	}
	
	// And finally free the order struct itself.
	free(order);
}


/*
 * Function: 	orders_getHighestId
 * Description: Gets the highest Id of all the orders already sumitted.
 * Arguments:   ---
 * Returns: 	The highest Id.
 */
int orders_getHighestId()
{
	int retValue = 0;
	tOrder * order = orders_firstOrder;
	if (order == NULL)
	{
		return retValue;
	}
	
	retValue = order->id;
	
	while (order->nextOrder != NULL)
	{
		order = order->nextOrder;
		if (order->id > retValue)
		{
			retValue = order->id;
		}
	}
	
	return retValue;
}

/*
 * Function: 	orders_getLastProduct
 * Description: Gets the latest product pointer in an order.
 * Arguments:   ---
 * Returns: 	The pointer to the latest product in order
 */
tProductOrder * orders_getLastProduct(tOrder * order)
{
	tProductOrder * retValue = NULL;

	retValue = order->firstProduct;
	
	if (retValue == NULL)
	{
		return retValue;
	}
	
	while (retValue->nextProduct != NULL)
	{
		retValue = retValue->nextProduct;
	}
	
	return retValue;
}


/*
 * Function: 	orders_getLastOrder
 * Description: Gets the latest stored order.
 * Arguments:   ---
 * Returns: 	The pointer to the latest stored order
 */
tOrder * orders_getLastOrder()
{
	tOrder * retValue = NULL;

	retValue = orders_firstOrder;
	
	if (retValue == NULL)
	{
		return orders_firstOrder;
	}
	
	while (retValue->nextOrder != NULL)
	{
		retValue = retValue->nextOrder;
	}
	
	return retValue;
}



/*
 * Function: 	orders_getOrderFromId
 * Description: Gets a order struct given its id
 * Arguments:   Id: The id to look for
 * Returns: 	The order struct matching this id. Null if not found.
 */
tOrder * orders_getOrderFromId(int id)
{
	tOrder * order = orders_firstOrder;
	
	while (order != NULL)
	{
		if (order->id == id)
		{
			return order;
		}
		order = order->nextOrder;
	}
	
	return NULL;
}
