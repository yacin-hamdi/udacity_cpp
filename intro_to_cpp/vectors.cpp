#include<iostream>
#include<vector>


int main() {
	vector<int> a = { 0,1,2,3,4 };
	for (int i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";

	std::cout << "\n\n";
	for (int element : a)
		std::cout << element << " " ;

	cout << "\n\n";

	std::vector<std::vector<int>> b = { {0,1,2,3},
										{4,5,6,7},
										{8,9,10,11} };

	for (int i = 0; i < b.size(); i++) {
		for (int j = 0; j < b[0].size();j++)
			std::cout << b[i][j] << " ";
		std::cout << std::endl;
	}
	std::cout << "\n";

	for (auto row : b) {
		for (int element : row)
			std::cout << element << " ";
		std::cout << std::endl;
	}

}