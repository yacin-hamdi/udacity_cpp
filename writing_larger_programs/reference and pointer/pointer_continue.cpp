#include <iostream>
#include <vector>

using std::cout;
using std::vector;


void increment(int* j) {
	(*j)++;
}

int* addOne(int* j) {
	*j++;
	return j;
}

int main() {

	vector<int> v{ 1,2,3,4,5 };
	vector<int>* pointer_v = &v;

	for (int a : v) {
		cout << a << " ";
	}

	cout << "\n";
	cout << "first element:" << (*pointer_v)[0] << "\n";
	
	for (int i = 0; i < (*pointer_v).size(); i++) {
		cout << (*pointer_v)[i] << " ";
	}

	cout << "\n\n";


	int inc = 1;
	cout << "inc = " << inc << std::endl;
	increment(&inc);

	cout << "inc = " << inc << std::endl;

	int add = 10;
	cout << "add = " << add << std::endl;
	cout << "add address " << &add << std::endl;
	int* pointer_add = addOne(&add);
	cout << "add = " << add << std::endl;
	cout << "pointer_add = " << *pointer_add << std::endl;

	cout << "add address " << &add << std::endl;
	cout << "pointer_add address " << pointer_add << std::endl;

}