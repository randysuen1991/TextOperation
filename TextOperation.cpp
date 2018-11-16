#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// Input: 1. a line that is going to be splitted. 2. a delimeter 
// Output: a vector<string> which contains the tokens. 
vector<string> split(string line, string delimeter) {
	vector<string> vs;
	size_t pos = 0;
	while ((pos = line.find(delimeter) != string::npos)){
		string token = line.substr(0, pos);
		vs.push_back(token);
		line.erase(0, pos);
	}
	vs.push_back(line);
	return vs;
}


int main()
{
	string d=" ";
	ifstream file("test.txt");
	ofstream file_o("test_o.txt");


	if (file.is_open()) {
		string line;
		while (getline(file, line)) {
			size_t i = 0;
			printf("%s\n", line.c_str());
			vector<string> vs = split(line, d);
			//for (int j = 0; j < vs.size(); j++) {
				//printf("%s", vs[j].c_str());
				//file_o.write(vs[j], vs[j].size());
				//file_o << vs[j];
			//}
			for (vector<string>::iterator j = vs.begin(); j != vs.end(); j++) {
				for (string::iterator k = (*j).begin(); k != (*j).end(); k++) {
					printf("%c", *k);
				}
			}
			file_o << "\n";
			printf("\n");
		}
	}
	file.close();
}
