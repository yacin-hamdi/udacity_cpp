#include<iostream>


namespace english {
	void hello() {
		std::cout << "Hola, Mundo\n";
	}
}

namespace spanish {
	void hello() {
		std::cout << "hello world\n";
	}
}






int main() {
	english::hello();
	spanish::hello();

}