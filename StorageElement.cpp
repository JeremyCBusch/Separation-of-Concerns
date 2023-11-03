#include "StorageElement.h"

StorageBird::StorageBird(double radius, double speed, int points) {
   this->type = BIRD;
}

StorageBullet::StorageBullet(double angle, double speed, double radius, int value)
{
   this->type = BULLET;
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
