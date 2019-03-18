#include "Contest.h"


struct INPUTSTRUCT
{
	pair<uint, uint> info;
};

ofstream &operator <<(ofstream & output, const INPUTSTRUCT & rStruct)
{
	output << rStruct.info << endl;
	return output;
}

ifstream &operator >> (ifstream & input, INPUTSTRUCT & rStruct)
{
	input >> rStruct.info;

	return input;
}

/***********************************************************************************
************************************************************************************/
void	Contest::Run(std::ifstream & input, std::ofstream & output)
{
	INPUTSTRUCT stInputStruct;

	input >> stInputStruct;
	output << stInputStruct;

	VI vi = { 1, 2, 3, 4, 5, 6, 7, 8 };
	SI si = { 1, 2, 3,4 ,6, 7 };

	MII mii;
	mii[0] = 123;
	mii[2] = 23322;
	mii[5] = 23923;

	output << vi << endl;
	output << si << endl;
	output << mii << endl;
}