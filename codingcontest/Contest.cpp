#include "Contest.h"


struct INPUTSTRUCT
{
};

ofstream &operator <<(ofstream & output, const INPUTSTRUCT & rStruct)
{
	return output;
}

ifstream &operator >> (ifstream & input, INPUTSTRUCT & rStruct)
{
	return input;
}

/***********************************************************************************
************************************************************************************/
void	Contest::Run(std::ifstream & input, std::ofstream & output)
{
	INPUTSTRUCT stInputStruct;

	input >> stInputStruct;
	output << stInputStruct;

	// lambda
	auto add = [](int i, int j) -> int { return i + j;  };

	int a = add(10, 20);
	int b = add(100, 200);

	output << a << " " << b << endl;

	VI vi;
	fillVector(vi, 123, 5);

	SI si = { 1, 2, 3,4 ,6, 7 };
	

	MII mii;
	mii[0] = 123;
	mii[2] = 23322;
	mii[5] = 23923;

	output << vi << endl;
	output << si << endl;
	output << mii << endl;
}