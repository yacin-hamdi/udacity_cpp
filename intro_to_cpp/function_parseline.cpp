#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>

using std::cout;
using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;

vector<vector<int>> read_board_file(string);
vector<int> parseline(string);

int main() {
	string filepath = "file/board";
	vector<vector<int>> grid = read_board_file(filepath);
	
	for (auto row : grid) {
		for (int cell : row)
			cout << cell << " ";
		cout << std::endl;
	}

}

vector<vector<int>> read_board_file(string filepath) {
	ifstream file;
	vector<vector<int>> grid;
	file.open(filepath);
	
	if (file) {
		string line;
		while (getline(file, line)) {
			vector<int> vec = parseline(line);
			grid.push_back(vec);
		}
	}
	return grid;

}

vector<int> parseline(string line) {
	istringstream my_stream(line);
	int n;
	char c;
	vector<int> grid_line;
	while (my_stream >> n >> c) {
		grid_line.push_back(n);
	}

	return grid_line;
}