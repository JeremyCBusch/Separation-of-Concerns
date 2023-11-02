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
   storage->getPosition() += storage->getVelocity();

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

void LogicStandard::advance(StorageElement* storage)
{
    // small amount of drag
    //    v *= 0.995;
    storage.setVelocity(*(storage.getVelocity()) * 0.995)

    // inertia   
    //    pt.add(v);
   storage.setPosition(*(storage.getVelocity()))

   // out of bounds checker
   if (isOutOfBounds(storage))
   {
      storage->setisDead(true);
      points *= -1; // points go negative when it is missed!
   }
}

void LogicSinker::advance(StorageElement* storage)
{
   // gravity
   v.addDy(-0.07);

   // inertia
   pt.add(v);

   // out of bounds checker
   if (isOutOfBounds(storage))
   {
      storage->setisDead(true);
      points *= -1; // points go negative when it is missed!
   }
}

void LogicFloater::advance(StorageElement* storage)
{
   // large amount of drag
   v *= 0.990;

   // inertia
   pt.add(v);

   // anti-gravity
   v.addDy(0.05);

   // out of bounds checker
   if (isOutOfBounds(storage))
   {
      storage->setisDead(true);
      points *= -1; // points go negative when it is missed!
   }
}

void LogicCrazy::advance(StorageElement* storage)
{

   // inertia
   pt.add(v);

   // out of bounds checker
   if (isOutOfBounds(storage))
   {
      storage->setisDead(true);
      points *= -1; // points go negative when it is missed!
   }
}

void LogicCrazy::turn()
{
   // erratic turns eery half a second or so
   if (randomInt(0, 15) == 0)
   {
      v.addDy(randomFloat(-1.5, 1.5));
      v.addDx(randomFloat(-1.5, 1.5));
   }
}

void LogicBomb::death(std::list<StorageBullet*>& bullets)
{
   for (int i = 0; i < 20; i++)
      bullets.push_back(new StorageShrapnel(*this));   //TODO: we don't have shrapenel storage
}
