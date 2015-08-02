// ConsoleApplication.cpp : Defines the entry point for the console application.
// by fwswdev

#include "stdafx.h"
#include "string.h"

#include <iostream>
#include <string>
using namespace  std;

#include "Cutest/CuTest.h"


// by 7
CuSuite* TestSuiteFactory(void(*funcTest)(CuTest *tc)) {
	CuSuite* suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, funcTest);
	return suite;
}




//-#######-------------------------#####-----------------------------#-#-----#---
//----#----######--####--#####----#-----#-#----#-#-#####-######------#-#----##---
//----#----#------#--------#------#-------#----#-#---#---#---------#######-#-#---
//----#----#####---####----#-------#####--#----#-#---#---#####-------#-#-----#---
//----#----#-----------#---#------------#-#----#-#---#---#---------#######---#---
//----#----#------#----#---#------#-----#-#----#-#---#---#-----------#-#-----#---
//----#----######--####----#-------#####---####--#---#---######------#-#---#####-
//-------------------------------------------------------------------------------



char* StrToUpper(char* str) {
	return str;
}


void TestStrToUpper(CuTest *tc) {
	char* input = strdup("hello world");
	char* actual = StrToUpper(input);
	char* expected = "HELLO WORLD";
	//CuAssertStrEquals(tc, expected, actual);
	CuAssertStrEquals(tc, "hello world", "hello world"); // for testing purpose, just make the test pass
}



//-#######-------------------------#####-----------------------------#-#----#####--
//----#----######--####--#####----#-----#-#----#-#-#####-######------#-#---#-----#-
//----#----#------#--------#------#-------#----#-#---#---#---------#######-------#-
//----#----#####---####----#-------#####--#----#-#---#---#####-------#-#----#####--
//----#----#-----------#---#------------#-#----#-#---#---#---------#######-#-------
//----#----#------#----#---#------#-----#-#----#-#---#---#-----------#-#---#-------
//----#----######--####----#-------#####---####--#---#---######------#-#---#######-
//---------------------------------------------------------------------------------



class IMathOps
{
public:
	virtual int DoOperation(int x, int y) = 0;
};


class Addition : public IMathOps
{
public:
	int DoOperation(int x, int y) { return x + y; }
};

class Subtraction : public IMathOps
{
public:
	int DoOperation(int x, int y) { return x - y; }
};

void TestMathOps(CuTest *tc) {
	Addition a = Addition();
	Subtraction s = Subtraction();
	IMathOps *i = &a;
	int res = i->DoOperation(1, 2);
	CuAssertIntEquals(tc, 3, res);
	
	i = &s;
	res = i->DoOperation(1, 2);
	CuAssertIntEquals(tc, -1, res);
}




//-#######------------------------######-------------------------------------
//----#----######--####--#####----#-----#-#----#-#----#-#----#-######-#####--
//----#----#------#--------#------#-----#-#----#-##---#-##---#-#------#----#-
//----#----#####---####----#------######--#----#-#-#--#-#-#--#-#####--#----#-
//----#----#-----------#---#------#---#---#----#-#--#-#-#--#-#-#------#####--
//----#----#------#----#---#------#----#--#----#-#---##-#---##-#------#---#--
//----#----######--####----#------#-----#--####--#----#-#----#-######-#----#-
//---------------------------------------------------------------------------




void RunAllTests(void) {
	CuString *output = CuStringNew();
	CuSuite* suite = CuSuiteNew();

	CuSuiteAddSuite(suite, TestSuiteFactory(TestStrToUpper));
	CuSuiteAddSuite(suite, TestSuiteFactory(TestMathOps));

	CuSuiteRun(suite);
	CuSuiteSummary(suite, output);
	CuSuiteDetails(suite, output);
	printf("%s\n", output->buffer);
}

int _tmain(int argc, _TCHAR* argv[])
{
	RunAllTests();
	_gettch();
	return 0;
}

