#include<algorithm>
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
using std::sort;
using std::abs;



enum class State { kObstacle, kEmpty, kClosed,kPath, kStart, kFinish };

vector<State> parseline(string);
vector<vector<State>> ReadBoardFile(string);
string CellString(State);

vector<vector<State>> Search(vector<vector<State>>, int[2], int[2]);
void printboard(vector<vector<State>>);
int Heuristic(int, int, int, int);

void AddToOpen(int, int, int, int, vector<vector<int>> &, vector<vector<State>> &);
bool Compare(vector<int>, vector<int>);
void CellSort(vector<vector<int>> *);
bool CheckValidCell(int, int, vector<vector<State>> &);
void ExpandNeighbors(vector<int> &, int[], vector<vector<int>> &, vector<vector<State>> & );


#include "test7.cpp"
int main() {

	vector<vector<State>> board = ReadBoardFile("1.board");
	int start[2] { 0,0 };
	int goal[2] { 4, 5 };
	auto solution = Search(board, start, goal);
	printboard(solution);
	
	TestHeuristic();
	TestAddToOpen();
	TestCompare();
	TestSearch();
	TestCheckValidCell();
	TestExpandNeighbors();


	




}


vector<vector<State>> ReadBoardFile(string file_path) {
	vector<vector<State>> board;
	ifstream file;
	file.open(file_path);
	if (file) {
		string line;
		while (getline(file, line)) {
			vector<State> row = parseline(line);
			board.push_back(row);
		}
	}

	return board;
}

vector<State> parseline(string line) {
	istringstream my_stream(line);
	vector<State> row;
	int n;
	char c;
	State state = State::kEmpty;
	while (my_stream >> n >> c) {
		if (n == 1)
			state = State::kObstacle;
		else
			state = State::kEmpty;

		row.push_back(state);
	}
	return row;
}

string CellString(State state) {
	if (state == State::kObstacle)
		return "⛰️ ";
	else if (state == State::kPath)
		return "🚗 ";
	else if (state == State::kFinish)
		return "🏁 ";
	else if (state == State::kStart)
		return "🚦 ";
	else
		return "0 ";

}

vector<vector<State>> Search(vector<vector<State>> board, int start[2], int goal[2]) {
	vector<vector<int>> open{ };
	int x = start[0];
	int y = start[1];
	int g = 0;
	int h = Heuristic(x, y, goal[0], goal[1]);
	AddToOpen(x, y, g, h, open, board);

	while (open.size() > 0) {
		CellSort(&open);
		vector<int> current_node = open.back();
		open.pop_back();
		x = current_node[0];
		y = current_node[1];
		if (start[0] == x && start[1] == y)
			board[x][y] = State::kStart;
		else
			board[x][y] = State::kPath;
		
		if (x == goal[0] and y == goal[1]) {
			cout << "path found\n";
			board[x][y] = State::kFinish;
			return board;
		}
			
		ExpandNeighbors(current_node, goal, open, board);
		

		
	}
	cout << "no path\n";

	return vector<vector<State>> {};
	
}

void printboard(vector<vector<State>> board) {
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			cout << CellString(board[i][j]) << " ";
		}
		cout << "\n";
	}
}

int Heuristic(int x1, int y1, int x2, int y2) {
	return  abs(x2 - x1) + abs(y2 - y1);
}

void AddToOpen(int x, int y, int g, int h, vector<vector<int>>& open_node, vector<vector<State>> &grid) {
	vector<int> node{ x, y, g, h };
	open_node.push_back(node);
	grid[x][y] = State::kClosed;
}

bool Compare(vector<int> node1, vector<int> node2) {
	int f1 = node1[2] + node1[3];
	int f2 = node2[2] + node2[3];
	return f1 > f2;
}

void CellSort(vector<vector<int>>* v) {
	sort(v->begin(), v->end(), Compare);
}

bool CheckValidCell(int x, int y, vector<vector<State>>& grid) {
	return x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == State::kEmpty;
	

}

void ExpandNeighbors(vector<int> &current_node, int goal[2], vector<vector<int>> &openlist, vector<vector<State>> &grid) {
	int x = current_node[0];
	int y = current_node[1];
	int g = current_node[2];
	int h = Heuristic(x, y, goal[0], goal[1]);

	const int delta[4][2]{ {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
	for (auto action:delta) {
		int x2 = x + action[0];
		int y2 = y + action[1];

		if (CheckValidCell(x2, y2, grid)) {
			
			int g2 = g + 1;
			int h2 = Heuristic(x2, y2, goal[0], goal[1]);
			AddToOpen(x2, y2, g2, h2, openlist, grid);
		}
	}
}
