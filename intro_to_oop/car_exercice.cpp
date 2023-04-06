#include<iostream>
#include<string>
#include<cstring>


class Car {
public:
	Car() {}

	void setHorsePower(int horse_power);
	void setWeight(float weight);
	void setBrand(std::string brand);

	int getHorsePower() const { return horse_power; }
	float getWeight() const { return weight; }
	std::string getBrand() ;



private:
	int horse_power;
	float weight;
	char* brand;
};

void Car::setHorsePower(int horse_power) {
	this->horse_power = horse_power;
}

void Car::setWeight(float weight) {
	this->weight = weight;
}

void Car::setBrand(std::string brand) {
	this->brand = new char(brand.length() + 1);
	strcpy(this->brand, brand.c_str());
}

std::string Car::getBrand() {
	std::string res_brand;
	return res_brand + this->brand;
}




int main() {
	Car car;
	car.setBrand("Peugeot");
	std::cout << car.getBrand() << "\n";
}