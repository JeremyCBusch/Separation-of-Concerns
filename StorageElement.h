#pragma once
#include <cassert>
#include <list>
#include "position.h"

// Forward declarations
class LogicElement;
class InterfaceElement;
class Velocity;

class StorageElement
{
protected:
   static Position dimensions;
   Position pt;
   Velocity v;
   double radius;
   int points;
   bool dead;
   LogicElement * pLogic;
   InterfaceElement * pInterface;

public:
   enum Type { BULLET, BIRD, EFFECT };

   Position * getPosition() { return &pt; }
   Velocity * getVelocity() { return &v; }
   double getRadius() { return radius; }
   int getPoints() { return points; }
   bool isDead() const { return dead; }
   LogicElement * getLogicElement() { return pLogic; }
   InterfaceElement * getInterface() { return pInterface; }
   Position getDimensions() { return dimensions; }

   void setPosition(Position pt) { this->pt = pt; }
   void setVelocity(Velocity v) { this->v = v; }
   void setRadius(double radius) { this->radius = radius; }
   void setPoints(int points) { this->points = points; }
   void setDead(bool isDead) { this->dead = isDead; }
   void setLogicElement(LogicElement* pLogic) { this->pLogic = pLogic; }
   void setInterfaceElement(InterfaceElement* pInterface) { this->pInterface = pInterface; }
};

class StorageBird : public StorageElement
{
public:
   StorageBird(double radius = 25.0, double speed = 5.0, int points = 10);
   void draw();
   void advance();
};

class StorageBullet : public StorageElement
{
public:
   StorageBullet(double angle = 0.0, double speed = 30.0, double radius = 5.0, int value = 1);
   void draw();
   void advance();
};

class StorageEffect : public StorageElement
{
protected:
   double age;    // 1.0 = new, 0.0 = dead
   double size;   // 1.0 = full size, 0.0 = dead
   Position ptEnd;

public:
   StorageEffect(Position pt)
   {
      this->ptEnd = pt;
      this->age = 5.0;
   }
   double getAge() { return age; }
   void setAge(int newAge) { age = newAge; }
   double getSize() { return size; }
   void setSize(int newSize) { size = newSize; }
};

//class StorageExhaust : public StorageEffect
//{
//public:
//   StorageExhaust(Position* pt, Velocity* v);
//};
//
//class StorageFragment : public StorageEffect
//{
//public:
//   StorageFragment(Position * pt, Velocity * v);
//};
//
//
//class StorageStreek : public StorageEffect
//{
//public:
//   StorageStreek(Position* pt, Velocity* v);
//};
//
//
//class StorageShrapnel : public StorageBullet
//{
//public:
//   StorageShrapnel(StorageBullet* bomb);
//};

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