#include<iostream>
#include<string>
#include<sstream>
using std::string;
using std::istringstream;
using std::cout;

int main() {
	string a("1 2 3");
	istringstream my_stream(a);

	int n;
	while (my_stream) {
		my_stream >> n;
		if (my_stream) {
			cout << "the stream was successfully " << n << std::endl;
		}
		else {
			cout << "the stream was not successfully \n";
		}
	}
}