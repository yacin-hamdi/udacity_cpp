#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>

using std::string;
using std::istringstream;
using std::ifstream;
using std::vector;
using std::cout;

vector<vector<int>> parseline(string);

int main() {
	string filepath = "file/board";
	vector<vector<int>> grid = parseline(filepath);
	for (vector<int> i : grid) {
		for (int j : i)
			cout << j << " ";
		cout << std::endl;
	}

}

vector<vector<int>> parseline(string filepath) {
	ifstream file;
	int n;
	char c;
	vector<vector<int>> grid;
	file.open(filepath);
	if (file) {
		string line;
		while (getline(file, line)) {
			istringstream my_stream(line);
			vector<int> vec = {};
			while (my_stream >> n >> c) {
				vec.push_back(n);
			}
			grid.push_back(vec);
		}
	}

	return grid;
}