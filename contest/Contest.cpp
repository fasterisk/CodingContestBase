#include "Contest.h"

struct InputObject
{
	// todo
};

InputObject readInput(istream & input)
{ 
	InputObject o;
	// todo
	return o;
}

void writeOutput(ostream & output, const InputObject & o) 
{
	// todo
}

double pi() { return atan(1) * 4; } 

/***********************************************************************************
************************************************************************************/
void Contest::Run(istream & input, ostream & output)
{
	auto in = readInput(input);
	output << setprecision(20);
	writeOutput(output, in);
}