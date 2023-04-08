#include<iostream>
#include<vector>

class Test {
public:
	Test() {
		counter++;
	}

	int getCount() { return counter; }
	
	
private:
	static int counter;
};

int Test::counter = 0;

int main() {
	
	std::vector<Test> tests{};

	for (int i = 0; i < 100; i++) {
		tests.push_back(Test());
	}
	int counter = tests[1].getCount();
	std::cout << "we have created " << counter << " object" << std::endl;


}