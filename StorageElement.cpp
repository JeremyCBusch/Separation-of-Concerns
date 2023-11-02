#include "storageElement.h"

StorageShrapnel::StorageShrapnel(StorageBullet & bomb)
{
   // how long will this one live?
   timeToDie = random(5, 15);

   // The speed and direction is random
   v->set(random(0.0, 6.2), random(10.0, 15.0));
   pt = bomb.getPosition();

   points = 0;

   radius = 3.0;
}

StorageExhaust::StorageExhaust(Position* pt, Velocity* v)
{
   ptEnd = pt;

   // age
   age = 0.5;
}




StorageStreek::StorageStreek(Position& pt, Velocity v)
{
   ptEnd = pt;
   v *= -1.0;
   ptEnd += v;

   // age
   age = 0.5;
}

StorageBullet::StorageBullet(double angle = 0.0, double speed = 30.0, double radius = 5.0, int value = 1)
{
   this->angle = angle;
   this->speed = speed;
   this->radius = radius;
   this->value = value;
}
