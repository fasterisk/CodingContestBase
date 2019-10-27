#pragma once

#include <string>
#include <vector>
#include <map>
#include <set>
#include <cassert>
#include <unordered_set>
#include <algorithm>

using namespace std;

// 
typedef unsigned int uint;

// Pairs
typedef pair<int, int> PI;
typedef pair<double, double> PD;

// Vectors
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<string> VS;
typedef vector<PI> VII;

// Sets
typedef set<int> SI;

// Maps
typedef map<int, int> MII;
typedef map<string, int> MSI;

constexpr int MAXINT = std::numeric_limits<int>::max();
constexpr int MININT = -MAXINT;

template<typename T, typename U> inline void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if (x < y) x = y; }

template<typename T>
inline void fillVector(vector<T> & rVec, T item, int iNum)
{
	for (int i = 0; i < iNum; ++i)
		rVec.push_back(item);
}

inline int roundToInt(double d) { return int(d + 0.5); }


template<typename K, typename V>
inline vector<K> extractKeys(const map<K,V> & rvMap)
{
	auto v = vector<K>{};
	transform(rvMap.begin(), rvMap.end(), back_inserter(v), [](auto& iter) { return iter.first; });

	return v;
}

template<typename K, typename V>
inline vector<K> extractValues(const map<K, V>& rvMap)
{
	auto v = vector<K>{};
	transform(rvMap.begin(), rvMap.end(), back_inserter(v), [](auto& iter) { return iter.second; });

	return v;
}