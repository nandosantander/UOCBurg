/*
 * File:        operations.c
 * Description: Contains miscellaneous operations provided by the library.
 */
 
#include "operations.h"
#include "categories.h"
#include "products.h"
#include "orders.h"
#include "helpers.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 /* 
 * Function:    ops_getVersion
 * Description: Gets the library version
 * Arguments:   ---
 * Returns:     The library version
 */
int ops_getVersion()
{
	return UOCBURG_LIB_VERSION;
}

/*
 * Function:    ops_saveCategoriesList
 * Description: Saves the list of categories with their information into a file.
 * Arguments:   ---
 * Returns:     ---
 */ 
void ops_saveCategoriesList()
{
	FILE * outputFile;
	tCategory * category;

	outputFile = fopen(OPS_CATEGORIES_FILE, "w");
	if (outputFile == NULL)
	{
		return;
	}
	
	category = categories_firstCategory;
	while (category != NULL)
	{
		fprintf(outputFile, "%d;%s;%d\n", category->id, category->text, category->position);
		category = category->nextCategory;
	}
	
	fclose(outputFile);
}

/*
 * Function:    ops_loadCategoriesInformation
 * Description: Retrieves the information of the categories previously stored on the file
 * Arguments:   ---
 * Returns:     The list of categories is retrieved upon categories_firstCategory variable.
 */ 
void ops_loadCategoriesInformation()
{
	FILE * inputFile;
	tCategory * newCategory, * currentCategory;
	char * auxId, * auxText, * auxPosition;
	int firstStruct = 1;
	
	inputFile = fopen(OPS_CATEGORIES_FILE, "r");
	if (inputFile == NULL)
	{
		return;
	}
	
	do
	{
		// First, we read the contents of the line
		auxId = helpers_scanFromFile(inputFile, ';', 3);
		auxText = helpers_scanFromFile(inputFile, ';', MAX_CATEGORY_LENGTH);
		auxPosition = helpers_scanFromFile(inputFile, ';', 3);

		if (strcmp(auxId, ""))
		{
			// We have a new register, so append it to the list.
			newCategory = (tCategory *)malloc(sizeof(tCategory));
			categories_initStruct(newCategory);
		
			newCategory->id = atoi(auxId);
			strcpy(newCategory->text, auxText);
			newCategory->position = atoi(auxPosition);
			
			if (firstStruct == 1)
			{
				// This is the very first struct, so assign it to categories_firstCategory 
				categories_firstCategory = newCategory;
				firstStruct = 0;
			}
			else
			{
				// assign next struct in current pointer
				currentCategory->nextCategory = newCategory;
			}
			
			// move the pointer
			currentCategory = newCategory;
			
			// and free previously allocated data
			free(auxId);
			free(auxText);
			free(auxPosition);
		}
	} while (strcmp(auxId, ""));
	
	
	fclose(inputFile);
}


/*
 * Function:    ops_saveProductsList
 * Description: Saves the list of products with their information into a file.
 * Arguments:   ---
 * Returns:     ---
 */ 
void ops_saveProductsList()
{
	FILE * outputFile;
	tProduct * product;

	outputFile = fopen(OPS_PRODUCTS_FILE, "w");
	if (outputFile == NULL)
	{
		return;
	}
	
	product = products_firstProduct;
	while (product != NULL)
	{
		fprintf(outputFile, "%d;%d\n", product->id, product->position);
		product = product->nextProduct;
	}
	
	fclose(outputFile);
}


/*
 * Function:    ops_saveProductDescription
 * Description: Save the detailed description of the product into the specific file.
 * Arguments:   product: The product to save
 * Returns:     ---
 */ 
