#ifndef _OFFICES_H_
#define _OFFICES_H_

#define MIN_CATEGORY_LENGTH 4
#define MAX_CATEGORY_LENGTH 32

typedef enum
{
	CATEGORY_NOERR,
	CATEGORY_INVALIDTEXT,
	CATEGORY_REPEATED,
	CATEGORY_UNDEFINEDERR
} categoryError;

typedef struct sCategory
{
	int id;
	char text[MAX_CATEGORY_LENGTH];
	int position;
	struct sCategory * nextCategory;
} tCategory;

tCategory * categories_firstCategory;

// Initializes contents of a category struct
void categories_initStruct(tCategory * category);

// Adds a new category to the list
categoryError categories_addCategory(tCategory * category);

// Verifies the introduced information is valid
categoryError categories_checkCategory(tCategory * category);

// Gets the highest Id of all the categories available on the list.
int categories_getHighestId();

// Gets the latest stored category.
tCategory * categories_getLastCategory();

// Gets a category struct given its id
tCategory * categories_getCategoryFromId(int id);

// Transforms the error value enumerate into a string
char * categories_errMsg(categoryError err);

// Prints the list of categories on screen and requests the user to select one 
tCategory * categories_selectCategory();

// Remove a category object from the list. 
void categories_removeCategory(tCategory * categoryToRemove);

// Alphabetically sort the list of categories.
void categories_sortAlphabetically();

#endif