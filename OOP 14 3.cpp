#include <iostream>
#include <string>
#define random(min, max) (min+rand()%(max-min+1))
using namespace std;

const char LETTERS[]{ 'A','B', 'E','K','M','H','O','P','C','T','X' };
const string COLORS[]{ "white","black","yellow","blue","red" };
const string MODELS[]{ "Mercedes", "Toyota","BMW","Lexus","Tesla" };
//class Student {
//private:
//	string name;
//	int age;
//public:
//	Student(string name, int age):Student(name) {
//		this->name = name;
//		this->age = age;
//	}
//	Student(string name) {
//		this->name = name;
//		this->age = 0;
//	}
//	string getName() {
//		return name;
//	}
//	int getAge() {
//		return age;
//	}
//	void setName(string name) {
//		this->name = name;
//	}
//	void setAge(int age) {
//		this->age = age;
//	}
//	void showInfo() {
//		cout << "Name: " << this->name << "\nAge: " << this->age << endl;
//	}
//};

class Car {
private:
	static string lastNumber;
	string number;
	string model;
	string color;

public:
	Car(){};

	Car(string model, string color) {
		this->number = lastNumber;
		this->model = model;
		this->color = color;
		incrementLastNumber();
	}
	string getNumber() {
		return number;
	}
	void carInfo() {
		cout << "Number: " << number << endl;
		cout << "Model: " << model << endl;
		cout << "Color: " << color << endl << endl;
	}
	string getModel() {
		return model;
	}
	string getColor() {
		return color;
	}
	void setColor(string color) {
		this->color = color;
	}
private:
	void incrementLastNumber() {
		int num = 0;
		string letters;
		int index = 0;
		letters = lastNumber[0];
		letters += lastNumber[4];
		letters += lastNumber[5];
		cout << num << endl;
		num += (lastNumber[1] - '0') * 100;
		cout << num << endl;
		num += (lastNumber[2] - '0') * 10;
		cout << num << endl;
		num += (lastNumber[3] - '0');
		cout << num << endl;
		num++;
		cout << num << endl;
		if (num == 1000) {
			num = 0;
			if (letters[2] == LETTERS[10]) {
				letters[2] = LETTERS[0];
				if (letters[1] == LETTERS[10]) {
					letters[1] = LETTERS[0];
					if (letters[0] == LETTERS[10]) {
						cout << "ERROR 0";
						return;
					}
					else {
						for (int i = 0; i <= 10; i++) {
							if (letters[0] == LETTERS[i]) {
								index = i;
								break;
							}
						}
						letters[0] = LETTERS[index + 1];
					}
				}
				else {
					for (int i = 0; i <= 10; i++) {
						if (letters[1] == LETTERS[i]) {
							index = i;
							break;
						}
					}
					letters[1] = LETTERS[index + 1];
				}

			}
			else {
				for (int i = 0; i <= 10; i++) {
					if (letters[2] == LETTERS[i]) {
						index = i;
						break;
					}
				}
				letters[2] = LETTERS[index + 1];
			}
		}


		string newLastNumber;
		newLastNumber = letters[0];
		if (num < 10) {
			newLastNumber += "00";
		}
		else if (num < 100) {
			newLastNumber += "0";
		}
		newLastNumber += to_string(num);
		newLastNumber += letters[1];
		newLastNumber += letters[2];
		lastNumber = newLastNumber;
	}

	string generateNumber() {
		string letters = "";
		letters += lastNumber[0];
		letters += lastNumber[4];
		letters += lastNumber[5];
		int numbers = stoi(lastNumber.substr(1, 3));
		if (numbers >= 999) {
			numbers = 0;
			if (letters[2] == LETTERS[10]) {
				letters[2] = LETTERS[0];
				if (letters[1] == LETTERS[10]) {
					letters[1] = LETTERS[0];
					if (letters[0] != LETTERS[10]) {
						letters[0] = findNextLetter(letters[0]);
					}
				}
				else {
					letters[1] = findNextLetter(letters[1]);
				}
			}
			else {
				letters[2] = findNextLetter(letters[2]);
			}
		}
		else {
			numbers++;
		}
		lastNumber = "";
		lastNumber += letters[0];
		if (numbers < 10) {
			lastNumber += "00";
			if (numbers < 100) {
				lastNumber += "0";
			}
		}
		lastNumber += numbers;
		lastNumber += letters[1];
		lastNumber += letters[2];
	}
	char findNextLetter(char currentLeter) {
		for (int i = 0; i < 11; i++) {
			if (LETTERS[i] == currentLeter) {
				return LETTERS[i + 1];
			}
		}
	}

};

class Parking {
private:
	string name;
	int capacity;
	int size = 0;
	float price;
	Car* cars = new Car[0];

public:
	Parking(string name, int capacity, float price) {
		this->name = name;
		this->capacity = capacity;
		this->price = price;
	}
	void setName(string name) {
		this->name = name;
	}
	string getName() {
		return name;
	}
	void setPrice(float price) {
		this->price = price;
	}
	float getPrice() {
		return price;
	}
	int getSize() {
		return size;
	}
private:
	//void addCar(Car car) {
	//	if (size >= capacity) {
	//		cout << "No places left\n";
	//		return;
	//	}
	//	bool flag = 0;
	//	for (int i = 0; i < size;) {
	//		if (car.getNumber == cars[i].getNumber) {
	//			flag = 1;
	//			break;
	//		}
	//	}
	//	if (flag) {
	//		cout << "That car is already here\n";
	//		return;
	//	}
	//	Car* buf = new Car[size + 1];
	//	for (int i = 0; i < size;) {
	//		buf[i] = cars[i];
	//	}
	//	buf[size] = car;
	//	delete[] cars;
	//	cars = buf;
	//}
};







string Car::lastNumber = "A000AA";

int main()
{
	srand(time(NULL));
	//Student st1("Oleg", 20);
	//st1.showInfo();
	Car car1("mashina", "white");

	//Car cars[100];
	//for (int i = 0; i < 100; i++) {
	//	cars[i] = Car(MODELS[random(0, 4)], COLORS[random(0, 4)]);
	//}
	//for (int i = 0; i < 100; i++) {
	//	cars[i].carInfo();
	//}
	//cars[99].setColor("grey");
	//cars[99].carInfo();
	Parking park1("qwerty", 10, 1.5);
	cout << park1.getName();
}