void ops_saveProductDescription(tProduct * product)
{
	FILE * outputFile;
	char filename[32];

	if (product == NULL)
	{
		return;
	}
	
	sprintf(filename, OPS_PRODUCT_DESC_FILE, product->id);
	
	outputFile = fopen(filename, "w");
	if (outputFile == NULL)
	{
		return;
	}
	
	fprintf(outputFile, "%s\n", product->text);
	fprintf(outputFile, "%s\n", product->description);
	fprintf(outputFile, "%d\n", product->category);
	fprintf(outputFile, "%.02f\n", product->price);
	
	fclose(outputFile);
}


/*
 * Function:    ops_loadProductsInformation
 * Description: Retrieves the information of the products previously stored on the file
 * Arguments:   ---
 * Returns:     The list of products is retrieved upon products_firstProduct variable.
 */ 
void ops_loadProductsInformation()
{
	FILE * inputFile;
	tProduct * newProduct, * currentProduct;
	char * auxId, * auxPosition;
	int firstStruct = 1;
	
	inputFile = fopen(OPS_PRODUCTS_FILE, "r");
	if (inputFile == NULL)
	{
		return;
	}
	
	do
	{
		// First, we read the contents of the line
		auxId = helpers_scanFromFile(inputFile, ';', 3);
		auxPosition = helpers_scanFromFile(inputFile, ';', 3);

		if (strcmp(auxId, ""))
		{
			// We have a new register, so append it to the list.
			newProduct = (tProduct *)malloc(sizeof(tProduct));
			products_initStruct(newProduct);
		
			newProduct->id = atoi(auxId);
			newProduct->position = atoi(auxPosition);
			
			if (firstStruct == 1)
			{
				// This is the very first struct, so assign it to products_firstProduct 
				products_firstProduct = newProduct;
				firstStruct = 0;
			}
			else
			{
				// assign next struct in current pointer
				currentProduct->nextProduct = newProduct;
			}
			
			// move the pointer
			currentProduct = newProduct;
			
			// load the specific product information
			ops_loadProductDescription(currentProduct);
			
			// and free previously allocated data
			free(auxId);
			free(auxPosition);
		}
	} while (strcmp(auxId, ""));
	
	
	fclose(inputFile);
}

/*
 * Function:    ops_loadProductDescription
 * Description: Retrieves the detailed description of the product previously stored on the product specific file
 * Arguments:   product: The product struct where the information will be retrieved.
 * Returns:     ---
 */ 
void ops_loadProductDescription(tProduct * product)
{
	FILE * inputFile;
	char filename[32];
	char * auxText;
	char * auxDescription;

	if (product == NULL)
	{
		return;
	}
	
	sprintf(filename, OPS_PRODUCT_DESC_FILE, product->id);
	
	inputFile = fopen(filename, "r");
	if (inputFile == NULL)
	{
		return;
	}
	
	auxText = helpers_scanFromFile(inputFile, '\n', MAX_PRODUCT_LENGTH);
	auxDescription = helpers_scanFromFile(inputFile, '\n', MAX_DESCRIPTION_LENGTH);
	
	strcpy(product->text, auxText);
	strcpy(product->description, auxDescription);
	
	fscanf(inputFile, "%d\n", &product->category);
	fscanf(inputFile, "%f\n", &product->price);
	
	free(auxText);
	free(auxDescription);
	
	fclose(inputFile);
}



/*
 * Function:    ops_saveOrdersList
 * Description: Saves the list of orders with their information into a file.
 * Arguments:   ---
 * Returns:     ---
 */ 
void ops_saveOrdersList()
{
	FILE * outputFile;
	tOrder * order;

	order = orders_firstOrder;
	outputFile = fopen(OPS_ORDERS_FILE, "w");
	if (outputFile == NULL)
	{
		return;
	}
	
	while (order != NULL)
	{
		fprintf(outputFile, "%d\n", order->id);
		order = order->nextOrder;
	}
	
	fclose(outputFile);
}


/*
 * Function:    ops_saveOrderDescription
 * Description: Save the detailed description of the order into the specific file.
 * Arguments:   order: The order to save
 * Returns:     ---
 */ 
