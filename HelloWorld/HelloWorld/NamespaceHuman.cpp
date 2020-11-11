#include <iostream>

#include "NamespaceHuman.h"

namespace NamespaceHuman {
	void Human::setAge(int a) {
		age = a;
	}
	int Human::getAge() {
		return age;
	}

	void Human::setSex(int s) {
		sex = s;
	}

	int Human::getSex() {
		return sex;
	}
}