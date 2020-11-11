#pragma once
#ifndef __FIGHTERPLANE_H__
#define __FIGHTERPLANE_H__
#include <iostream>
#include "AirPlane.h"
namespace avdance {
	class FighterPlane : public AirPlane{
	public:
		FighterPlane() {
			weapons = 1;
		}
		FighterPlane(int w, int wh) {
			
		}
		~FighterPlane() {
			
		}
	public:
		void setWings(int w);
		int getWings();

		void setWheels(int w);
		int getWheels();
	public:
		void setWeapons(int ws);
		int getWeapons();

		virtual void fly();
	private:
		int weapons = 0;
		int wheels = 1;
		int wings = 0;
	};
}


#endif // !__FIGHTERPLANE_H__
