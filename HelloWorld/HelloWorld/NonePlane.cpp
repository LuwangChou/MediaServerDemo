#include <iostream>
#include "NonePlane.h"
namespace avdance {
	void NonePlane::setWeapons(int ws) {
		weapons = ws;
	}
	int NonePlane::getWeapons() {
		return weapons;
	}

	void NonePlane::fly() {
		std::cout << "NonePlane ....fly ..." << std::endl;

	}
}
