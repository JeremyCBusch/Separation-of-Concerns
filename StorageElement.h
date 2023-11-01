#pragma once

#include "position.h";
#include "logicElement.h";
#include "interfaceElement.h"

class StorageElement
{
protected:
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

	void setPosition(Position * pt) { this->pt = pt; }
	void setVelocity(Velocity* v) { this->v = v; }
	void setRadius(double radius) { this->radius = radius; }
	void setPoints(int points) { this->points = points; }
	void setisDead(bool isDead) { this->isDead = isDead; }
	void setLogicElement(LogicElement* pLogic) { this->pLogic = pLogic; }
	void setInterfaceElement(InterfaceElement* pInterface) { this->pInterface = pInterface; }
};

class StorageBird : public StorageElement
{
private:
	double speed;
public:
	
	StorageBird(double radius = 25.0, double speed = 5.0, int points = 10)
	{
		this->radius = radius;
		this->speed = speed;
		this->points = points;
	}

	double getSpeed() { return speed; }
	void setSpeed(double speed) { this->speed = speed; }
};

class StorageBullet : public StorageElement
{
private:
	double angle;
	double speed;
	double radius;
	int value;
public:
	StorageBullet(double angle = 0.0, double speed = 30.0, double radius = 5.0, int value = 1)
	{
		this->angle = angle;
		this->speed = speed;
		this->radius = radius;
		this->value = value;
	}
};

class StorageEffect : public StorageElement
{
private:
	Position* pt;  // location of the effect
	double age;    // 1.0 = new, 0.0 = dead

public:
	StorageEffect(Position* pt) 
	{
		this->pt = pt;
		this->age = 5.0;
	}
};