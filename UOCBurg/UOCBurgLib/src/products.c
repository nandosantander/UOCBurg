/*
 * File:        products.c
 * Description: Contains the functionality related to the products management.
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "products.h"
#include "categories.h"
#include "operations.h"

/*
 * Function:    products_initStruct
 * Description: Initializes contents of a product struct
 * Arguments:   product: Upon return, the product struct ready to be filled
 * Returns:     ---
 */
void products_initStruct(tProduct * product)
{
	memset(product->text, 0, MAX_PRODUCT_LENGTH);
	memset(product->description, 0, MAX_DESCRIPTION_LENGTH);
	product->id = 0;
	product->price = 0;
	product->category = 0;
	product->position = 0;
	product->nextProduct = NULL;
}


/*
 * Function: 	products_getLastProduct
 * Description: Gets the latest stored product.
 * Arguments:   ---
 * Returns: 	The pointer to the latest stored product
 */
tProduct * products_getLastProduct()
{
	tProduct * retValue = NULL;

	retValue = products_firstProduct;
	
	if (retValue == NULL)
	{
		return products_firstProduct;
	}
	
	while (retValue->nextProduct != NULL)
	{
		retValue = retValue->nextProduct;
	}
	
	return retValue;
}


/*
 * Function: 	products_getHighestId
 * Description: Gets the highest Id of all the products available on the list.
 * Arguments:   ---
 * Returns: 	The highest Id.
 */
int products_getHighestId()
{
	int retValue = 0;
	
	tProduct * product = products_firstProduct;
	if (product == NULL)
	{
		return retValue;
	}
	
	retValue = product->id;
	
	while (product->nextProduct != NULL)
	{
		product = product->nextProduct;
		if (product->id > retValue)
		{
			retValue = product->id;
		}
	}
	
	return retValue;
}


/*
 * Function:    products_addProduct
 * Description: Adds a new product to the list
 * Arguments:   ---
 * Returns:     An enum with the error code according to the validation of the data.
 */
productError products_addProduct(tProduct * product)
{
	productError err;
	tProduct * lastProduct;
    
	// Verify the product introduced is correct
	err = products_checkProduct(product);
	if (err != PRODUCT_NOERR)
	{
		return err;
	}
	
	// Determine a unique identifier for the category
	product->id = products_getHighestId() + 1;
	
	// Add the item at the very end of the list.
	if (products_firstProduct == NULL)
	{
		products_firstProduct = product;
	}
	else
	{
		lastProduct = products_getLastProduct();
		if (lastProduct == NULL)
		{
			return PRODUCT_UNDEFINEDERR;
		}
		lastProduct->nextProduct = product;
	}
	
	ops_saveProductsList();
	ops_saveProductDescription(product);
	
	return PRODUCT_NOERR;
}


/*
 * Function:    products_checkProduct
 * Description: Verifies the introduced information is valid
 * Arguments:   product: The product struct to be validated
 * Returns:     The error message
 */ 
productError products_checkProduct(tProduct * product)
{	
    int len;
    tCategory * category;
	
	if (product == NULL)
	{
		return PRODUCT_UNDEFINEDERR;
	}
	
    len = strlen(product->text);  
    if ((len < MIN_PRODUCT_LENGTH) || (len >= MAX_PRODUCT_LENGTH))
	{
        return PRODUCT_INVALIDTEXT;
    }
    
	if (product->price < 0)
	{
		return PRODUCT_INVALIDPRICE;
	}
		
	category = categories_getCategoryFromId(product->category);
	if (category == NULL)
	{
		return PRODUCT_INVALIDCATEGORY;
	}
    
    return PRODUCT_NOERR;
}

/*
 * Function:    products_errMsg
 * Description: Transforms the error value enumerate into a string
 * Arguments:   The error value
 * Returns:     The string to display to the user
 */ 
