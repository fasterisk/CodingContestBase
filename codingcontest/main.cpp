// codingcontest.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include "Contest.h"

int main()
{
	std::string FOLDER_PREFIX = "level";

	unsigned int LEVEL_NUMBER = 1;
	unsigned int NUM_TEST_LEVELS = 4;

	for (unsigned int nLevelFile = 0; nLevelFile < NUM_TEST_LEVELS; ++nLevelFile)
	{
		std::ostringstream ssInputFileName, ssOutputFileName;
		ssInputFileName << FOLDER_PREFIX << LEVEL_NUMBER << "/level" << LEVEL_NUMBER << "_" << nLevelFile << ".in";
		ssOutputFileName << FOLDER_PREFIX << LEVEL_NUMBER << "/level" << LEVEL_NUMBER << "_" << nLevelFile << "_output.txt";

		std::cout << "Input File: " << ssInputFileName.str() << std::endl;
		std::cout << "Output File: " << ssOutputFileName.str() << std::endl;

		std::ifstream input;
		input.open(ssInputFileName.str());

		std::ofstream output;
		output.open(ssOutputFileName.str());

		assert(input.is_open());
		assert(output.is_open());

		Contest contest;

		switch (LEVEL_NUMBER)
		{
		case 1: contest.Level1(input, output); break;
		case 2: contest.Level2(input, output); break;
		case 3: contest.Level3(input, output); break;
		case 4: contest.Level4(input, output); break;
		case 5: contest.Level5(input, output); break;
		case 6: contest.Level6(input, output); break;
		case 7: contest.Level7(input, output); break;
		default:
			break;
		}

		output.flush();
		input.close();
		output.close();
	}
}