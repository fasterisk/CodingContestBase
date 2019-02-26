#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <cassert>
#include <sstream>
#include <istream>
#include <ostream>

class Contest
{
public:
	/// Level specific implementations
	void	Level1(std::ifstream & input, std::ofstream & output);
	void	Level2(std::ifstream & input, std::ofstream & output);
	void	Level3(std::ifstream & input, std::ofstream & output);
	void	Level4(std::ifstream & input, std::ofstream & output);
	void	Level5(std::ifstream & input, std::ofstream & output);
	void	Level6(std::ifstream & input, std::ofstream & output);
	void	Level7(std::ifstream & input, std::ofstream & output);
};