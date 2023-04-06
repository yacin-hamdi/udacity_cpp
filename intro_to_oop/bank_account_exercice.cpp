#include<iostream>
#include<string>


class BankAccount {
public:
	BankAccount(std::string number, std::string name, float funds):number(number), name(name), funds(funds) {}

	void Number(std::string number);
	std::string Number();

	void Name(std::string name);
	std::string Name();

	void Funds(float funds);
	float Funds();


private:
	std::string number;
	std::string name;
	float funds;
};


void BankAccount::Number(std::string number) {
	this->number = number;
}

std::string BankAccount::Number() {
	return this->number;
}

void BankAccount::Name(std::string name) {
	this->name = name;
}

std::string BankAccount::Name() {
	return this->name;
}

void BankAccount::Funds(float funds) {
	this->funds = funds;
}

float BankAccount::Funds() {
	return this->funds;
}



int main() {
	BankAccount moose("123456789", "moose", 32.2);
	std::cout << "account name: " << moose.Name() << std::endl;
	std::cout << "account number: " << moose.Number() << std::endl;
	std::cout << "funds : " << moose.Funds() << "$\n\n\n";
	moose.Name("moose1");
	moose.Funds(120.12);

	std::cout << "account name: " << moose.Name() << std::endl;
	std::cout << "account number: " << moose.Number() << std::endl;
	std::cout << "funds : " << moose.Funds() << "$\n\n\n";
}