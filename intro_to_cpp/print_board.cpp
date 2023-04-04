#include<iostream>
#include<vector>
using std::vector;
using std::cout;
void print_board(vector<vector<int>>);

int main() {

	vector<vector<int>> vec = {
		{0,1,0,0,0,0},
		{0,1,0,0,0,0},
		{0,1,0,0,0,0},
		{0,1,0,0,0,0},
		{0,0,0,0,1,0} };
	print_board(vec);

}

void print_board(vector<vector<int>> vec) {
	for (auto row : vec) {
		for (int element : row)
			cout << element << " ";
		cout << std::endl;
	}
}