void ops_saveOrderDescription(tOrder * order)
{
	FILE * outputFile;
	char filename[32];
	tProductOrder * productOrder;
	
	if (order == NULL)
	{
		return;
	}

	sprintf(filename, OPS_ORDER_DESC_FILE, order->id);
	
	outputFile = fopen(filename, "w");
	if (outputFile == NULL)
	{
		return;
	}
	
	fprintf(outputFile, "%02d/%02d/%02d %02d:%02d\n", order->dateTime.year, order->dateTime.month, order->dateTime.day, order->dateTime.hour, order->dateTime.minute);
	fprintf(outputFile, "%.02f\n", order->total);
	
	productOrder = order->firstProduct;
	while(productOrder != NULL)
	{
		fprintf(outputFile, "%d;%d\n", productOrder->id, productOrder->quantity);
		productOrder = productOrder->nextProduct;
	}
	
	fclose(outputFile);
}


/*
 * Function:    ops_loadOrdersInformation
 * Description: Retrieves the information of the orders previously stored on the file
 * Arguments:   ---
 * Returns:     The list of orders is retrieved upon orders_firstOrder variable.
 */ 
void ops_loadOrdersInformation()
{
	FILE * inputFile;
	tOrder * newOrder, * currentOrder;
	int auxId, firstStruct = 1;
	
	inputFile = fopen(OPS_ORDERS_FILE, "r");
	if (inputFile == NULL)
	{
		return;
	}
	
	while (fscanf(inputFile, "%d", &auxId) != EOF)
	{
		// We have a new register, so append it to the list.
		newOrder = (tOrder *)malloc(sizeof(tOrder));
		newOrder->id = auxId;
		newOrder->firstProduct = NULL;
		newOrder->nextOrder = NULL;
		if (firstStruct == 1)
		{
			// This is the very first struct, so assign it to orders_firstOrder 
			orders_firstOrder = newOrder;
			firstStruct = 0;
		}
		else
		{
			// assign next struct in current pointer
			currentOrder->nextOrder = newOrder;
		}
		
		// move the pointer
		currentOrder = newOrder;
		
		// load the specific product information
		ops_loadOrderDescription(currentOrder);
	}
	
	fclose(inputFile);
}

/*
 * Function:    ops_loadOrderDescription
 * Description: Retrieves the detailed description of the order previously stored on the order specific file
 * Arguments:   order: The order struct where the information will be retrieved.
 * Returns:     ---
 */ 
void ops_loadOrderDescription(tOrder * order)
{
	FILE * inputFile;
	tProductOrder * currentProductOrder, * newProductOrder;
	int auxId, auxQuantity, firstStruct = 1;
	char filename[32];

	if (order == NULL)
	{
		return;
	}
	
	sprintf(filename, OPS_ORDER_DESC_FILE, order->id);
	
	inputFile = fopen(filename, "r");
	if (inputFile == NULL)
	{
		return;
	}
	
	fscanf(inputFile, "%d/%d/%d %d:%d\n", &order->dateTime.year, &order->dateTime.month, &order->dateTime.day, &order->dateTime.hour, &order->dateTime.minute);
	fscanf(inputFile, "%f\n", &order->total);
	
	while(fscanf(inputFile, "%d;%d\n", &auxId, &auxQuantity) != EOF)
	{
		newProductOrder = (tProductOrder *)malloc(sizeof(tProductOrder));
		newProductOrder->id = auxId;
		newProductOrder->quantity = auxQuantity;
		newProductOrder->nextProduct = NULL;
		if (firstStruct == 1)
		{
			// This is the very first struct, so assign it to orders_firstOrder 
			order->firstProduct = newProductOrder;
			firstStruct = 0;
		}
		else
		{
			// assign next struct in current pointer
			currentProductOrder->nextProduct = newProductOrder;
		}
		
		// move the pointer
		currentProductOrder = newProductOrder;
	} 
	
	fclose(inputFile);
}

