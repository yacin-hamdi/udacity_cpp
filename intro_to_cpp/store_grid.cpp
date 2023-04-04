#include<iostream>
#include<vector>

int main() {
	std::vector<std::vector<int>> grid = { {0, 1, 0, 0, 0, 0, 0},
											{0, 1, 0, 0, 0, 0, 0},
											{0, 1, 0, 0, 0, 0, 0},
											{0, 1, 0, 0, 0, 0, 0},
											{0, 0, 0, 0, 0, 1, 0} };

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			std::cout << grid[i][j];
		}
		std::cout << std::endl;
	}

								
}