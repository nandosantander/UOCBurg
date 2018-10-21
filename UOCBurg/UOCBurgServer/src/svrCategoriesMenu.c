/*
 * File:        svrCategoriesMenu.c
 * Description: Contains the user interface functionality for the Categories related functionality
 * 				Basically, it implements the different menus that will be displayed on the screen
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "svrCategoriesMenu.h"

#include "helpers.h"
#include "categories.h"


/* 
 * Function:    svrCategoriesMenu_mainMenu
 * Description: Displays the Categories sub-menu with the available operations
 * Arguments:   ---
 * Returns:     The option the user selected.
 */
char svrCategoriesMenu_mainMenu()
{
	char option;

	helpers_clearScreen();
	
	printf("\nEdit Categories\n");
	printf("\n------------------------------------\n\n");
	
	printf("Please, select a menu option:\n\n");
	printf("1. List Categories \n");
    printf("2. Add Category \n");
	printf("3. Remove Category \n");
	printf("4. Sort Categories \n");
	printf("\n");
	printf("0. Exit\n\n");

	option = helpers_getOption();
	
	return option;
}

/*
 * Function:    svrCategoriesMenu_addCategory
 * Description: Creates a new Category struct and requests for the information
 * Arguments:   ---
 * Returns:     ---
 */
void svrCategoriesMenu_addCategory()
{
	tCategory * newCategory = NULL;
	categoryError err = CATEGORY_NOERR;
	char *errMsg;

	helpers_clearScreen();
	
    newCategory = (tCategory*)malloc(sizeof(tCategory));
    categories_initStruct(newCategory);
    
    printf("\nAdd a new Category\n");
    printf("\n------------------\n\n");
	
    printf("Text:        ");
    helpers_scanText(newCategory->text, MAX_CATEGORY_LENGTH);
	
    printf("\n");
    
    err = categories_addCategory(newCategory);      

	// Display the result on screen.
	if (err == CATEGORY_NOERR)
	{
		helpers_clearScreen();
		printf("\nCategory successfully added\n");
		printf("\n---------------------------\n\n");
		
		printf("%s\n", newCategory->text);
	}
	else
	{
		// Some error ocurred. Display the error.
		free(newCategory);
		printf("\n\n");
		errMsg = categories_errMsg(err);
		printf("\n%s\n", errMsg);
	}
    
	helpers_pressAnyKey();	
}

/*
 * Function:    svrCategoriesMenu_listCategories
 * Description: Display the list of available categories. 
 * Arguments:   ---
 * Returns:     ---
 */
void svrCategoriesMenu_listCategories()
{
	helpers_clearScreen();
    
    tCategory *category = categories_firstCategory;
    
	int count = 1;
    
    printf("\nList of categories\n");
    printf("\n------------------\n\n");
	
    while(category != NULL)
	{
        printf("%03d - %s\n\n", count, category->text);
        count++;
        category = category->nextCategory;
    }
    
	helpers_pressAnyKey();
}


/*
 * Function:    svrCategoriesMenu_removeCategory
 * Description: Request the user to select which category to remove from the list. 
 * Arguments:   ---
 * Returns:     ---
 */
void svrCategoriesMenu_removeCategory()
{
	tCategory * categoryToRemove;
	
	helpers_clearScreen();
	printf("\n\nRemove Category: \n\n");
	printf("-------------------\n\n");
	
	///
	/// EX.3.2. Display the list of categories and let the user choose the category to remove.
	///

	categoryToRemove = categories_selectCategory();

	if (categoryToRemove != NULL)
	{
		categories_removeCategory(categoryToRemove);
	}
	
	// END OF EX.3.2.
}
