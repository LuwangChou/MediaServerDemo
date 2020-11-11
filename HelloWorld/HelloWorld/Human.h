#pragma once

#include <iostream>
namespace Human {
	class Human {
	public:

		Human() {
			std::cout << "construct human ..." << std::endl;
			age = 0;
			sex = 0;
		}

		Human(int a, int s) {
			std::cout << "construct human ..." << std::endl;
			age = a;
			sex = s;
		}
		~Human()
		{
			std::cout << "deconstruct human ..." << std::endl;

		}
	public:
		void setAge(int a);
		int getAge();

		void setSex(int s);
		int getSex();


	private:
		int age;
		int sex;

	};
}