char * products_errMsg(productError err)
{
	switch(err)
	{
		case PRODUCT_INVALIDTEXT:
		    return "The Product text is invalid. It must have between 4 & 32 letters.\n";
			
		case PRODUCT_INVALIDPRICE:
			return "The Product price is invalid. It must be a positive value.\n";
			
		case PRODUCT_INVALIDCATEGORY:
			return "The Product category is invalid.\n";
			
		case PRODUCT_UNDEFINEDERR:
			return "Undefined error.\n";
			
		default:
			return "";
	}
}


/*
 * Function: 	products_getProductFromId
 * Description: Gets a product struct given its id
 * Arguments:   Id: The id to look for
 * Returns: 	The product struct matching this id. Null if not found.
 */
tProduct * products_getProductFromId(int id)
{
	tProduct * product = products_firstProduct;
	
	while (product != NULL)
	{
		if (product->id == id)
		{
			return product;
		}
		product = product->nextProduct;
	}
	
	return NULL;
}



/*
 * Function:    products_removeProduct
 * Description: Remove a product object from the list. 
 * Arguments:   productToRemove: The pointer to the product object to remove.
 * Returns:     ---
 */
void products_removeProduct(tProduct * productToRemove)
{
	tProduct * currentProduct;
	char filename[32];
	char productName[MAX_PRODUCT_LENGTH];
	
	strcpy(productName, productToRemove->text);
	
	///
	/// EX.2.1. Remove the product from the list
	///
	
	if (productToRemove != NULL)
	{
		// First remove the file
		sprintf(filename, OPS_PRODUCT_DESC_FILE, productToRemove->id);
		remove(filename); 
		
		// And now remove the product from the list.
		if (productToRemove == products_firstProduct)
		{
			products_firstProduct = productToRemove->nextProduct;
			free(productToRemove);
		}
		else
		{
			currentProduct = products_firstProduct;
			while ((currentProduct != NULL) && (currentProduct->nextProduct != productToRemove))
			{
				currentProduct = currentProduct->nextProduct;
			}
			if (currentProduct != NULL)
			{
				currentProduct->nextProduct = productToRemove->nextProduct;
				free(productToRemove);
			}
		}
	}
	
	
	/// END OF EX.2.1
	
	ops_saveProductsList();
	helpers_clearScreen();
	printf("\nProduct '%s' removed\n\n", productName);
	helpers_pressAnyKey();
}


/*
 * Function:    products_sortAlphabetically
 * Description: Alphabetically sorts the list of products.
 * Arguments:   ---
 * Returns:     ---
 */ 
void products_sortAlphabetically()
{
	///
	/// EX.4.1. Sort the list of products alphabetically
	///
	
	tProduct * currentProduct, * nextProduct, * previousProduct;
	int sorted;
	
	sorted = 0;
	
	while (sorted == 0)
	{
		sorted = 1;
		previousProduct = NULL;
		currentProduct = products_firstProduct;
		if (currentProduct == NULL)
		{
			nextProduct = NULL;
		}
		else
		{
			nextProduct = currentProduct->nextProduct;
		}
		
		
		while ((nextProduct != NULL) && (sorted == 1))
		{
			// strcmp returns a negative value when 1st argument is alphabetically lower than 2nd.
			if (strcmp(currentProduct->text, nextProduct->text) > 0 )
			{
				// We have to swap the elements in the list and re-start the algorithm.
				currentProduct->nextProduct = nextProduct->nextProduct;
				nextProduct->nextProduct = currentProduct;
				if (previousProduct == NULL)
				{
					products_firstProduct = nextProduct;
				}
				else
				{
					previousProduct->nextProduct = nextProduct;
				}
				previousProduct = nextProduct;
				
				// This flag indicates we should start again the loop from the very beginning.
				sorted = 0;
			}
			else
			{
				// The products are alphabetically sorted, so move forward and keep on with the next one.
				previousProduct = currentProduct;
				currentProduct = nextProduct;
				nextProduct = nextProduct->nextProduct;
			}
		}
	}
	
	/// END OF EX.4.1
}