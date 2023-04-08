#include<iostream>

// Create a class Abstraction.
// The class needs two private attributes var1 and var2.
// Create one single function to set both values.
// Create one function to print both v


class Abstraction {
private:
	int var1_;
	int var2_;

public:
	void set(int var1, int var2){
		this->var1_ = var1;
		this->var2_ = var2;
	
	}
	void print() {
		std::cout << "var1 = " << var1_ << "\nvar2 = " << var2_ << std::endl;
	}
};

int main() {
	Abstraction abs;
	abs.set(4, 5);
	abs.print();
}