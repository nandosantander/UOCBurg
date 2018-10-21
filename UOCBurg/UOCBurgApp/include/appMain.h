#ifndef _APPMAIN_H_
#define _APPMAIN_H_

/*
 * File:        appMain.c
 * Description: Contains the main functionality for the application
 */

#include "appMain.h"

#include "operations.h"
#include "categories.h"
#include "products.h"
#include "helpers.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Displays the UOCBurg application main menu with the available operations
char appMain_mainMenu();

// Displays the UOCBurg application main menu
void appMain_displayMenu();

// Description: Requests the user the information to process the new order.
void appMain_newOrder();


#endif