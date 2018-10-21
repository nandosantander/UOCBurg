#ifndef _OPERATIONS_H_
#define _OPERATIONS_H_

#define UOCBURG_LIB_VERSION 3

#define OPS_CATEGORIES_FILE "Logs/categories.txt"
#define OPS_PRODUCTS_FILE "Logs/products.txt"
#define OPS_PRODUCT_DESC_FILE "Logs/product_%03d.txt"
#define OPS_ORDERS_FILE "Logs/orders.txt"
#define OPS_ORDER_DESC_FILE "Logs/order_%03d.txt"

#include "categories.h"
#include "products.h"
#include "orders.h"

// Gets the library version
int ops_getVersion();

// Saves the list of categories with their information into a file.
void ops_saveCategoriesList();

// Retrieves the information of the categories previously stored on the file
void ops_loadCategoriesInformation();

// Saves the list of products with their information into a file.
void ops_saveProductsList();

// Save the detailed description of the product into the specific file.
void ops_saveProductDescription(tProduct * product);

// Retrieves the information of the products previously stored on the file
void ops_loadProductsInformation();

// Retrieves the detailed description of the product previously stored on the product specific file
void ops_loadProductDescription(tProduct * product);

// Saves the list of orders with their information into a file.
void ops_saveOrdersList();

// Save the detailed description of the order into the specific file.
void ops_saveOrderDescription(tOrder * order);

// Retrieves the information of the orders previously stored on the file
void ops_loadOrdersInformation();

// Retrieves the detailed description of the order previously stored on the order specific file
void ops_loadOrderDescription(tOrder * order);


#endif