#ifndef _APPORDER_H_
#define _APPORDER_H_

#include "orders.h"

// The customer requests products to be added to the basket
char appOrder_newOrder();

// Adds a new product to the order
void appOrder_addProduct(tOrder * order);

// Displays the contents of an order
void appOrder_viewBasket(tOrder * order);

// Process the order by providing it the current datetime, appending it to the list and recording it into the proper file. 
void appOrder_processOrder(tOrder * order);

// Displays the list of orders already submitted
void appOrder_viewOrders();

// Auxilliary function to display on screen the contents of an order
void appOrder_displayBasket(tOrder * order);

#endif