#include "logicElement.h"
#include "storageElement.h"


void LogicPellet::advance(StorageBullet* storage, std::list<StorageEffect*>& effects)
{
   // inertia
   storage->getPosition()->add(*storage->getVelocity());

   // out of bounds checker
   if (isOutOfBounds(storage))
      storage->setisDead(true);
}

void LogicMissle::advance(StorageBullet* storage, std::list<StorageEffect*>& effects)
{
   // kill if it has been around too long
   effects.push_back(new StorageExhaust(storage->getPosition(), storage->getVelocity()));

   // inertia
   storage->getPosition()->add(*storage->getVelocity());

   // out of bounds checker
   if (isOutOfBounds(storage))
      storage->setisDead(true);
}



void LogicBomb::advance(StorageBullet* storage, std::list<StorageEffect*>& effects)
{
   // kill if it has been around too long
   storage->setTimeToDie(storage->getTimeToDie() - 1);
   if (storage->getTimeToDie() <= 0)
      storage->setisDead(true);

   // inertia
   storage->getPosition()->add(*storage->getVelocity());

   // out of bounds checker
   if (isOutOfBounds(storage))
      storage->setisDead(true);
}

void LogicShrapnel::advance(StorageEffect* storage, std::list<StorageEffect*>& effects)
{
   // kill if it has been around too long
   storage->setTimeToDie(storage->getTimeToDie() - 1);
   if (storage->getTimeToDie() <= 0)
      storage->setisDead(true);

   // add a streek
   effects.push_back(new StorageStreek(storage->getPosition(), storage->getVelocity()));

   // do the usual bullet stuff (like inertia)
   // inertia
   storage->getPosition()->add(*storage->getVelocity());

   // out of bounds checker
   if (isOutOfBounds(storage))
      storage->setisDead(true);
}

void LogicFragment::advance(StorageEffect* storage)
{
   // move it forward with inertia (no gravity)
   storage->getPosition()->add(*storage->getVelocity());

   // increase the age so it fades away
   storage->setAge(storage->getAge() - .02);
   storage->setSize(storage->getSize() * .95);
}

void LogicExhaust::advance(StorageEffect* storage)
{
   // move it forward with inertia (no gravity)
//   pt += v;

   // increase the age so it fades away
   storage->setAge(storage->getAge() - 0.025);
}

void LogicStreek::advance(StorageEffect* storage)
{
   // move it forward with inertia (no gravity)
//    pt += v;

   // increase the age so it fades away
   storage->setAge(storage->getAge() - 0.1);

}

void LogicStandard::advance(StorageStandard* storage)
{
   // small amount of drag
   //    v *= 0.995;
   storage->getVelocity()->setDx(storage->getVelocity()->getDx() * .995);
   storage->getVelocity()->setDy(storage->getVelocity()->getDy() * .995);

   // inertia   
   storage->getPosition()->add(*storage->getVelocity());

   // out of bounds checker
   if (isOutOfBounds(storage))
   {
      storage->setisDead(true);
      storage->setPoints(storage->getPoints() * -1); // points go negative when it is missed!
   }
}

void LogicSinker::advance(StorageElement* storage)
{
   // gravity
   storage->getVelocity()->addDy(-.07);

   // inertia
   storage->getPosition()->add(*storage->getVelocity());

   // out of bounds checker
   if (isOutOfBounds(storage))
   {
      storage->setisDead(true);
      storage->setPoints(storage->getPoints() * -1); // points go negative when it is missed!
   }
}

void LogicFloater::advance(StorageElement* storage)
{
   // large amount of drag
   storage->getVelocity()->setDx(storage->getVelocity()->getDx() * .990);
   storage->getVelocity()->setDy(storage->getVelocity()->getDy() * .990);

   // inertia
   storage->getPosition()->add(*storage->getVelocity());

   // anti-gravity
   storage->getVelocity()->addDy(.05);

   // out of bounds checker
   if (isOutOfBounds(storage))
   {
      storage->setisDead(true);
      storage->setPoints(storage->getPoints() * -1); // points go negative when it is missed!
   }
}

void LogicCrazy::advance(StorageElement* storage)
{

   // inertia
   storage->getPosition()->add(*storage->getVelocity());

   // out of bounds checker
   if (isOutOfBounds(storage))
   {
      storage->setisDead(true);
      storage->setPoints(storage->getPoints() * -1); // points go negative when it is missed!
   }
}

void LogicCrazy::turn(StorageElement* storage)
{
   // erratic turns eery half a second or so
   if (randomInt(0, 15) == 0)
   {
      storage->getVelocity()->addDy(randomFloat(-1.5, 1.5));
      storage->getVelocity()->addDx(randomFloat(-1.5, 1.5));
   }
}

void LogicBomb::death(std::list<StorageBullet*>& bullets, StorageBullet* storage)
{
   for (int i = 0; i < 20; i++)
      bullets.push_back(new StorageShrapnel(storage));
}

int LogicElement::randomInt(int min, int max)
{
   assert(min < max);
   int num = (rand() % (max - min)) + min;
   assert(min <= num && num <= max);
   return num;
}

double LogicElement::randomFloat(double min, double max)
{
   assert(min <= max);
   double num = min + ((double)rand() / (double)RAND_MAX * (max - min));
   assert(min <= num && num <= max);
   return num;
}
