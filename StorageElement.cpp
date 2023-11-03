#include "StorageElement.h"

StorageShrapnel::StorageShrapnel(StorageBullet* bomb)
{
   // how long will this one live?
   timeToDie = random(5, 15);

   // The speed and direction is random
   v->set(random(0.0, 6.2), random(10.0, 15.0));
   pt = bomb->getPosition();

   points = 0;

   radius = 3.0;
}

StorageExhaust::StorageExhaust(Position* pt, Velocity* v)
{
   ptEnd = pt;

   // age
   age = 0.5;
}




StorageStreek::StorageStreek(Position* pt, Velocity* v)
{
   ptEnd = pt;
   //v *= -1.0;
   //ptEnd += v;

   // age
   age = 0.5;
}

StorageBullet::StorageBullet(double angle, double speed, double radius, int value)
{
   this->isDead = false;
   this->angle = angle;
   this->speed = speed;
   this->radius = radius;
   this->value = value;

   // set the initial position
   pt->setX(dimensions.getX() - 1.0);
   pt->setY(1.0);
   assert(pt->getX() > 100.0);

   // set the initial velocity
   v->setDx(-speed * cos(angle));
   v->setDy(speed * sin(angle));
   assert(v->getDx() <= 0.0);
   assert(v->getDy() >= 0.0);
}
