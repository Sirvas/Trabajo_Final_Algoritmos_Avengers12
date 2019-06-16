#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std; 

vector<string> split(string str, char separadora) {
	istringstream iss(str);
	string cad;
	vector<string> arr;
	while (getline(iss, cad, separadora)) {
		arr.push_back(cad);
	}
	return arr;
}