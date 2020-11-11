#include <iostream>
#include "AirPlane.h"
namespace avdance {
	AirPlane::AirPlane() {
	}
	AirPlane::AirPlane(int w, int wh) {
		wings = w;
		wheels = wh;
	}

	AirPlane::~AirPlane() {}

	void AirPlane::setWings(int w) {
		wings = w;
	}
	int AirPlane::getWings() {
		return wings;
	}

	void AirPlane::setWheels(int wh) {
		wheels = wh;
	}
	int AirPlane::getWheels() {
		return wheels;
	}

	void AirPlane::fly() {
		std::cout << "AirPlane fly" << std::endl;
	}
}
