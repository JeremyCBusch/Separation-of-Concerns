#pragma once
#include "position.h"
#include "gunInterface.h"
#include "gunLogic.h"

class GunStorage
{
public: 
   GunStorage(const Position& pt) : angle(.78), pt(pt) {};

   double getAngle() const { return angle; }
   void setAngle(double newAngle) { angle = newAngle; }
   Position getPosition() const { return pt; }
   void setPosition(const Position& newPt) { pt = newPt; }

private:
   double angle;
   Position pt;
};

