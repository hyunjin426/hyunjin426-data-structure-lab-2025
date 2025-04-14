#include "complex.h"
#include "SportsCar.h"

int main()
{
	Car myCar;
	Car momsCar(10, "K5", 2);
	SportsCar mySeondCar;

	myCar.whereAmI();
	momsCar.whereAmI();
	myCar.changeGear(3);
	momsCar.speedUp();
	momsCar.display();

	mySeondCar.setTurbo(true);
}