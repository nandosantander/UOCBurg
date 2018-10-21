#ifndef _HELPERS_H_
#define _HELPERS_H_


/*
 * 
 * IMPORTANT NOTE: ¡¡¡¡Do not add new methods in this file!!!!
 *
 */
 
#include <stdio.h>

char helpers_option;
int helpers_int;
char helpers_text[32];

typedef struct
{
	int year;
	int month;
	int day;
	int hour;
	int minute;
} tDateTime;

// Used to clear the output screen
void helpers_clearScreen();

// Flushes the standard input
void helpers_clearInputBuffer();

// reads a key input from the user.
char helpers_getOption();

// waits until user presses any key
void helpers_pressAnyKey();

// Parses and gets an string manually introduced by the user until it presses the Enter.
void helpers_scanText(char * property, int maxValue);

// Parses and gets an integer value manually introduced by the user.
void helpers_scanInt(int * retValue);

// Parses and gets a floating double value manually introduced by the user.
void helpers_scanFloat(float * retValue);

// Parses and gets a datetime in format yyyy/mm/dd hh:mm
void helpers_scanDateTime(tDateTime * retValue);

// Parses and gets an string written on a file until finding the delimiter character or a new line.
char * helpers_scanFromFile(FILE * inputFile, char delimiter, int maxValue);

// Copies the content of a file into another file
void helpers_copyFile(FILE * inFile, FILE * outFile);

#endif
