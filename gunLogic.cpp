#include "gunLogic.h"

void GunLogic::input(int clockwise, int counterClockwise)
{
   // move it
   if (clockwise > 0)
   {
      storage.setAngle(storage.getAngle() + ((clockwise > 10) ? 0.06 : 0.025));
      if (storage.getAngle() > M_PI_2)
         storage.setAngle(M_PI_2);
   }
   if (counterClockwise > 0)
   {
      storage.setAngle(storage.getAngle() - ((counterClockwise > 10) ? 0.06 : 0.025));
      if (storage.getAngle() < 0.0)
         storage.setAngle(0.0);
   }
}
