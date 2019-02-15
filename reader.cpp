#include <iostream>
#include <fstream>
#include <cmath>
#include <random>
#include <ctime>

using namespace std;

/*
	A. Action: Generates a string read from a text file and *RETURNS* it as a single string excluding all chars aside from ACTG and actg
	B. Arguement/s: Name of .txt file to read from
*/
string S_out_Read(string myFile)
{
	char letter;
	string content;
	ifstream inFileStream; //ifstream object

	inFileStream.open(myFile);

	while (!inFileStream.eof()) //while stream pointer has not reached the end of file
	{
		inFileStream >> letter;
		if (letter == 'A' || letter == 'a' ||
			letter == 'T' || letter == 't' ||	//used to remove invalid characters
			letter == 'C' || letter == 'c' ||
			letter == 'G' || letter == 'g'
		  	)
		{
			content += toupper(letter);
		}
		
	}

	inFileStream.close();
	content.pop_back();  //Stack!

	//cout << "\n\nDNA String From Text File Read. - String Returned NOTIFICATION (From Sout_Read Method)\n\n";
	return content;
}
/*	
______________________________________________________________________________________________________________________
	A. Action: Writes a string into a specified text file
	B. Arguement/s: Name of .txt file to write into, content to write)
*/
void V_out_Write(string newFile, string content)
{
	ofstream outFileStream;
	outFileStream.open(newFile);
	outFileStream << content;
	outFileStream.close();
}
/*
______________________________________________________________________________________________________________________
	A. Action: Prints a statistical summary (measures of central tendency and probability) from a specified string and updates mean and standard deviation
	B. Arguement/s: String to summarize, mean and standard deviation data type to update
*/
void V_out_Summarize(string content, double &mean, double &sd)
{
	double A_sum = 0.0;
	double T_sum = 0.0;
	double C_sum = 0.0;
	double G_sum = 0.0;

	double prob_of_A = 0.0;
	double prob_of_T = 0.0;
	double prob_of_C = 0.0;
	double prob_of_G = 0.0;

	mean = 0;
	double variance = 0;
	sd = 0; 

	
	double AA_sum = 0.0;
	double AT_sum = 0.0;
	double AC_sum = 0.0;
	double AG_sum = 0.0;

	double TA_sum = 0.0;
	double TT_sum = 0.0;
	double TC_sum = 0.0;
	double TG_sum = 0.0;

	double CA_sum = 0.0;
	double CT_sum = 0.0;
	double CC_sum = 0.0;
	double CG_sum = 0.0;

	double GA_sum = 0.0;
	double GT_sum = 0.0;
	double GC_sum = 0.0;
	double GG_sum = 0.0;

	double prob_of_AA = 0.0;
	double prob_of_AT = 0.0;
	double prob_of_AC = 0.0;
	double prob_of_AG = 0.0;

	double prob_of_TA = 0.0;
	double prob_of_TT = 0.0;
	double prob_of_TC = 0.0;
	double prob_of_TG = 0.0;

	double prob_of_CA = 0.0;
	double prob_of_CT = 0.0;
	double prob_of_CC = 0.0;
	double prob_of_CG = 0.0;

	double prob_of_GA = 0.0;
	double prob_of_GT = 0.0;
	double prob_of_GC = 0.0;
	double prob_of_GG = 0.0;
	

	double length = content.length();
	int i;
	int j;

	for (i = 0; i < length; i++) 
	{
		if (content[i] == 'A')
		{
			A_sum++;
		}

		else if (content[i] == 'T')
		{
			T_sum++;
		}

		else if (content[i] == 'C')
		{
			C_sum++;
		}

		else if (content[i] == 'G')
		{
			G_sum++;
		}
	}
	
	for (i = 0, j = 1; i < length-1 && j < length; i++, j++) 
	{
		if (content[i] == 'A' && content[j] == 'A')
		{
			AA_sum++;
		}

		else if (content[i] == 'A' && content[j] == 'T')
		{
			AT_sum++;
		}

		else if (content[i] == 'A' && content[j] == 'C')
		{
			AC_sum++;
		}

		else if (content[i] == 'A' && content[j] == 'G')
		{
			AG_sum++;
		}

		/////////////////////////////////////////////////////////

		else if (content[i] == 'T' && content[j] == 'A')
		{
			TA_sum++;
		}

		else if (content[i] == 'T' && content[j] == 'T')
		{
			TT_sum++;
		}

		else if (content[i] == 'T' && content[j] == 'C')
		{
			TC_sum++;
		}

		else if (content[i] == 'T' && content[j] == 'G')
		{
			TG_sum++;
		}

		/////////////////////////////////////////////////////////

		else if (content[i] == 'C' && content[j] == 'A')
		{
			CA_sum++;
		}

		else if (content[i] == 'C' && content[j] == 'T')
		{
			CT_sum++;
		}

		else if (content[i] == 'C' && content[j] == 'C')
		{
			CC_sum++;
		}

		else if (content[i] == 'C' && content[j] == 'G')
		{
			CG_sum++;
		}

		/////////////////////////////////////////////////////////

		else if (content[i] == 'G' && content[j] == 'A')
		{
			GA_sum++;
		}

		else if (content[i] == 'G' && content[j] == 'T')
		{
			GT_sum++;
		}

		else if (content[i] == 'G' && content[j] == 'C')
		{
			GC_sum++;
		}

		else if (content[i] == 'G' && content[j] == 'G')
		{
			GG_sum++;
		}
	}
	

	length = A_sum + T_sum + C_sum + G_sum;

	mean = (A_sum + T_sum + C_sum + G_sum) / 4;
	variance = pow((A_sum - mean),2) + pow((T_sum - mean),2) + pow((C_sum - mean),2) + pow((G_sum - mean),2);
	sd = sqrt(variance);

	prob_of_A = A_sum / length;
	prob_of_T = T_sum / length;
	prob_of_C = C_sum / length;
	prob_of_G = G_sum / length;

	
	prob_of_AA = AA_sum / length;
	prob_of_AT = AT_sum / length;
	prob_of_AC = AC_sum / length;
	prob_of_AG = AG_sum / length;

	prob_of_TA = TA_sum / length;
	prob_of_TT = TT_sum / length;
	prob_of_TC = TC_sum / length;
	prob_of_TG = TG_sum / length;

	prob_of_CA = CA_sum / length;
	prob_of_CT = CT_sum / length;
	prob_of_CC = CC_sum / length;
	prob_of_CG = CG_sum / length;

	prob_of_GA = GA_sum / length;
	prob_of_GT = GT_sum / length;
	prob_of_GC = GC_sum / length;
	prob_of_GG = GG_sum / length;

	
	cout << "Name: Elmer Camargo\nStudent ID#: 2291367\nChapman email: camargop@chapman.edu\n";
	cout << "Course Number and Section: 350-2\nAssignment: 1 - DNA Reader\n";

	cout << "\nProbability A: " << prob_of_A << "\nProbability T: " << prob_of_T;
	cout << "\nProbability C: " << prob_of_C << "\nProbability G: " << prob_of_G << "\n";

	cout << "\nTotal A: " << A_sum << "		Strand Sum: " << length;
	cout << "\nTotal T: " << T_sum << "		Mean: " << mean;
	cout << "\nTotal C: " << C_sum << "		Variance: " << variance;
	cout << "\nTotal G: " << G_sum << "		Standard Deviation: " << sd << "\n";

	cout << "\nProbability AA: " << prob_of_AA << "		Probability AT: " << prob_of_AT;
	cout << "\nProbability AC: " << prob_of_AC << "		Probability AG: " << prob_of_AG;

	cout << "\nProbability TA: " << prob_of_TA << "		Probability TT: " << prob_of_TT;
	cout << "\nProbability TC: " << prob_of_TC << "		Probability TG: " << prob_of_TG;

	cout << "\nProbability CA: " << prob_of_CA << "		Probability CT: " << prob_of_CT;
	cout << "\nProbability CC: " << prob_of_CC << "		Probability CG: " << prob_of_CG;

	cout << "\nProbability GA: " << prob_of_GA << "		Probability GT: " << prob_of_GT;
	cout << "\nProbability GC: " << prob_of_GC << "		Probability GG: " << prob_of_GG << "\n";
}
/*
______________________________________________________________________________________________________________________
	A. Action: Generates and RETURNS the length of a string following standard Gaussian with specified mean and standard deviation   
	B. Arguement/s: Mean and standard deviation to normalize the Gaussian
*/
int I_out_BoxMuller(double mean, double sd)
{
	int normGauss = 0;
	double randA;
	double randB;
	double unnormGauss; 
	const double PI = 3.1415926;

	randA = ((double)rand() / (RAND_MAX));
	randA = ((double)rand() / (RAND_MAX)); //re-calcd bc if only done once rand() generates approx the same number each time
	randB = ((double)rand() / (RAND_MAX));

	unnormGauss = (double) (   (sqrt(-2*log(randA))) * (cos (2*PI*randB))   );

	unnormGauss = (sd * unnormGauss) + mean;

	//cout << "\nmean used" << mean << "\n"; 

	normGauss = (int) unnormGauss;

	//cout << "Gauss "<< normGauss << " - Int Returned NOTIFICATION (From Iout_BoxMuller Method)\n\n";

	//cout << "random variables used " << a << " " << b;

	return normGauss;
}
/*
______________________________________________________________________________________________________________________	
	A. Action: Generates a string of a specified length from randomly selected characters (A, T, C, or G) and RETURNS the string
	B. Arguement/s: Length of string to generate 
*/
string S_out_New_DNA_String(int length)
{
	int i = 0;
	int randInt = 0;

	string DNAstring;

	for (i = 0; i < length; i++)
	{	
		randInt = rand() % 4;

		if (randInt == 0)
		{
			DNAstring += 'A';
		}

		else if (randInt == 1)
		{
			DNAstring += 'T';
		}

		else if (randInt == 2)
		{
			DNAstring += 'C';
		}

		else if (randInt == 3)
		{
			DNAstring += 'G';
		}
	}

	//cout << "- String Returned NOTIFICATION (From Sout_New_DNA_String Method)\n\n";

	return DNAstring;
}
/*
______________________________________________________________________________________________________________________
	A. Action: Prints a shortened statistical summary (relative frequency) from a specified string
	B. Arguement/s: String to summarize, summary report number to update, length of string to analyze
*/
void V_out_ShortSummarize(string content, int summaryNumber, int length)
{
	cout << "\n-------------Summary Number " << summaryNumber+1 << "--------------\n";

	double A_sum = 0.0;
	double T_sum = 0.0;
	double C_sum = 0.0;
	double G_sum = 0.0;

	double prob_of_A = 0.0;
	double prob_of_T = 0.0;
	double prob_of_C = 0.0;
	double prob_of_G = 0.0;

	double mean = 0;
	double variance = 0;
	double sd = 0; 

	int i;
	int j;

	cout <<"\n" << content;

	for (i = 0; i < length; i++) //nucleotide sums
	{
		if (content[i] == 'A')
		{
			A_sum++;
		}

		else if (content[i] == 'T')
		{
			T_sum++;
		}

		else if (content[i] == 'C')
		{
			C_sum++;
		}

		else if (content[i] == 'G')
		{
			G_sum++;
		}
	}

	length = A_sum + T_sum + C_sum + G_sum;

	mean = (A_sum + T_sum + C_sum + G_sum) / 4;
	variance = pow((A_sum - mean),2) + pow((T_sum - mean),2) + pow((C_sum - mean),2) + pow((G_sum - mean),2);
	sd = sqrt(variance);

	prob_of_A = A_sum / length;
	prob_of_T = T_sum / length;
	prob_of_C = C_sum / length;
	prob_of_G = G_sum / length;

	cout << "\nRelative Frequency A: " << prob_of_A << "		Relative Frequency T: " << prob_of_T;
	cout << "\nRelative Frequency C: " << prob_of_C << "		Relative Frequency G: " << prob_of_G << "\n";

	//cout << "\n\n---------------------------\n\n";
}