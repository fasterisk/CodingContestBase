#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <map>
#include <set>
#include <cassert>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <iomanip>

using namespace std;

//
using uint = unsigned int;

// Pairs
using PI = pair<int, int>;
using PD = pair<double, double>;

// Vectors
using VI = vector<int>;
using VD = vector<double>;
using VS = vector<string>;
using VII = vector<PI>;

// Sets
using SI = set<int>;

// Maps
using MII = map<int, int>;
using MSI = map<string, int>;

constexpr int MAXINT = std::numeric_limits<int>::max();
constexpr int MININT = -MAXINT;

double pi() { return atan(1) * 4; }

template <typename T, typename U>
inline void amin(T & x, U y)
{
	if (y < x)
		x = y;
}
template <typename T, typename U>
inline void amax(T & x, U y)
{
	if (x < y)
		x = y;
}

template <typename T>
inline void fillVector(vector<T> & rVec, T item, size_t num)
{
	rVec.resize(rVec.size() + num, item);
}

inline int roundToInt(double d) { return lround(d); }

template <typename K, typename V>
inline vector<K> extractKeys(const map<K, V> & rvMap)
{
	auto v = vector<K>(rvMap.size());
	transform(rvMap.begin(), rvMap.end(), v.begin(), [](auto & iter) { return iter.first; });

	return v;
}

template <typename K, typename V>
inline vector<K> extractValues(const map<K, V> & rvMap)
{
	auto v = vector<K>(rvMap.size());
	transform(
	    rvMap.begin(), rvMap.end(), back_inserter(v), [](auto & iter) { return iter.second; });

	return v;
}
