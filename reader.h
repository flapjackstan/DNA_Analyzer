#include <iostream>
#include <fstream>
#include <cmath>
#include <random>
#include <ctime>

using namespace std;

/*
______________________________________________________________________________________________________________________

	A. Action: Generates a string read from a text file and *RETURNS* it as a single string excluding all chars aside from ACTG and actg
	B. Arguement/s: Name of .txt file to read from
*/
	string S_out_Read(string myFile);
/*
	-Author Comments: n/a
______________________________________________________________________________________________________________________

	A. Action: Writes a string into a specified text file
	B. Arguement/s: Name of .txt file to write into, content to write)
*/
	void V_out_Write(string newFile, string content);
/*
	-Author Comments: n/a
______________________________________________________________________________________________________________________

	A. Action: Prints a statistical summary (measures of central tendency and probability) from a specified string and updates mean and standard deviation
	B. Arguement/s: String to summarize, mean and standard deviation data type to update
*/
	void V_out_Summarize(string content,double &mean, double &sd);
/*
	-Author Comments: n/a
______________________________________________________________________________________________________________________

	A. Action: Generates an int and *RETURNS* the length of a string following standard Gaussian with specified mean and standard deviation   
	B. Arguement/s: Mean and standard deviation to normalize the Gaussian
*/
	int I_out_BoxMuller(double mean, double sd);
/*
	-Author Comments: n/a
______________________________________________________________________________________________________________________	

	A. Action: Generates a string of a specified length from randomly selected characters (A, T, C, or G) and *RETURNS* the string
	B. Arguement/s: Length of string to generate 
*/
	string S_out_New_DNA_String(int length);
/*
	-Author Comments: n/a
______________________________________________________________________________________________________________________	

	A. Action: Prints a shortened statistical summary (relative frequency) from a specified string
	B. Arguement/s: String to summarize, summary report number to update, length of string to analyze 
*/
	void V_out_ShortSummarize(string content, int summaryNumber, int length);

//	-Author Comments: n/a