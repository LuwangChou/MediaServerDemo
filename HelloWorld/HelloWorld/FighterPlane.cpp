#include <iostream>
#include "FighterPlane.h"
namespace avdance {
//如何重写父类的成员函数
/*
函数的覆盖

   覆盖发生的条件：

（1） 基类必须是虚函数（使用virtual 关键字来进行声明）

（2）发生覆盖的两个函数分别位于派生类和基类

（3）函数名和参数列表必须完全相同


函数的隐藏

    隐藏发生的条件：

（1）子类和父类的函数名相同，参数列表可以不一样
*/
	void FighterPlane::setWings(int w) {
		wings = w + 1000;
	}
	int FighterPlane::getWings() {
		return wings;
	}

	void FighterPlane::setWheels(int w) {
		wheels = w + 1000;

	}
	int FighterPlane::getWheels() {
		return wheels;
	}
	void FighterPlane::setWeapons(int ws) {
		weapons = ws;
	}
	
	int FighterPlane::getWeapons() {
		return weapons;
	}

	void FighterPlane::fly() {
		std::cout << "FighterPlane .... fly..." << std::endl;
	}
}