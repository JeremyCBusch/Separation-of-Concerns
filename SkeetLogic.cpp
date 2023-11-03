#include "SkeetLogic.h"
#include "storageElement.h"

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
//   gun.interact(ui.isUp() + ui.isRight(), ui.isDown() + ui.isLeft());
   storage.getGun().getInterface().input(ui);
   BulletStorage *p = nullptr;

   // a pellet can be shot at any time
   if (ui.isSpace())
      p = new Pellet(gun.getAngle());
      // missiles can be shot at level 2 and higher
   else if (ui.isM() && getLevelNumber() > 1)
      p = new Missile(gun.getAngle());
      // bombs can be shot at level 3 and higher
   else if (ui.isB() && getLevelNumber() > 2)
      p = new Bomb(gun.getAngle());

   bullseye = ui.isShift();

   // add something if something has been added
   if (nullptr != p)
      bullets.push_back(p);

   // send movement information to all the bullets. Only the missile cares.
   for (auto bullet : bullets)
      bullet->input(ui.isUp() + ui.isRight(), ui.isDown() + ui.isLeft(), ui.isB());
}

/************************
 * SKEET SPAWN
 * lanuch new birds
 ************************/
void SkeetLogic::spawn()
{
    double size;
    switch (storage.getTime().level())
    {
        // in level 1 spawn big birds occasionally
    case 1:
        size = 30.0;
        // spawns when there is nothing on the screen
        if (random(0, 15) == 1)  //birds.size() == 0 &&
        {
            StorageStandard * tempBird = new StorageStandard(30, 7.0);
            //storage.addPBird(*tempbird);
            storage.add(*tempBird);
        }

        // spawn every 4 seconds
        if (random(0, 4 * 30) == 1)
            storage.add(*new StorageStandard(size, 7.0));
        break;

        // two kinds of birds in level 2
    case 2:
        size = 25.0;
        // spawns when there is nothing on the screen
        if (birds.size() == 0 && random(0, 15) == 1)
            birds.push_back(new Standard(size, 7.0, 12));

        // spawn every 4 seconds
        if (random(0, 4 * 30) == 1)
            birds.push_back(new Standard(size, 5.0, 12));
        // spawn every 3 seconds
        if (random(0, 3 * 30) == 1)
            birds.push_back(new Sinker(size));
        break;

        // three kinds of birds in level 3
    case 3:
        size = 20.0;
        // spawns when there is nothing on the screen
        if (birds.size() == 0 && random(0, 15) == 1)
            birds.push_back(new Standard(size, 5.0, 15));

        // spawn every 4 seconds
        if (random(0, 4 * 30) == 1)
            birds.push_back(new Standard(size, 5.0, 15));
        // spawn every 4 seconds
        if (random(0, 4 * 30) == 1)
            birds.push_back(new Sinker(size, 4.0, 22));
        // spawn every 4 seconds
        if (random(0, 4 * 30) == 1)
            birds.push_back(new Floater(size));
        break;

        // three kinds of birds in level 4
    case 4:
        size = 15.0;
        // spawns when there is nothing on the screen
        if (birds.size() == 0 && random(0, 15) == 1)
            birds.push_back(new Standard(size, 4.0, 18));

        // spawn every 4 seconds
        if (random(0, 4 * 30) == 1)
            birds.push_back(new Standard(size, 4.0, 18));
        // spawn every 4 seconds
        if (random(0, 4 * 30) == 1)
            birds.push_back(new Sinker(size, 3.5, 25));
        // spawn every 4 seconds
        if (random(0, 4 * 30) == 1)
            birds.push_back(new Floater(size, 4.0, 25));
        // spawn every 4 seconds
        if (random(0, 4 * 30) == 1)
            birds.push_back(new Crazy(size));
        break;

    default:
        break;
    }
}