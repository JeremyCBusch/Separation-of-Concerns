#include "SkeetLogic.h"
#include "StorageElement.h"
#include "interfaceElement.h"

/******************************************************************
 * RANDOM
 * This function generates a random number.
 ****************************************************************/
//int random(int min, int max)
//{
//    assert(min < max);
//    int num = (rand() % (max - min)) + min;
//    assert(min <= num && num <= max);
//    return num;
//}
//double random(double min, double max)
//{
//    assert(min <= max);
//    double num = min + ((double)rand() / (double)RAND_MAX * (max - min));
//    assert(min <= num && num <= max);
//    return num;
//}

void SkeetLogic::input(UserInput ui) {
   // reset the game
   if (isGameOver() && ui.isSpace())
   {
      storage.reset();
      return;
   }

   // gather input from the interface
   // gun.interact(ui.isUp() + ui.isRight(), ui.isDown() + ui.isLeft());
   storage.getGun().getInterface().input(ui);
   StorageBullet * p = nullptr;

   // a pellet can be shot at any time
   if (ui.isSpace()) {
      p = new StorageBullet(storage.getGun().getAngle());
      p->setInterfaceElement(new InterfacePellet());
      p->setLogicElement(new LogicPellet());
   }
   else if (ui.isM() && getLevelNumber() > 1) {
      p = new StorageBullet();
      p->setInterfaceElement(new InterfaceMissle());
      p->setLogicElement(new LogicMissile());
   }
   else if (ui.isB() && getLevelNumber() > 2) {
      p = new StorageBullet();
      p->setInterfaceElement(new InterfaceBomb());
      p->setLogicElement(new LogicBomb());
   }

   storage.setBullseye(ui.isShift())

   // add something if something has been added
   if (nullptr != p)
      bullets.push_back(p);

   // send movement information to all the bullets. Only the missile cares.
   for (auto it = beginBullet(); it != endBullet(); it++)
      (*it).getInterface()->input(ui, static_cast<LogicMissile&>(*(*it).getLogicElement()), (*it));
}

/************************
 * SKEET SPAWN
 * lanuch new birds
 ************************/
void SkeetLogic::spawn()
{
    double size;
    switch (getLevelNumber())
    {
        // in level 1 spawn big birds occasionally
    case 1:
         size = 30.0;
         // spawns when there is nothing on the screen
         if (random(0, 15) == 1)  //birds.size() == 0 &&
         {
            StorageBird * bird = new StorageBird(size, 7.0);
            bird->setInterfaceElement(new InterfaceStandard());
            bird->setLogicElement(new LogicStandard());
            storage.add(*bird);
         }

         // spawn every 4 seconds
         if (random(0, 4 * 30) == 1)
         {
            StorageBird * bird = new StorageBird(size, 5.0);
            bird->setInterfaceElement(new InterfaceStandard());
            bird->setLogicElement(new LogicStandard());
            storage.add(*bird);
         }
         break;

        // two kinds of birds in level 2
    case 2:
        size = 25.0;
        // spawns when there is nothing on the screen
        if (!storage.aliveBirds() && random(0, 15) == 1) {
//            birds.push_back(new Standard(size, 7.0, 12));
            StorageBird * bird = new StorageBird(size, 7.0, 12);
            bird->setInterfaceElement(new InterfaceStandard());
            bird->setLogicElement(new LogicStandard());
            storage.add(*bird);
        }

        // spawn every 4 seconds
        if (random(0, 4 * 30) == 1) {
//            birds.push_back(new Standard(size, 7.0, 12));
            StorageBird * bird = new StorageBird(size, 7.0, 12);
            bird->setInterfaceElement(new InterfaceStandard());
            bird->setLogicElement(new LogicStandard());
            storage.add(*bird);
        }
        // spawn every 3 seconds
        if (random(0, 3 * 30) == 1) {
//            birds.push_back(new Sinker(size));
            StorageBird * bird = new StorageBird(size);
            bird->setInterfaceElement(new InterfaceSinker());
            bird->setLogicElement(new LogicSinker());
            storage.add(*bird);
        }
        break;

        // three kinds of birds in level 3
    case 3:
        size = 20.0;
        // spawns when there is nothing on the screen
        if (!storage.aliveBirds() && random(0, 15) == 1) {
//            birds.push_back(new Standard(size, 5.0, 15));
            StorageBird * bird = new StorageBird(size, 5.0, 15);
            bird->setInterfaceElement(new InterfaceStandard());
            bird->setLogicElement(new LogicStandard());
            storage.add(*bird);
        }

        // spawn every 4 seconds
        if (random(0, 4 * 30) == 1) {
//            birds.push_back(new Standard(size, 5.0, 15));
            StorageBird * bird = new StorageBird(size, 5.0, 15);
            bird->setInterfaceElement(new InterfaceStandard());
            bird->setLogicElement(new LogicStandard());
            storage.add(*bird);
        }
        // spawn every 4 seconds
        if (random(0, 4 * 30) == 1) {
//            birds.push_back(new Sinker(size, 4.0, 22));
            StorageBird * bird = new StorageBird(size, 4.0, 22);
            bird->setInterfaceElement(new InterfaceSinker());
            bird->setLogicElement(new LogicSinker());
            storage.add(*bird);
        }
        // spawn every 4 seconds
        if (random(0, 4 * 30) == 1) {
//            birds.push_back(new Floater(size));
            StorageBird * bird = new StorageBird(size);
            bird->setInterfaceElement(new InterfaceFloater());
            bird->setLogicElement(new LogicFloater());
            storage.add(*bird);
        }
        break;

        // three kinds of birds in level 4
    case 4:
        size = 15.0;
        // spawns when there is nothing on the screen
        if (!storage.aliveBirds() && random(0, 15) == 1) {
//            birds.push_back(new Standard(size, 4.0, 18));
            StorageBird * bird = new StorageBird(size, 4.0, 18);
            bird->setInterfaceElement(new InterfaceStandard());
            bird->setLogicElement(new LogicStandard());
            storage.add(*bird);
        }

        // spawn every 4 seconds
        if (random(0, 4 * 30) == 1) {
//            birds.push_back(new Standard(size, 4.0, 18));
            StorageBird * bird = new StorageBird(size, 4.0, 18);
            bird->setInterfaceElement(new InterfaceStandard());
            bird->setLogicElement(new LogicStandard());
            storage.add(*bird);
        }
        // spawn every 4 seconds
        if (random(0, 4 * 30) == 1) {
//            birds.push_back(new Sinker(size, 3.5, 25));
            StorageBird * bird = new StorageBird(size, 3.5, 25);
            bird->setInterfaceElement(new InterfaceSinker());
            bird->setLogicElement(new LogicSinker());
            storage.add(*bird);
        }
        // spawn every 4 seconds
        if (random(0, 4 * 30) == 1) {
//            birds.push_back(new Floater(size, 4.0, 25));
            StorageBird * bird = new StorageBird(size, 4.0, 25);
            bird->setInterfaceElement(new InterfaceFloater());
            bird->setLogicElement(new LogicFloater());
            storage.add(*bird);
        }
        // spawn every 4 seconds
        if (random(0, 4 * 30) == 1) {
//            birds.push_back(new Crazy(size));
            StorageBird * bird = new StorageBird(size);
            bird->setInterfaceElement(new InterfaceCrazy());
            bird->setLogicElement(new LogicCrazy());
            storage.add(*bird);
        }
        break;

    default:
        break;
    }
}

