#pragma once

#include <sstream>
#include <istream>
#include <ostream>
#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

namespace io
{
	template<typename T>
	inline void readVector(istream & input, int iNum, vector<T> & rVector)
	{
		for (int i = 0; i < iNum; ++i)
		{
			T item;
			input >> item;

			rVector.push_back(item);
		}
	}

	template<typename T>
	inline void readSet(istream & input, int iNum, set<T> & rSet)
	{
		for (int i = 0; i < iNum; ++i)
		{
			T item;
			input >> item;

			rSet.insert(item);
		}
	}

	template<typename T1, typename T2>
	inline void readMap(istream & input, int iNum, map<T1, T2> & rMap)
	{
		for (int i = 0; i < iNum; ++i)
		{
			T1 t1;
			input >> t1;
			T2 t2;
			input >> t2;

			rMap[t1] = t2;
		}
	}

	inline void goToNextLine(istream & input)
	{
		char nextChar = 0;
		while (input.get(nextChar))
		{
			if (nextChar == '\n')
			{
				break;
			}
		}
	}
}  // namespace io

////////////////////////////////////////////////////////////////////
///				Operators
////////////////////////////////////////////////////////////////////

template<typename T1, typename T2>
inline ostream& operator << (ostream & output, const pair<T1, T2>& p)
{
	output << p.first << " " << p.second;

	return output;
}

template<typename T1, typename T2>
inline istream& operator >> (istream & input, pair<T1, T2>& p)
{
	input >> p.first;
	input >> p.second;

	return input;
}

template<typename T>
inline ostream &operator <<(ostream & output, const vector<T> & rVector)
{
	bool bFirst = true;
	for (auto & item : rVector)
	{
		if (bFirst)
			bFirst = false;
		else
			output << " ";

		output << item;
	}

	return output;
}

template<typename T>
inline ostream &operator <<(ostream & output, const set<T> & rSet)
{
	bool bFirst = true;
	for (auto & item : rSet)
	{
		if (bFirst)
			bFirst = false;
		else
			output << " ";

		output << item;
	}

	return output;
}

template<typename T1, typename T2>
inline ostream &operator <<(ostream & output, const map<T1, T2> & rMap)
{
	bool bFirst = true;
	for (auto & iter : rMap)
	{
		if (bFirst)
			bFirst = false;
		else
			output << " ";

		output << iter;
	}

	return output;
}

