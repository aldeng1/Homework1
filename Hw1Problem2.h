#pragma once

// #include "Hw1Problem2.h"

#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <map>
#include <array>

using namespace std;

class dist
{
public:

	double distance;

	double distan(string from, string to)
	{

		std::array<std::map<std::vector<string>, double>, 6> dis;

		std::vector<string>d1 = { "SCE","PHL" };
		std::map<std::vector<string>, double> d1n = { {d1,160} };

		std::vector<string>d2 = { "SCE","ORD" };
		std::map<std::vector<string>, double> d2n = { {d2,640} };

		std::vector<string>d3 = { "SCE","EWR" };
		std::map<std::vector<string>, double> d3n = { {d3,220} };

		std::vector<string>d4 = { "PHL","SCE" };
		std::map<std::vector<string>, double> d4n = { {d4,160} };

		std::vector<string>d5 = { "ORD","SCE" };
		std::map<std::vector<string>, double> d5n = { {d5,640} };

		std::vector<string>d6 = { "EWR","SCE" };
		std::map<std::vector<string>, double> d6n = { {d6,220} };

		dis[0] = d1n;
		dis[1] = d2n;
		dis[2] = d3n;
		dis[3] = d4n;
		dis[4] = d5n;
		dis[5] = d6n;

		for (auto& m : dis) {
			for (auto it = m.begin(); it != m.end(); ++it) {
				if (it->first[0] == from && it->first[1] == to) {
					return it->second;
				}
			}
		}


		return -1;
	}

};