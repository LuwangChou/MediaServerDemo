#include <iostream>
#include "FighterPlane.h"
namespace avdance {
//�����д����ĳ�Ա����
/*
�����ĸ���

   ���Ƿ�����������

��1�� ����������麯����ʹ��virtual �ؼ���������������

��2���������ǵ����������ֱ�λ��������ͻ���

��3���������Ͳ����б������ȫ��ͬ


����������

    ���ط�����������

��1������͸���ĺ�������ͬ�������б���Բ�һ��
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