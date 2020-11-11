#pragma once
#ifndef __AIRPLANE_H__
#define __AIRPLANE_H__
#include <iostream>

namespace avdance {
	class AirPlane {
	public:
		AirPlane();
		AirPlane(int w,int wh);
		~AirPlane();

	public:
		virtual void setWings(int w);
		virtual int getWings();

		void setWheels(int w);
		int getWheels();

		virtual void fly();

	private:
		int wings;
		int wheels;
	};
}


#endif // !__AIRPLANE_H__
