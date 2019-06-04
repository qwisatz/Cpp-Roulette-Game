#include <iostream>
#include <cstdlib>   // rand and srand
#include <ctime>
#include <string>
#include <array>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>

int RandU(int nMin, int nMax) {
	// Get the system time.
	unsigned seed = time(0);

	// Seed the random number generator.
	srand(seed);

	// RANDOMISE THE NUMBER
	rand();

	return nMin + (int) ((double) rand() / (RAND_MAX + 1) * (nMax - nMin + 1));
}

int main() {

	std::cout << "=================================================="
			<< std::endl;
	std::cout << "                      START!" << std::endl;
	std::cout << "=================================================="
			<< std::endl;

	//================================================================
	// VAR: TABLE
	//================================================================
	// values for controlling format
	const int int_width = 7;
	const int num_flds = 7;
	const std::string sep = " |";
	const int total_width = int_width * 2 + int_width * 2
			+ sep.size() * num_flds;
	const std::string line = sep + std::string(total_width - 1, '-') + '|';

	//================================================================
	// POINTERS
	//================================================================
	std::string win("win");
	std::string lose("lose");
	std::string none("none");

	// CREATE POINTERS TO POINT TO COMMONLY USED STRING VALUES
	std::string* pWinLoseNum;
	std::string* pWinLoseColour;
	std::string* pWinOddEven;
	std::string* pWinLoseHighLow;

	// TO GET VALUE INSTAD OF PRINTING ADDRESS:
	// *pWinLoseNum
	pWinLoseNum = &none;
	pWinLoseColour = &none;
	pWinOddEven = &none;
	pWinLoseHighLow = &none;

	//================================================================
	// VAR
	//================================================================
	// PLAYER INPUTS
	int inputNum;
	std::string inputColour;
	std::string inputLowHighBet;
	std::string inputOddEven;

	// RANDOM NUMBER
	int numRouletteMin;
	int numRouletteMax;

	int numRand;
	std::string numColour;
	std::string numLowHighBet;
	std::string numOddEven;

	// STATS
	std::string winNum;
	std::string winColour;
	std::string winLowHighBet;
	std::string winOddEven;

	//================================================================
	// READ IN CSV FILES
	//================================================================
	// COLOUR ARRAY
	// std::array<int, 18> red = { 1, 3, 5, 7, 9, 12, 14, 16, 18, 19, 21, 23, 25, 27, 30, 32, 34, 36 };
	//std::array<int, 18> black = { 2, 4, 6, 8, 10, 11, 13, 15, 17, 20, 22, 24, 26, 28, 29, 31, 33, 35 };

	//================================================================
	// RED NUMBERS
	//================================================================
	std::ifstream in("red2.csv");
	std::vector<std::vector<int>> fields;
	if (in) {
		std::string line;

		while (getline(in, line)) {
			std::stringstream sep(line);
			std::string field;
			fields.push_back(std::vector<int>());
			while (getline(sep, field, ',')) {
				fields.back().push_back(stod(field));
			}
		}
	}

	std::array<int, 18> red;
	// RED ARRAY FORLOOP
	int iLoop = 0;

	// ITERATING THROUGH FIELDS AND ADDING IT TO INT RED ARRAY
	for (auto row : fields) {
		for (auto field : row) {
			red[iLoop] = field;
			iLoop++;
		}
	}

	std::cout << "RED NUMBERS FROM ARRAY" << std::endl;
	for (int i = 0; i < red.size(); i++) {
		std::cout << red[i] << std::endl;
	}

	//================================================================
	// BLACK NUMBERS
	//================================================================
	std::ifstream in2("black2.csv");
	// CREATE ARRAY
	std::vector<std::vector<int>> fields2;

	// IF FILE EXISTS
	if (in2) {
		std::string line;

		while (getline(in2, line)) {
			std::stringstream sep(line);
			std::string field;
			fields2.push_back(std::vector<int>());
			while (getline(sep, field, ',')) {
				fields2.back().push_back(stod(field));
			}
		}
	}

	std::array<int, 18> black;
	// RED ARRAY FORLOOP
	iLoop = 0;

	// ITERATING THROUGH FIELDS AND ADDING IT TO INT RED ARRAY
	for (auto row : fields2) {
		for (auto field : row) {
			black[iLoop] = field;
			iLoop++;
		}
	}

	std::cout << "BLACK NUMBERS FROM ARRAY" << std::endl;
	for (int i = 0; i < black.size(); i++) {
		std::cout << black[i] << std::endl;
	}

	//================================================================
	// INITIALISE VALUES
	//================================================================
	inputNum = 14;
	inputColour = "red";
	inputLowHighBet = "high";
	inputOddEven = "even";

	numRouletteMin = 0;
	numRouletteMax = 36;

	numColour = "none";

	// PRINT OUT INPUTS
	std::cout << "INPUT NUM = " << inputNum << std::endl;
	std::cout << "INPUT COLOUR = " << inputColour << std::endl;
	std::cout << "INPUT ODD/EVEN = " << inputOddEven << std::endl;
	std::cout << "INPUT LOW HIGH BET = " << inputLowHighBet << '\n'
			<< std::endl;

	//================================================================
	// RANDOM NUM
	//================================================================
	numRand = RandU(numRouletteMin, numRouletteMax);
	std::cout << "RANDOM NUMBER = " << numRand << '\n' << std::endl;

	//================================================================
	// COLOUR ARRAY
	//================================================================
	std::cout << "RED NUMBERS" << std::endl;
	for (int i = 0; i < red.size(); i++) {
		std::cout << red[i] << std::endl;
	}

	std::cout << "BLACK NUMBERS" << std::endl;
	for (int i = 0; i < black.size(); i++) {
		std::cout << black[i] << std::endl;
	}

	// LOOP THROUGH ARRAY AND SEE WHICH COLOUR THE RANDOM NUMBER
	for (int i = 0; i < red.size(); i++) {
		if (red[i] == numRand) {
			numColour = "red";
			break;
		}
	}

	for (int i = 0; i < black.size(); i++) {
		if (black[i] == numRand) {
			numColour = "black";
			break;
		}
	}

	if (numRand == 0) {
		numColour = "green";
	}

	std::cout << '\n' << std::endl;

	//================================================================
	// CHECK IF ODD/EVEN
	//================================================================

	if (numRand % 2 == 0) {
		std::cout << numRand << " is even." << std::endl;
		;
		numOddEven = "even";
	} else {
		std::cout << numRand << " is odd." << std::endl;
		numOddEven = "odd";
	}
	//================================================================
	// LOW HIGH BET
	//================================================================
	// CHECK IF INPUT IS LOW OR HIGH
	// CHECK RAND IN LOW OR HIGH
	// LOW = 1-18
	// HIGH 19-36

	// COULD USE POINTERS FOR STRINGS LOW AND HIGH
	if (numRand >= 1 && numRand < 18) {
		numLowHighBet = "low";
	} else if (numRand > 18) {
		numLowHighBet = "high";
	} else {
		numLowHighBet = "none";
	}

	std::cout << "lowHighBet OF BALL= " << numLowHighBet << std::endl;

	//================================================================
	// RESULT: SPECIFIC NUMBER
	//================================================================
	// check the boolean condition
	if (inputNum == numRand) {
		//SET POINTERS
		pWinLoseNum = &win;

		// if condition is true then print the following
		//std::cout << "WINNER SPECIFIC NUMBER!" << std::endl;

	} else {
		//SET POINTERS
		pWinLoseNum = &lose;

		// if condition is false then print the following
		//std::cout << "YOU LOSE SPECIFIC NUMBER!" << std::endl;
	}

	//================================================================
	// RESULT: COLOUR
	//================================================================
	std::cout << "RANDOM COLOUR = " << numColour << std::endl;

	std::cout << '\n' << std::endl;

	// CHECK IF INPUT COLOUR MATCHES
	if (inputColour == numColour) {
		//SET POINTERS
		pWinLoseColour = &win;

		// if condition is true then print the following
		//std::cout << "WINNER COLOUR!" << std::endl;

	} else {
		//SET POINTERS
		pWinLoseColour = &lose;

		// if condition is false then print the following
		//std::cout << "YOU LOSE COLOUR!" << std::endl;
	}

	//================================================================
	// RESULT: ODD/EVEN
	//================================================================
	// PRINT ODD/EVEN VALUE OF RANDNUM

	if (inputOddEven == numOddEven) {
		//SET POINTERS
		pWinOddEven = &win;

		//std::cout << "YOU WIN ODD EVEN BET" << std::endl;
	} else {
		//SET POINTERS
		pWinOddEven = &lose;

		//std::cout << "YOU LOSE ODD EVEN BET" << std::endl;
	}

	//================================================================
	// RESULT: LOWHIGHBET
	//================================================================
	// CHECK IF LOW HIGH BET MATCHES
	if (inputLowHighBet == numLowHighBet) {
		//SET POINTERS
		pWinLoseHighLow = &win;

		// if condition is true then print the following
		//std::cout << "WINNER OF LOW HIGH BET!" << std::endl;

	} else {
		pWinLoseHighLow = &lose;

		// if condition is false then print the following
		//std::cout << "YOU LOSE THE LOW HIGH BET!" << std::endl;
	}

	//================================================================
	// OVERALL RESULT
	//================================================================
	std::cout << line << '\n' << sep << std::setw(int_width) << "NUM" << sep
			<< std::setw(int_width) << "COLOUR" << sep << std::setw(int_width)
			<< "ODD/EVEN" << sep << std::setw(int_width) << "HIGH/LOW" << sep
			<< '\n' << line << '\n';

	std::cout << "                 YOUR CHOICE" << std::endl;

	std::cout << line << '\n' << sep << std::setw(int_width) << inputNum << sep
			<< std::setw(int_width) << inputColour << sep
			<< std::setw(int_width) << inputOddEven << sep
			<< std::setw(int_width) << inputLowHighBet << sep << '\n' << line
			<< '\n';

	std::cout << "                    HOUSE" << std::endl;

	std::cout << line << '\n' << sep << std::setw(int_width) << numRand << sep
			<< std::setw(int_width) << numColour << sep << std::setw(int_width)
			<< numOddEven << sep << std::setw(int_width) << numLowHighBet << sep
			<< '\n' << line << '\n';

	std::cout << "                    RESULT" << std::endl;

	std::cout << line << '\n' << sep << std::setw(int_width) << *pWinLoseNum
			<< sep << std::setw(int_width) << *pWinLoseColour << sep
			<< std::setw(int_width) << *pWinOddEven << sep
			<< std::setw(int_width) << *pWinLoseHighLow << sep << '\n' << line
			<< '\n';
	return 0;
}

