#ifndef _SVRREPORTSMENU_H_
#define _SVRREPORTSMENU_H_

typedef enum
{
	SVRREPORT_TODAY,
	SVRREPORT_YEAR,
	SVRREPORT_FULL
} reportType;

// Displays the Reports sub-menu with the available operations
char svrReportsMenu_mainMenu();

// Displays the report of the orders made during today 
void svrReportsMenu_todayReport();

// Displays the report of the orders made during this year 
void svrReportsMenu_yearReport();

// Displays the report of all the historic data 
void svrReportsMenu_fullReport();

// Generates the report according the selected option 
void svrReportsMenu_generateReport(reportType type);

#endif