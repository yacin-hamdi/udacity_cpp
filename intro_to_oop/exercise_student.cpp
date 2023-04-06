#include<cassert>
#include<iostream>
#include<string>
#include<stdexcept>


class Student {

public:
	Student(std::string name, int grade, float GPA) :name_(name), grade_(grade), GPA_(GPA){}

	void setName(std::string name);
	void setGrade(int grade);
	void setGPA(float GPA);

	std::string getName() const;
	int getGrade() const;
	float getGPA() const;
	


private:
	std::string name_;
	int grade_;
	float GPA_;
};

void Student::setName(std::string name) {this->name_ = name;}

void Student::setGrade(int grade) {
	if (grade > 0 && grade <= 12)
		this->grade_ = grade;

	else
		throw std::invalid_argument("megative number");
	
	
}
void Student::setGPA(float GPA) {
	if (GPA > 0 && GPA <= 4)
		this->GPA_ = GPA;
	else
		throw std::invalid_argument("negative number");
	
	 
}

float Student::getGPA() const {return GPA_;}
std::string Student::getName() const { return name_; }
int Student::getGrade() const { return grade_; }





int main() {
	Student moose("moose", 2, 3.5);
	assert(moose.getName() == "moose");
	assert(moose.getGrade() == 2);
	assert(moose.getGPA() == 3.5);
	bool myException{ true };
		try {
		moose.setGrade(-1);
	}
	catch (std::invalid_argument& e) {
		myException = false;
	}
	assert(myException);
		
	


}