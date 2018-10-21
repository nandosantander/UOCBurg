/*
 * File:        categories.c
 * Description: Contains the functionality related to the categories management.
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "categories.h"
#include "operations.h"
 
 
/*
 * Function:    categories_initStruct
 * Description: Initializes contents of a category struct
 * Arguments:   category: Upon return, the category struct ready to be filled
 * Returns:     ---
 */
void categories_initStruct(tCategory * category)
{
	memset(category->text, 0, MAX_CATEGORY_LENGTH);
	category->id = 0;
	category->position = 0;
	category->nextCategory = NULL;
}


/*
 * Function:    categories_addCategory
 * Description: Adds a new category to the list
 * Arguments:   ---
 * Returns:     An enum with the error code according to the validation of the data.
 */
categoryError categories_addCategory(tCategory * category)
{
	categoryError err;
    tCategory * lastCategory;
	
	// Verify the category introduced is correct
	err = categories_checkCategory(category);
	if (err != CATEGORY_NOERR)
	{
		return err;
	}
	
	// Determine a unique identifier for the category
	category->id = categories_getHighestId() + 1;
	
	// Add the item at the very end of the list.
	if (categories_firstCategory == NULL)
	{
		categories_firstCategory = category;
	}
	else
	{
		lastCategory = categories_getLastCategory();
		if (lastCategory == NULL)
		{
			return CATEGORY_UNDEFINEDERR;
		}
		lastCategory->nextCategory = category;
	}
	
	ops_saveCategoriesList(category);
	
	return CATEGORY_NOERR;
}



/*
 * Function:    categories_checkCategory
 * Description: Verifies the introduced information is valid
 * Arguments:   category: The category struct to be validated
 * Returns:     The error message
 */ 
categoryError categories_checkCategory(tCategory * category)
{	
    int len;
	tCategory * currentCategory = categories_firstCategory;
	
	if (category == NULL)
	{
		return CATEGORY_UNDEFINEDERR;
	}
		
    len = strlen(category->text);  
    if ((len < MIN_CATEGORY_LENGTH) || (len >= MAX_CATEGORY_LENGTH))
	{
        return CATEGORY_INVALIDTEXT;
    }
     
	// Follow the list to validate if there is any category with the same name
	while (currentCategory != NULL)
	{
		if (!strcmp(currentCategory->text, category->text))
		{
			return CATEGORY_REPEATED;
		}
		currentCategory = currentCategory->nextCategory;
	}   
	
	return CATEGORY_NOERR;
}


/*
 * Function: 	categories_getHighestId
 * Description: Gets the highest Id of all the categories available on the list.
 * Arguments:   ---
 * Returns: 	The highest Id.
 */
int categories_getHighestId()
{
	int retValue = 0;
	
	tCategory * category = categories_firstCategory;
	if (category == NULL)
	{
		return retValue;
	}
	
	retValue = category->id;
	
	while (category->nextCategory != NULL)
	{
		category = category->nextCategory;
		if (category->id > retValue)
		{
			retValue = category->id;
		}
	}
	
	return retValue;
}


/*
 * Function: 	categories_getLastCategory
 * Description: Gets the latest stored category.
 * Arguments:   ---
 * Returns: 	The pointer to the latest stored category
 */
tCategory * categories_getLastCategory()
{
	tCategory * retValue = NULL;

	retValue = categories_firstCategory;
	
	if (retValue == NULL)
	{
		return categories_firstCategory;
	}
	
	while (retValue->nextCategory != NULL)
	{
		retValue = retValue->nextCategory;
	}
	
	return retValue;
}


/*
 * Function: 	categories_getCategoryFromId
 * Description: Gets a category struct given its id
 * Arguments:   Id: The id to look for
 * Returns: 	The category struct matching this id. Null if not found.
 */
tCategory * categories_getCategoryFromId(int id)
{
	tCategory * category = categories_firstCategory;
	
	while (category != NULL)
	{
		if (category->id == id)
		{
			return category;
		}
		category = category->nextCategory;
	}
	
	return NULL;
}

/*
 * Function:    categories_errMsg
 * Description: Transforms the error value enumerate into a string
 * Arguments:   The error value
 * Returns:     The string to display to the user
 */ 
char * categories_errMsg(categoryError err)
{
	switch(err)
	{
		case CATEGORY_INVALIDTEXT: 
		    return "The Category text is invalid. It must have between 4 & 32 letters.\n";
						
		case CATEGORY_UNDEFINEDERR:
			return "Undefined error.\n";
			
		case CATEGORY_REPEATED:
			return "The name already exists in the database.\n";
			
		default:
			return "";
	}
}

