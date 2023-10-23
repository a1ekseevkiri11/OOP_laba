#include <iostream>
#include <random>
#include <cmath>
#include <stdlib.h>
#include <time.h>

using namespace std;



// 1 laba
const double pi = 3.141592653589793;

double randomPosition() {
	return -99 + rand() % (99 + 99 + 1);
}

class Circle {

private:
	double x, y, r;

public:
	//3
	Circle(double r = 0) : r(r) {
		cout << "Input coordinate Circle\nx: ";
		cin >> x;
		cout << "y: ";
		cin >> y;
	}

	double getX() {
		return x;
	}

	double getY() {
		return y;
	}

	double getRadius() {
		return r;
	}

	//1
	double getCircumference() {
		return 2 * pi * r;
	}

	//2
	void randomCoordinate() {
		x = randomPosition();
		y = randomPosition();
	}

};

//4
double getDistanceBetweenCenters(Circle circle1, Circle circle2) {
	return sqrt(pow(circle1.getX() - circle2.getX(), 2) + pow(circle1.getY() - circle2.getY(), 2));
}

//5
static bool touchOnePoint(Circle circle1, Circle circle2) {
	if (circle1.getRadius() + circle2.getRadius() == getDistanceBetweenCenters(circle1, circle2)) {
		return true;
	}
	if (getDistanceBetweenCenters(circle1, circle2) + min(circle1.getRadius(), circle2.getRadius()) == max(circle1.getRadius(), circle2.getRadius())) {
		return true;
	}
	return false;
}

//2 laba

//1
class Horse {
private:
	string nickname;
public:
	Horse(string nickname = "Undefined") : nickname(nickname) {}

	string getNickname() {
		return nickname;
	}
};

class Pegas : public Horse {
public:
	Pegas(string nickname) : Horse(nickname) {}
	void flight() {
		cout << "flight pegas: " << getNickname();
	}
};

//2, 4
//class Pet {
//private:
//	int weight, age;
//	char sex;
//public:
//	Pet(int weight, char sex, int age) : weight(weight), age(age), sex(sex) {}
//
//	int getWeight() {
//		return weight;
//	}
//
//	int getAge() {
//		return age;
//	}
//
//	char getSex() {
//		return sex;
//	}
//};


//class Cat : public Pet {
//private:
//	string name;
//public:
//	Cat(int weight, char sex, int age, string name) : Pet(weight, sex, age), name(name) {}
//
//	string getName() {
//		return name;
//	}
//
//	void getInfo() {
//		cout << "cat" << " " << getName() << " " << getAge() << " " << getSex() << " " << getWeight();
//	}
//};
//
//class Dog : public Pet {
//private:
//	string name;
//public:
//	Dog(int weight, char sex, int age, string name) : Pet(weight, sex, age), name(name) {}
//
//	string getName() {
//		return name;
//	}
//
//	void getInfo() {
//		cout << "dog" << " " << getName() << " " << getAge() << " " << getSex() << " " << getWeight();
//	}
//};


//3
class Fish {
private:
	string name;
public:
	Fish(string name) : name(name) {}

	string getName() {
		return name;
	}

	void swim() {
		cout << getName() << " swim";
	}
};

class Animal : public Fish {
private:
	int countLeg;
public:
	Animal(string name, int countLeg) : Fish(name), countLeg(countLeg) {}

	int getCountLeg() {
		return countLeg;
	}

	void walk() {
		cout << getName() << " walk";
	}
};

class Ape : public Animal {
private:

public:
	Ape(string name, int countLeg) : Animal(name, countLeg) {}

	void climbTree() {
		cout << getName() << " climb tree";
	}
};

class Human : public Ape {
private:
	bool bipedalism;
public:
	Human(string name, int countLeg, bool bipedalism) : Ape(name, countLeg), bipedalism(bipedalism){}

	bool getBipedalism() {
		return bipedalism;
	}

	void say() {
		cout << getName() << " say";
	}
};


