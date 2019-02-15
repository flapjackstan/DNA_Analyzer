/*
Name: Elmer Camargo
Student ID#: 2291367
Chapman email: camargop@chapman.edu
Course Number and Section: 350-2
Assignment: 1 - DNA Reader
*/

#include <iostream>  
#include <fstream>
#include <cmath>
#include <random>
#include <ctime>

#include "reader.h"

using namespace std;

/*
Overview: Reads a string of nucleotides, summarizes it, and returns 1000 strings of nucleotides following a Gaussian Distribution based of summarized results.
Requirements to execute: This program requires a command line arguement of a text file to initiate. 

*/
int main (int argc, char* argv[])
{

	//initializations on stack to be deleted upon program termination

	srand(static_cast<unsigned int>(std::time(nullptr)));  //used as a seed to create random numbers
	
	int in_gaussian = 0; //int will always have a positive value
	short int response = 1; //int will change to be larger than 2 bytes (16bits - values 1-510) [unless user inputs something otherwise]
	int length = 0; //int will always have a positive value
	int newDesiredLength = 0; //int will always have a positive value
	double mean = 0; //mean returned may exceed 8 bytes (2.22507e-308 or 0x1p-1022)
	double sd = 0; //see above
	string in_dnaString = "";
	string in_newDNAString = "";

	cout << "\n---------------------------\n";  // using "\n" instead of "endl" - see reference 4.i (Cpp Core Guidelines SL.io.50: Avoid endl)

	in_dnaString = argv[1];

	while(response == 1)
	{

		in_dnaString = S_out_Read(in_dnaString);
		length = in_dnaString.length();
		V_out_Summarize(in_dnaString, mean, sd);

		newDesiredLength = 1000;

			for(int summaryNumber = 0; summaryNumber < newDesiredLength; summaryNumber++)
			{
				in_gaussian = I_out_BoxMuller(mean, sd);
				in_newDNAString = S_out_New_DNA_String(in_gaussian);
				V_out_ShortSummarize(in_newDNAString, summaryNumber, in_gaussian);
			}

		cout << "\nWould you like to process another file? Press 1 for yes, 0 for no. ";
		cin >> response;

			if(response == 1)
			{
				cout << "\nPlease input next file: ";
				cin >> in_dnaString;
			}

			else
			response = 0;
	}

	cout << "\n---------------------------\n";
	return 0;

}