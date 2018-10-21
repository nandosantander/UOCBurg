#ifndef _ORDERS_H_
#define _ORDERS_H_

#include <time.h>

#include "helpers.h"

typedef struct sProductOrder
{
	int id;
	int quantity;
	struct sProductOrder * nextProduct;
} tProductOrder;

typedef struct sOrder 
{
	int id;
	float total;
	tDateTime dateTime;
	tProductOrder * firstProduct;
	struct sOrder * nextOrder;
} tOrder;

tOrder * orders_firstOrder;

// Frees the previously allocated memory of a non-processed order
void orders_freeMemory(tOrder * order);

// Gets the highest Id of all the orders already sumitted.
int orders_getHighestId();

// Gets the latest product pointer in an order.
tProductOrder * orders_getLastProduct(tOrder * order);

// Gets the latest stored order.
tOrder * orders_getLastOrder();

// Gets a order struct given its id
tOrder * orders_getOrderFromId(int id);

#endif