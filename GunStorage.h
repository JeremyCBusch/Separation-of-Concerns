#pragma once
#include "position.h"
#include "gunInterface.h"
#include "gunLogic.h"

class GunStorage
{
public: 
   GunStorage(const Position& pt) : interface(), logic(), angle(.78), pt(pt) {};

   double getAngle() { return angle; }
   void setAngle(double newAngle) { angle = newAngle; }
   Position getPosition() { return pt; }
   void setPosition(Position newPt) { pt = newPt; }

private:
   double angle;
   Position pt;
   GunInterface interface;
   GunLogic logic;
};

