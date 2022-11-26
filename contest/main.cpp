#include "CodingContestBase.h"
#include "Contest.h"

#define AOC
//#define CCC

static constexpr const string_view FOLDER_PREFIX = "level";
static constexpr const unsigned int LEVEL_NUMBER = 1;

#ifdef CCC
static constexpr const unsigned int NUM_TEST_LEVELS = 1;
#endif

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
		#ifdef AOC
		ostringstream exampleInput;
		ostringstream exampleOutput;
		exampleInput << FOLDER_PREFIX << LEVEL_NUMBER << "/input.txt";
		exampleOutput << FOLDER_PREFIX << LEVEL_NUMBER << "/output.txt";

		#endif

		#ifdef CCC
		ostringstream exampleInput;
		ostringstream exampleOutput;
		exampleInput << FOLDER_PREFIX << LEVEL_NUMBER << "/" << FOLDER_PREFIX << LEVEL_NUMBER
		                << "_input.txt";
		exampleOutput << FOLDER_PREFIX << LEVEL_NUMBER << "/" << FOLDER_PREFIX << LEVEL_NUMBER
		                 << "_output.txt";

		doLevel(exampleInput.str(), exampleOutput.str());

		for (unsigned int nLevelFile = 1; nLevelFile <= NUM_TEST_LEVELS; ++nLevelFile)
		{
			ostringstream ssInputFileName;
			ostringstream ssOutputFileName;
			ssInputFileName << FOLDER_PREFIX << LEVEL_NUMBER << "/" << FOLDER_PREFIX << LEVEL_NUMBER
			                << "_" << nLevelFile << "_input.txt";
			ssOutputFileName << FOLDER_PREFIX << LEVEL_NUMBER << "/" << FOLDER_PREFIX
			                 << LEVEL_NUMBER << "_" << nLevelFile << "_output.txt";

			doLevel(ssInputFileName.str(), ssOutputFileName.str());
		}
		#endif
	}
	catch (...)
	{
		// oje
	}
}
