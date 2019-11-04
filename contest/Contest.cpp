#include "Contest.h"

struct InputObject
{
	int i1 = 0;
	int i2 = 0;
};

ofstream &operator <<(ofstream & output, const InputObject & o)
{
	return output;
}

ifstream &operator >> (ifstream & input, InputObject & i)
{
	input >> i.i1;
	input >> i.i2;
	return input;
}

/***********************************************************************************
************************************************************************************/
void Contest::Run(std::ifstream & input, std::ofstream & output)
{
	InputObject inputobject;
	input >> inputobject;
}