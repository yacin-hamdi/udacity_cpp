#include<iostream>
#include<string>
#include<fstream>

int main() {
	std::ifstream board;
	std::string filename;
	filename = "file/board";
	board.open(filename);
		if (board) {
			std::cout << "the file stream have been created\n";
			std::string line;
			while (getline(board, line)) {
				std::cout << line << "\n";
			}
	}
}