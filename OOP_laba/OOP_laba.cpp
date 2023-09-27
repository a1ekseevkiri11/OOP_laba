#include <iostream>
#include <random>
#include <cmath>
#include <stdlib.h>
#include <time.h>

using namespace std;

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
	if (getDistanceBetweenCenters(circle1, circle2) + min(circle1.getRadius(), circle2.getRadius()) == max(circle1.getRadius(), circle2.getRadius())){
		return true;
	}
	return false;
}

int main() {
	srand(time(NULL));
	Circle circle1(1);
	Circle circle2(2);
}