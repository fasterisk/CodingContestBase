#include "CodingContestBase.h"
#include "Contest.h"


static constexpr const string_view FOLDER_PREFIX = "level";
static constexpr const unsigned int LEVEL_NUMBER = 1;
static constexpr const unsigned int NUM_TEST_LEVELS = 5;

void doLevel(const string & inFileName, const string & outFileName) {
	cout << "Input File: " << inFileName << endl;
	cout << "Output File: " << outFileName << endl;

	ifstream input;
	input.open(inFileName);

	ofstream output;
	output.open(outFileName);

	assert(input.is_open());
	assert(output.is_open());

	Contest::Run(input, output);

	output.flush();
	input.close();
	output.close();
}

int main()
{
	try
	{
		ostringstream exampleInput;
		ostringstream exampleOutput;
		exampleInput << FOLDER_PREFIX << LEVEL_NUMBER << "/" << FOLDER_PREFIX << LEVEL_NUMBER
		                << "_example.in";
		exampleOutput << FOLDER_PREFIX << LEVEL_NUMBER << "/" << FOLDER_PREFIX << LEVEL_NUMBER
		                 << "_example_my.txt";

		doLevel(exampleInput.str(), exampleOutput.str());

		for (unsigned int nLevelFile = 1; nLevelFile <= NUM_TEST_LEVELS; ++nLevelFile)
		{
			ostringstream ssInputFileName;
			ostringstream ssOutputFileName;
			ssInputFileName << FOLDER_PREFIX << LEVEL_NUMBER << "/" << FOLDER_PREFIX << LEVEL_NUMBER
			                << "_" << nLevelFile << ".in";
			ssOutputFileName << FOLDER_PREFIX << LEVEL_NUMBER << "/" << FOLDER_PREFIX
			                 << LEVEL_NUMBER << "_" << nLevelFile << "_output.txt";

			doLevel(ssInputFileName.str(), ssOutputFileName.str());
		}
	}
	catch (...)
	{
		// oje
	}
}
