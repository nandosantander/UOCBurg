#ifndef _PRODUCTS_H_
#define _PRODUCTS_H_

#define MIN_PRODUCT_LENGTH 4
#define MAX_PRODUCT_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 128

typedef enum
{
	PRODUCT_NOERR,
	PRODUCT_INVALIDTEXT,
	PRODUCT_INVALIDPRICE,
	PRODUCT_INVALIDCATEGORY,
	PRODUCT_UNDEFINEDERR
} productError;

typedef struct sProduct
{
	int id;
	char text[MAX_PRODUCT_LENGTH];
	char description[MAX_DESCRIPTION_LENGTH];
	float price;
	int category;
	int position;
	struct sProduct * nextProduct;
} tProduct;

tProduct * products_firstProduct;

// Initializes contents of a product struct
void products_initStruct(tProduct * product);

// Gets the latest stored product.
tProduct * products_getLastProduct();

// Gets the highest Id of all the products available on the list.
int products_getHighestId();

// Adds a new product to the list
productError products_addProduct(tProduct * product);

// Transforms the error value enumerate into a string
char * products_errMsg(productError err);

// Verifies the introduced information is valid
productError products_checkProduct(tProduct * product);

// Gets a product struct given its id
tProduct * products_getProductFromId(int id);

// Remove a product object from the list. 
void products_removeProduct(tProduct * productToRemove);

// Alphabetically sorts the list of products. 
void products_sortAlphabetically();

#endif