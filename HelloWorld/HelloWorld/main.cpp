#include <iostream>
#include "Human.h"
#include "NamespaceHuman.h"
#include "FighterPlane.h"
#include "AirPlane.h"
#include "NonePlane.h"
using namespace avdance;
int main(int argc, char* argv[]) {
	std::cout << "hello world" << std::endl;


	NamespaceHuman::Human* human = new NamespaceHuman::Human(100,1);
	std::cout << "human age" << human->getAge() << std::endl;
	std::cout << "human sex" << human->getSex() << std::endl;



	avdance::FighterPlane fp;
	fp.setWings(15);
	fp.setWheels(3);
	fp.setWeapons(1000);

	std::cout << "FighterPlane :" << fp.getWings() << ","
		<< fp.getWheels() << ","
		<< fp.getWeapons() << std::endl;



	avdance::FighterPlane fp2;
	avdance::AirPlane* pAp = &fp2;
	avdance::FighterPlane* pFp = &fp2;

	pAp->setWings(13);
	pFp->setWings(19);
	std::cout << "AirPlane :getWings" << pAp->getWings() << std::endl;
	std::cout << "FighterPlane :getWings" << pFp->getWings() << std::endl;

	pAp->setWheels(2222);
	pFp->setWheels(4444);
	std::cout << "AirPlane :getWheels" << pAp->getWheels() << std::endl;
	std::cout << "FighterPlane :getWheels" << pFp->getWheels() << std::endl;

	/*
	���
	FighterPlane :1000,1001,1000
	AirPlane :getWings  1019  //���� ���ҵ�������ĳ�Ա����
	FighterPlane :getWings 1019 // ֱ�ӵ���
	AirPlane :getWheels 2222  // ֱ�ӵ��ã� ���ø���ĳ�Ա����
	FighterPlane :getWheels 5444  // ���� �� ������ø���ĳ�Ա����

	�ܽ᣺ �����Ա�������� virtual ���ӳ�Ա�������������ϵ �������߶������ڣ�
	���� ������Ը��Ǹ��࣬��������Ҳ���Ե��������Ա������ʵ�ֶ�̬
	*/



	AirPlane* airplane = nullptr;

	airplane = new AirPlane();
	airplane->fly();
	airplane = new FighterPlane();
	airplane->fly();

	airplane = new NonePlane();
	airplane->fly();


	return 0;
}