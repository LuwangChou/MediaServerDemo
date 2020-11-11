#pragma once
#pragma once
#ifndef __NONEPLANE_H__
#define __NONEPLANE_H__
#include <iostream>
#include "AirPlane.h"
namespace avdance {
	class NonePlane : public AirPlane {
	public:
		NonePlane() {
			weapons = 1;
		}
		NonePlane(int w, int wh) {

		}
		~NonePlane() {

		}
	public:
		void setWeapons(int ws);
		int getWeapons();

		virtual void fly();
	private:
		int weapons = 0;
	};
}


#endif // !__NONEPLANE_H__