//3 laba
//полиморфизм
//1, 2
class Cow {
private:
	string name;
public:
	Cow(string name) : name(name) {}

	string getName() {
		return name;
	}

	virtual void sayMyName() {
		cout << "I'm cow - " << name << "\n";
	}
};

class Whale : public Cow {
public:
	Whale(string name) : Cow(name) {}

	virtual void sayMyName() {
		cout << "I'm not a cow, I'm a whale - " << getName() << "\n";
	}
};


//3
class Bird {
};

class Lamp {
};

class Definition {
public:
	static void itIs(Bird _) {
		cout << "Bird";
	}
	static void itIs(Lamp _) {
		cout << "Lamp";
	}
	/*static void itIs(Cat _) {
		cout << "Cat";
	}
	static void itIs(Dog _) {
		cout << "Dog";
	}*/
};

//4
class Cat {
private:
	string name;
public:
	Cat(string name) : name(name) {}
	
	string getName() {
		return name;
	}

	Cat getChild(string name) {
		return Cat(name);
	}

	virtual void Voice() {
		cout << "Miay\n";
	}
};

//class Dog : public Cat {
//public:
//	Dog(string name) : Cat(name) {}
//
//	Dog getChild(string name) {
//		return Dog(name);
//	}
//
//	virtual void Voice() {
//		cout << "Gav\n";
//	}
//};

//перегрузка

class Overload {
public:
	static void print(int a) {
		cout << "int: " << a;
	}

	static void print(string a) {
		cout << "string: " << a;
	}

	static void print(char a) {
		cout << "char: " << a;
	}

	static void print(float a) {
		cout << "float: " << a;
	}

	static void print(bool a) {
		cout << "bool: " << a;
	}

	static int min(int a, int b) {
		return a < b ? a : b;
	}

	static long min(long a, long b) {
		return a < b ? a : b;
	}

	static double min(double a, double b) {
		return a < b ? a : b;
	}

	static int max(int a, int b) {
		return a > b ? a : b;
	}

	static long max(long a, long b) {
		return a > b ? a : b;
	}

	static double max(double a, double b) {
		return a > b ? a : b;
	}
};

//4 laba

class Pet {
protected:
	string name;
	int age;
	bool hungry;
public:
	virtual void voice() = 0;

	void setName(string name) {
		this->name = name;
	}

	string getName() {
		return name;
	}

	void setAge(int age) {
		this->age = age;
	}

	int getAge() {
		return age;
	}

	void setAge(bool hungry) {
		this->hungry = hungry;
	}

	bool getHungry() {
		return hungry;
	}
};

class Snake : public Pet {
public:
	Snake(string name, int age, bool hungry) {
		setName(name);
		setAge(age);
		setAge(hungry);
	}

	virtual void voice() {
		cout << "Shhhhh" << "\n";
	}
};

class Dog : public Pet {
public:
	Dog(string name, int age, bool hungry) {
		setName(name);
		setAge(age);
		setAge(hungry);
	}

	virtual void voice() {
		cout << "Gav gav!" << "\n";
	}
};

class PatrolDog : public Pet{
public:
	PatrolDog(string name, int age, bool hungry) {
		setName(name);
		setAge(age);
		setAge(hungry);
	}

	virtual void voice() {
		cout << "GAV GAV!" << "\n";
	}
};

class Cat : public Pet {
public:
	Cat(string name, int age, bool hungry) {
		setName(name);
		setAge(age);
		setAge(hungry);
	}

	virtual void voice() {
		cout << "Mey" << "\n";
	}
};

class Fish : public Pet {
public:
	Fish(string name, int age, bool hungry) {
		setName(name);
		setAge(age);
		setAge(hungry);
	}

	virtual void voice() {
		cout << "Fish can say?" << "\n";
	}
};



//class Truck {
//
//};
//
//class Sedan {
//
//};
//
//class Pickup {
//
//};

int main() {
	cout << Overload::max(1, 10);
}