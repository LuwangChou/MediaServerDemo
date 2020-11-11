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
	输出
	FighterPlane :1000,1001,1000
	AirPlane :getWings  1019  //覆盖 ，找到了子类的成员函数
	FighterPlane :getWings 1019 // 直接调用
	AirPlane :getWheels 2222  // 直接调用， 调用父类的成员函数
	FighterPlane :getWheels 5444  // 隐藏 ， 不会调用父类的成员函数

	总结： 父类成员函数不加 virtual 父子成员函数不会产生联系 ，即两者独立存在；
	加了 子类可以覆盖父类，父类引用也可以调用子类成员函数；实现多态
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