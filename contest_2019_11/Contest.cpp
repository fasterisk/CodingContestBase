#include "Contest.h"

struct InputObject
{
};

ofstream &operator <<(ofstream & output, const InputObject & rStruct)
{
	return output;
}

ifstream &operator >> (ifstream & input, InputObject & rA)
{
	return input;
}

/***********************************************************************************
************************************************************************************/
void Contest::Run(std::ifstream & input, std::ofstream & output)
{
	
}