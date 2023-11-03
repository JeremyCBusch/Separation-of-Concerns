#pragma once

#include "position.h";
#include "logicElement.h";
#include "interfaceElement.h"
#include <cassert>
#include <list>

class StorageElement
{
protected:
	static Position dimensions;
	Position* pt;
	Velocity* v;
	double radius;
	double speed;
	int points;
	bool isDead;
	LogicElement* pLogic;
	InterfaceElement* pInterface;

public:
	Position * getPosition() { return pt; }
	Velocity* getVelocity() { return v; }
	double getRadius() { return radius; }
	int getPoints() { return points; }
	bool getIsDead() { return isDead; }
	LogicElement* getLogicElement() { return pLogic; }
	InterfaceElement* getInterfaceElement() { return pInterface; }
	Position getDimensions() { return dimensions; }
	double getSpeed() { return speed; }

	void setSpeed(double speed) { this->speed = speed; }
	void setPosition(Position * pt) { this->pt = pt; }
	void setVelocity(Velocity* v) { this->v = v; }
	void setRadius(double radius) { this->radius = radius; }
	void setPoints(int points) { this->points = points; }
	void setisDead(bool isDead) { this->isDead = isDead; }
	void setLogicElement(LogicElement* pLogic) { this->pLogic = pLogic; }
	void setInterfaceElement(InterfaceElement* pInterface) { this->pInterface = pInterface; }
};


class StorageStandard : public StorageElement {
public:
	StorageStandard(double radius = 25.0, double speed = 5.0, int points = 10)
	{
		this->radius = radius;
		this->speed = speed;
		this->points = points;
	}
private: 
	InterfaceStandard interface;
};




class StorageFloater : public StorageElement {
public:
	StorageFloater(double radius = 30.0, double speed = 5.0, int points = 15)
	{
		this->radius = radius;
		this->speed = speed;
		this->points = points;
	}
private:
	InterfaceFloater interface;
};




class StorageSinker : public StorageElement {
public:
	StorageSinker(double radius = 30.0, double speed = 5.0, int points = 15)
	{
		this->radius = radius;
		this->speed = speed;
		this->points = points;
	}
private:
	InterfaceSinker interface;
};



class StorageCrazy : public StorageElement {
public:
	StorageCrazy(double radius = 30.0, double speed = 5.0, int points = 15)
	{
		this->radius = radius;
		this->speed = speed;
		this->points = points;
	}
private:
	InterfaceCrazy interface;
};





class StorageBullet : public StorageElement
{
protected:
	double angle;
	double speed;
	double radius;
	int value;
	int timeToDie;

public:
	StorageBullet(double angle = 0.0, double speed = 30.0, double radius = 5.0, int value = 1);

	int getTimeToDie() { return timeToDie; }
	void setTimeToDie(int newTimeToDie) { this->timeToDie = newTimeToDie; }
};

class StorageEffect : public StorageElement
{
protected:
	Position* ptEnd;  // location of the effect
	double age;    // 1.0 = new, 0.0 = dead
	int timeToDie;
	int size;
	
public:
	StorageEffect() {};
	StorageEffect(Position* pt) 
	{
		this->ptEnd = pt;
		this->age = 5.0;
	}
	int getTimeToDie() { return timeToDie; }
	void setTimeToDie(int newTimeToDie) { this->timeToDie = newTimeToDie; }
	double getAge() { return age; }
	double setAge(int newAge) { age = newAge; }
	double getSize() { return size; }
	double setSize(int newSize) { size = newSize; }
};

class StorageExhaust : public StorageEffect
{
private:
	InterfaceExhaust interface;
public:
	StorageExhaust(Position* pt, Velocity* v);
	InterfaceExhaust getInterface() { return interface; }
};

class StorageFragment : public StorageEffect
{
private:
	InterfaceFragment interface;
public:
	InterfaceFragment getInterface() { return interface; }
};


class StorageStreek : public StorageEffect
{
private:
	InterfaceStreek interface;
public:
	StorageStreek(Position* pt, Velocity* v);
	InterfaceStreek getInterface() { return interface; }
};


class StorageShrapnel : public StorageBullet
{
private:
	InterfaceShrapnel interface;
public:
	StorageShrapnel(StorageBullet* bomb);

	InterfaceShrapnel getInterface() { return interface; }
};

/******************************************************************
 * RANDOM
 * This function generates a random number.
 ****************************************************************/
int random(int min, int max)
{
   assert(min < max);
   int num = (rand() % (max - min)) + min;
   assert(min <= num && num <= max);
   return num;
}
double random(double min, double max)
{
   assert(min <= max);
   double num = min + ((double)rand() / (double)RAND_MAX * (max - min));
   assert(min <= num && num <= max);
   return num;
}