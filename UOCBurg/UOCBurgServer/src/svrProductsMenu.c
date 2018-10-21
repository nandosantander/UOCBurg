/*
 * File:        svrProductsMenu.c
 * Description: Contains the user interface functionality for the Products related functionality
 * 				Basically, it implements the different menus that will be displayed on the screen
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "svrProductsMenu.h"

#include "helpers.h"
#include "products.h"
#include "categories.h"
#include "operations.h"


/* 
 * Function:    svrProductsMenu_mainMenu
 * Description: Displays the Products sub-menu with the available operations
 * Arguments:   ---
 * Returns:     The option the user selected.
 */
char svrProductsMenu_mainMenu()
{
	char option;
	
	helpers_clearScreen();

	
	printf("\nEdit Products\n");
	printf("\n------------------------------------\n\n");
	
	printf("Please, select a menu option:\n\n");
	printf("1. List Products \n");
    printf("2. Add Product \n");
	printf("3. Remove Product \n");
	printf("4. Sort Products \n");
	printf("\n");
	printf("0. Exit\n\n");

	
	option = helpers_getOption();
	
	return option;
}

/*
 * Function:    svrProductsMenu_addProduct
 * Description: Creates a new Product struct and requests for the information
 * Arguments:   ---
 * Returns:     ---
 */
void svrProductsMenu_addProduct()
{
	tProduct * newProduct = NULL;
	productError err = PRODUCT_NOERR;
	char *errMsg;	
	tCategory * currentCategory;
	
	helpers_clearScreen();

    newProduct = (tProduct*)malloc(sizeof(tProduct));
    products_initStruct(newProduct);
	
    printf("\nAdd a new Product\n");
    printf("\n------------------\n\n");
	
    printf("Text:         ");
    helpers_scanText(newProduct->text, MAX_PRODUCT_LENGTH);
	
    printf("\n\nDescription:  ");
    helpers_scanText(newProduct->description, MAX_DESCRIPTION_LENGTH);
	
	printf("\n\nPrice:        ");
	helpers_scanFloat(&newProduct->price);
    
    printf("\n\nSelect Category: \n\n");
	currentCategory = categories_selectCategory();
	
	if (currentCategory == NULL)
	{
		newProduct->category = 0;
	}
	else
	{
		newProduct->category = currentCategory->id;
	}
	
    err = products_addProduct(newProduct);      

	// Display the result on screen.
	if (err == PRODUCT_NOERR)
	{
		helpers_clearScreen();
		printf("Product successfully added\n");
		printf("\n---------------------------\n\n");
		
		printf("%s\n", newProduct->text);
	}
	else
	{
		// Some error ocurred. Display the error.
		free(newProduct);
		printf("\n\n");
		errMsg = products_errMsg(err);
		printf("\n%s\n", errMsg);
	}
    
	helpers_pressAnyKey();	
}

/*
 * Function:    svrProductsMenu_listProducts
 * Description: Display the list of available products. 
 * Arguments:   ---
 * Returns:     ---
 */
void svrProductsMenu_listProducts()
{
    tProduct * product = products_firstProduct;
    tCategory * category;

	helpers_clearScreen();
	
	int count = 1;
    
    printf("\nList of products\n");
    printf("\n------------------\n\n");
    while(product != NULL){
		category = categories_getCategoryFromId(product->category);
		if (category != NULL)
		{
			printf("%03d - %s (%s) : %.2f E\n", count, product->text, category->text, product->price);
			printf("      %s\n\n", product->description);
			count++;
		}
        product = product->nextProduct;
    }
    
	helpers_pressAnyKey();
}



/*
 * Function:    svrProductsMenu_removeProduct
 * Description: Request the user to select which product to remove from the list.
 * Arguments:   ---
 * Returns:     ---
 */
void svrProductsMenu_removeProduct()
{
	tProduct * currentProduct;
	int option, count;
	
	helpers_clearScreen();
	printf("\n\nRemove product: \n");
	printf("-------------------\n\n");
	
	///
	/// EX.2.2. Display the list of products and let the user choose the product to remove.
	///
	
	currentProduct = products_firstProduct;
	count = 1;
    while(currentProduct != NULL)
	{
		printf("%03d - %s\n", count, currentProduct->text);
		count++;
        currentProduct = currentProduct->nextProduct;
    }
	
	if (count != 1)
    {
		printf("\n\nSelect the product to remove:  ");
		helpers_scanInt(&option);
		
		if (option > 0)
		{
			currentProduct = products_firstProduct;
			count = 1;
			while (currentProduct != NULL)
			{
				if (count >= option)
				{
					break;
				}
				count++;
				currentProduct = currentProduct->nextProduct;
			}
			
			products_removeProduct(currentProduct);
		}
	}
	
	/// END OF EX.2.2.
}
