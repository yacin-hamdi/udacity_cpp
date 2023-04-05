#include<iostream>
using std::cout;


int main() {
	int i = 1;
	int j = 2;
	int a = 10;
	int b = 11;
	int c = 100;
	int d = 1000;

	cout << "i = " << i << " and its address is " << &i << std::endl;
	cout << "j = " << j << " and its address is " << &j << std::endl;
	cout << "a = " << a << " and it is located at " << &a << std::endl;
	cout << "b = " << b << " and it is located at " << &b << std::endl;
	cout << "c = " << c << " and it is located at " << &c << std::endl;
	cout << "d = " << d << " and it is located at " << &d << std::endl;

	int& ref = b;
	cout << "ref is other name of b = " << b << " and ref = " <<   ref << std::endl;
	cout << "ref is located at " << &ref << " which is the location of b: " << &ref << std::endl;


	int& ref1 = a;
	cout << "ref1 = " << ref1 << ", a = " << a << std::endl;
	cout << "ref1 address = " << &ref1 << ", a address = " << &a << std::endl;

	int* c_address = &c;
	cout << "c_address is " << c_address << " and c address is " << &a << std::endl;

	cout << "\n\n" << "declare a pointer to i";

	int var = 5;
	int* pointer_to_var = &var;

	cout << "the address of var is " << &var << "\n";
	cout << "the pointer_to_var is " << pointer_to_var << std::endl;
	cout << "the value pointer_to_var points to " << *pointer_to_var << std::endl;
	cout << "the value of var is " << var << std::endl;

	var = 10;

	cout << "the new var value is " << var << std::endl;
	cout << "the new value pointer_to_var points to is " << *pointer_to_var << std::endl;




	cout << "\n\n ----------- pointer practice ------------\n";


	int var1 = 10;
	int var2 = 20;
	int var3 = 30;
	int* pointer1 = &var1;
	int* pointer2 = &var2;
	int* pointer3 = &var3;

	cout << "var1 address = " << &var1;
	cout << "\npointer1 holds " << pointer1;
	cout << "\nvar2 address = " << &var2;
	cout << "\npointer2 holds " << pointer2;
	
	cout << "\nvar3 address = " << &var3;
	cout << "\npointer3 holds " << pointer3;

	cout << "\n\nvar1 = " << var1;
	cout << "\npointer1 points to " << *pointer1;
	cout << "\nvar2 = " << var2;
	cout << "\npointer2 points to " << *pointer2;
	cout << "\nvar3 = " << var3;
	cout << "\npointer3 points to " << *pointer3;

	

}