/*
 * Function:    categories_selectCategory
 * Description: Prints the list of categories on screen and requests the user to select one 
 * Arguments:   ---
 * Returns:     The pointer to the selected category
 */ 
tCategory * categories_selectCategory()
{
	tCategory * currentCategory;
	int option, count = 1;
	
	categories_sortAlphabetically();
	
	currentCategory = categories_firstCategory;
    while(currentCategory != NULL)
	{
        printf("%03d - %s\n", count, currentCategory->text);
        count++;
        currentCategory = currentCategory->nextCategory;
    }
    
	printf("\n");
	
	helpers_scanInt(&option);
	
	if (option == 0)
	{
		return NULL;
	}
	
	currentCategory = categories_firstCategory;
    count = 1;
	while ((currentCategory != NULL) && (count < option))
	{
        currentCategory = currentCategory->nextCategory;
		count++;
    }
	
	return currentCategory;
}


/*
 * Function:    categories_removeCategory
 * Description: Remove a category object from the list. 
 * Arguments:   categoryToRemove: The pointer to the category object to remove.
 * Returns:     ---
 */
void categories_removeCategory(tCategory * categoryToRemove)
{
	tCategory * currentCategory;
	tProduct * currentProduct, * nextProduct;
	char categoryName[MAX_CATEGORY_LENGTH];

	strcpy(categoryName, categoryToRemove->text);
	
	///
	/// EX.3.1. Remove the category from the list.
	///

	if (categoryToRemove != NULL)
	{
		// First remove all products this category has
		currentProduct = products_firstProduct;
		
		while(currentProduct != NULL)
		{
			nextProduct = currentProduct->nextProduct;
			if (currentProduct->category == categoryToRemove->id)
			{
				products_removeProduct(currentProduct);
			}
			currentProduct = nextProduct;
		}
        
		// And now remove the product from the list.
		if (categoryToRemove == categories_firstCategory)
		{
			categories_firstCategory = categoryToRemove->nextCategory;
			free(categoryToRemove);
		}
		else
		{
			currentCategory = categories_firstCategory;
			while ((currentCategory != NULL) && (currentCategory->nextCategory != categoryToRemove))
			{
				currentCategory = currentCategory->nextCategory;
			}
			if (currentCategory != NULL)
			{
				currentCategory->nextCategory = categoryToRemove->nextCategory;
				free(categoryToRemove);
			}
		}
    }
	
	/// END OF EX.3.1
	ops_saveCategoriesList();
	helpers_clearScreen();
	printf("\nCategory '%s' removed\n\n", categoryName);
	helpers_pressAnyKey();
}

/*
 * Function:    categories_sortAlphabetically
 * Description: Alphabetically sorts the list of categories.
 * Arguments:   ---
 * Returns:     ---
 */ 
void categories_sortAlphabetically()
{
	///
	/// EX.4.2. Sort the list of categories alphabetically
	///
	
	tCategory * currentCategory, * nextCategory, * previousCategory;
	int sorted;
	
	sorted = 0;
	
	while (sorted == 0)
	{
		sorted = 1;
		previousCategory = NULL;
		currentCategory = categories_firstCategory;
		if (currentCategory != NULL)
		{
			nextCategory = currentCategory->nextCategory;
		}
		else
		{
			nextCategory = NULL;
		}
		while ((nextCategory != NULL) && (sorted == 1))
		{
			// strcmp returns a negative value when 1st argument is alphabetically lower than 2nd.
			if (strcmp(currentCategory->text, nextCategory->text) > 0 )
			{
				// We have to swap the elements in the list and re-start the algorithm.
				currentCategory->nextCategory = nextCategory->nextCategory;
				nextCategory->nextCategory = currentCategory;
				if (previousCategory == NULL)
				{
					categories_firstCategory = nextCategory;
				}
				else
				{
					previousCategory->nextCategory = nextCategory;
				}
				previousCategory = nextCategory;
				
				// This flag indicates we should start again the loop from the very beginning.
				sorted = 0;
			}
			else
			{
				// The categories are alphabetically sorted, so move forward and keep on with the next one.
				previousCategory = currentCategory;
				currentCategory = nextCategory;
				nextCategory = nextCategory->nextCategory;
			}
		}
	}
	
	
	/// END OF EX.4.2
}