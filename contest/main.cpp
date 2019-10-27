#include "CodingContestBase.h"
#include "Contest.h"

int main()
{
	std::string FOLDER_PREFIX = "level";

	unsigned int LEVEL_NUMBER = 5;
	unsigned int NUM_TEST_LEVELS = 5;

	for (unsigned int nLevelFile = 1; nLevelFile <= NUM_TEST_LEVELS; ++nLevelFile)
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
		contest.Run(input, output);

		output.flush();
		input.close();
		output.close();
	}
}