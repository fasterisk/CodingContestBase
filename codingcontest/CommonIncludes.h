#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cassert>
#include <sstream>
#include <istream>
#include <ostream>

using namespace std;

// 
typedef unsigned int uint;

// Pairs
typedef pair<int, int> PI;

// Vectors
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PI> VII;

// Sets
typedef set<int> SI;

// Maps
typedef map<int, int> MII;
typedef map<string, int> MSI;

template<typename T, typename U> inline void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if (x < y) x = y; }

template<typename T1, typename T2>
inline ofstream& operator << (ofstream & output, const pair<T1, T2>& p)
{
	output << "(" << p.first << ", " << p.second << ")";

	return output;
}

template<typename T1, typename T2>
inline ifstream& operator >> (ifstream & input, pair<T1, T2>& p)
{
	input >> p.first;
	input >> p.second;

	return input;
}

template<typename T>
inline ofstream &operator <<(ofstream & output, const vector<T> & rVector)
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
inline ofstream &operator <<(ofstream & output, const set<T> & rSet)
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
inline ofstream &operator <<(ofstream & output, const map<T1, T2> & rMap)
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

template<typename T> inline void readVector(ifstream & input, int iNum, vector<T> & rVector)
{
	for (int i = 0; i < iNum; ++i)
	{
		T item;
		input >> item;

		rVector.push_back(item);
	}
}

template<typename T> inline void readSet(ifstream & input, int iNum, set<T> & rSet)
{
	for (int i = 0; i < iNum; ++i)
	{
		T item;
		input >> item;

		rSet.insert(item);
	}
}