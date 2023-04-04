#include<iostream>
#include<fstream>
#include<string>

using std::ifstream;
using std::string;
void read_board_file(string);

int main() {
	string file_path;
	file_path = "file/board";
	read_board_file(file_path);
}

void read_board_file(string file_path) {
	ifstream file;
	file.open(file_path);
	if (file) {
		std::cout << "the file stream has been create\n";
		string line;
		while (getline(file, line)) {
			std::cout << line << "\n";
		}
	}
}