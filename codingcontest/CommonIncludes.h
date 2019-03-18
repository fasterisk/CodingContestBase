#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cassert>
#include <sstream>
#include <istream>
#include <ostream>

using namespace std;

// Vectors
typedef vector<int> vi;

// Pairs
typedef pair<int, int> pi;

// Maps
typedef map<int, int> mii;

template<typename T, typename U> inline void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if (x < y) x = y; }