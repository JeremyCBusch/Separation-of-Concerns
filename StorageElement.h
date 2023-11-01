#pragma once

#include "position.h";
#include "LogicElement.h";
#include "InterfaceElement.h"

class StorageElement
{
private:
	Position* pt;
	Velocity* v;
	double radius;
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