void SkeetLogic::advance() {
   storage.getTime().setTime(storage.getTime() + 1);

   // if status, then do not move the game
   if (isStatus())
   {
      // get rid of the bullets and the birds without changing the score
      storage.clearElements();
      return;
   }

   // spawn
   spawn();

   // move the birds and the bullets
   for (auto it = begin(); it != end(); it++)
   {
      it->getLogicElement()->advance(it, &storage.add);
   }
//   for (auto & pts : points)
//      pts.update();

   // hit detection
   for (auto bird = beginBird(); bird != endBird(); bird++)
      for (auto bullet = beginBullet(); bullet != endBullet(); bullet++)
         if (!(*bird).isDead() && !(*bullet).isDead() &&
               (*bird).getRadius() + (*bullet).getRadius() >
             minimumDistance(*(*bird).getPosition(), *(*bird).getVelocity(),
                             *(*bullet).getPosition(),  *(*bullet).getVelocity()))
         {
            for (int i = 0; i < 25; i++) {
               StorageEffect * effect = new StorageEffect(*(*bird).getPosition());
               effect->setInterfaceElement(new InterfaceFragment());
               effect->setLogicElement(new LogicFragment());
               storage.add(*effect);
            }
            (*bird).setDead(true);
            (*bullet).setDead(true);
            storage.incrementNumKilled();
            (*bullet).setPoints(-((*bird).getPoints()));
            (*bird).setPoints(0);
         }

   // remove the zombie birds
   for (auto it = beginBird(); it != endBird())
      if ((*it).isDead())
      {
         if ((*it).getPoints()) {
            // TODO: add points
//            points.push_back(Points((*it)->getPosition(), (*it)->getPoints()));
         }
         storage.addPoints((*it).getPoints());
//         score.adjust((*it)->getPoints());
         it = birds.erase(it);
      }
      else
         ++it;

   // remove zombie bullets
   for (auto it = bullets.begin(); it != bullets.end(); )
      if ((*it)->isDead())
      {
         (*it)->death(bullets);
         int value = -(*it)->getValue();
         points.push_back(Points((*it)->getPosition(), value));
         score.adjust(value);
         it = bullets.erase(it);
      }
      else
         ++it;

   // remove zombie fragments
   for (auto it = effects.begin(); it != effects.end();)
      if ((*it)->isDead())
         it = effects.erase(it);
      else
         ++it;

   // remove expired points
   for (auto it = points.begin(); it != points.end();)
      if ((*it).isDead())
         it = points.erase(it);
      else
         ++it;
}