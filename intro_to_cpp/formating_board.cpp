#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<string>


using std::cout;
using std::vector;
using std::ifstream;
using std::istringstream;
using std::string;


enum class State { kObstacle, kEmpty };
vector<string> parseline(string);
vector<vector<string>> read_from_board(string);
string cell_string(State);



int main() {

	vector<vector<string>> board = read_from_board("file/board");
	int var[3] = { 1,2,3 };

	for (auto row : board) {
		for (string element : row)
			cout << element << " ";
		cout << std::endl;
	}




}


vector<vector<string>> read_from_board(string file_path) {
	vector<vector<string>> board;
	ifstream file;
	file.open(file_path);
	if (file) {
		string line;
		while (getline(file, line)) {
			vector<string> row = parseline(line);
			board.push_back(row);
		}
	}

	return board;
}

vector<string> parseline(string line) {
	istringstream my_stream(line);
	vector<string> row;
	int n;
	char c;
	State state = State::kEmpty;
	while (my_stream >> n >> c) {
		if (n == 1)
			state = State::kObstacle;
		else
			state = State::kEmpty;

		row.push_back(cell_string(state));
	}
	return row;
}

string cell_string(State state) {
	if (state == State::kObstacle)
		return "⛰️ ";
	else
		return "0 ";
	
}